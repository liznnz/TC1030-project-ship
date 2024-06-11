#include "container.h"
#include "heavy.h"
#include "light.h"
#include "liquid.h"
#include "port.h"
#include "refrigerated.h"
#include "ship.h"
#include "simpleship.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
  ifstream inputFile;  // Objeto para leer el archivo de entrada
  ofstream outputFile; // Objeto para escribir en el archivo de salida

  // Verifica si el número de argumentos proporcionados es correcto
  if (argc != 3) {
    cout << "usage: " << argv[0] << " input_file output_file\n";
    return -1; // Termina el programa si el número de argumentos es incorrecto
  }

  // Abre el archivo de entrada
  inputFile.open(argv[1]);
  if (!inputFile.is_open()) {
    cout << argv[0] << ": File \"" << argv[1] << "\" not found\n";
    return -1; // Termina el programa si no se puede abrir el archivo de entrada
  }

  // Abre el archivo de salida
  outputFile.open(argv[2]);

  int C, S, P, N;
  // Lee los primeros cuatro números del archivo de entrada
  inputFile >> C >> S >> P >> N;

  // Vectores para almacenar contenedores, puertos y barcos
  vector<Container *> containers;
  vector<Port *> ports;
  vector<Ship *> ships;

  // Itera sobre el número de eventos N
  for (int i = 0; i < N; ++i) {
    int operation;
    inputFile >> operation; // Lee el tipo de operación

    switch (operation) {
    case 1: { // Crear un contenedor
      int idPort, weight;
      char type;
      inputFile >> idPort >> weight >> type; // Lee los detalles del contenedor

      Container *container = nullptr;
      // Crea el tipo de contenedor basado en el peso y tipo
      if (type == 'R') {
        container = new RefrigeratedContainer(containers.size(), weight);
      } else if (type == 'L') {
        container = new LiquidContainer(containers.size(), weight);
      } else if (type == 'B') {
        if (weight <= 3000) {
          container = new LightContainer(containers.size(), weight);
        } else {
          container = new HeavyContainer(containers.size(), weight);
        }
      }

      containers.push_back(container); // Añade el contenedor al vector
      ports[idPort]->add(
          container); // Añade el contenedor al puerto correspondiente
      break;
    }
    case 2: { // Crear un barco
      int idPort, totalWeight, maxNumberOfAllContainers,
          maxNumberOfHeavyContainers, maxNumberOfRefrigeratedContainers,
          maxNumberOfLiquidContainers;
      double fuelConsumptionPerKM;

      // Lee los detalles del barco
      inputFile >> idPort >> totalWeight >> maxNumberOfAllContainers >>
          maxNumberOfHeavyContainers >> maxNumberOfRefrigeratedContainers >>
          maxNumberOfLiquidContainers >> fuelConsumptionPerKM;

      // Crea un nuevo barco con los detalles leídos
      Ship *ship = new Ship(
          ships.size(), ports[idPort], totalWeight, maxNumberOfAllContainers,
          maxNumberOfHeavyContainers, maxNumberOfRefrigeratedContainers,
          maxNumberOfLiquidContainers, fuelConsumptionPerKM);

      ships.push_back(ship); // Añade el barco al vector de barcos
      ports[idPort]->incomingShip(
          ship); // Añade el barco a la lista de barcos del puerto
      break;
    }
    case 3: { // Crear un puerto
      double x, y;
      inputFile >> x >> y; // Lee las coordenadas del puerto

      // Crea un nuevo puerto con las coordenadas leídas
      Port *port = new Port(ports.size(), x, y);
      ports.push_back(port); // Añade el puerto al vector de puertos
      break;
    }
    case 4: { // Cargar un contenedor en un barco
      int idShip, idContainer;
      inputFile >> idShip >>
          idContainer; // Lee los identificadores del barco y contenedor

      // Carga el contenedor en el barco especificado
      ships[idShip]->load(containers[idContainer]);
      break;
    }
    case 5: { // Descargar un contenedor de un barco
      int idShip, idContainer;
      inputFile >> idShip >>
          idContainer; // Lee los identificadores del barco y contenedor

      // Descarga el contenedor del barco especificado
      ships[idShip]->unLoad(containers[idContainer]);
      break;
    }
    case 6: { // Hacer que un barco viaje a otro puerto
      int idShip, idPort;
      inputFile >> idShip >>
          idPort; // Lee los identificadores del barco y puerto

      // Hace que el barco viaje al puerto especificado
      ships[idShip]->sailTo(ports[idPort]);
      break;
    }
    case 7: { // Reabastecer de combustible a un barco
      int idShip;
      double amount;
      inputFile >> idShip >>
          amount; // Lee el identificador del barco y la cantidad de combustible

      // Reabastece de combustible al barco especificado
      ships[idShip]->reFuel(amount);
      break;
    }
    default:
      break;
    }
  }

  // Itera sobre todos los puertos y escribe su información en el archivo de
  // salida
  for (Port *port : ports) {
    outputFile << port->toString() << endl;
  }

  // Limpia los objetos creados dinámicamente
  for (Container *container : containers) {
    delete container;
  }
  for (Ship *ship : ships) {
    delete ship;
  }
  for (Port *port : ports) {
    delete port;
  }

  // Cierra los archivos de entrada y salida
  inputFile.close();
  outputFile.close();

  return 0; // Termina el programa exitosamente
}