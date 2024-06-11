// =========================================================
// File: ship.h
// Author: Lizeth Niniz Corona - a01711740
// Date: 09 de Junio del 2024
// Description:
// =========================================================
#ifndef SHIP_H
#define SHIP_H

#include "container.h"
#include "heavy.h"
#include "light.h"
#include "liquid.h"
#include "port.h"
#include "refrigerated.h"
#include "simpleship.h"
#include <iomanip>
#include <list>
#include <sstream>
#include <string>

// Definición de la clase Ship que hereda de SimpleShip
class Ship : public SimpleShip {
private:
  int currentWeight,
      totalWeight; // Peso actual y máximo que puede cargar el barco
  int currentNumberOfAllContainers,
      maxNumberOfAllContainers; // Número actual y máximo de contenedores
  int currentNumberOfHeavyContainers,
      maxNumberOfHeavyContainers; // Número actual y máximo de contenedores
                                  // pesados
  int currentNumberOfRefrigeratedContainers,
      maxNumberOfRefrigeratedContainers; // Número actual y máximo de
                                         // contenedores refrigerados
  int currentNumberOfLiquidContainers,
      maxNumberOfLiquidContainers;   // Número actual y máximo de contenedores
                                     // líquidos
  double fuel, fuelConsumptionPerKM; // Cantidad de combustible actual y consumo
                                     // de combustible por kilómetro
  Port *currentPort; // Puerto actual en el que se encuentra el barco
  std::list<Container *> containers; // Lista de contenedores que lleva el barco

  bool contains(
      Container *); // Método para verificar si un contenedor está en el barco
  void remove(Container *); // Método para eliminar un contenedor del barco

public:
  Ship(int, Port *, int, int, int, int, int,
       double);       // Constructor con varios parámetros
  Ship(const Ship &); // Constructor de copia

  int getId() const;            // Método para obtener el ID del barco
  int getCurrentWeight() const; // Método para obtener el peso actual del barco
  int getTotalWeight()
      const; // Método para obtener el peso total que puede cargar el barco
  int getCurrentNumberOfAllContainers()
      const; // Método para obtener el número actual de todos los contenedores
  int getMaxNumberOfAllContainers()
      const; // Método para obtener el número máximo de todos los contenedores
  int getCurrentNumberOfHeavyContainers()
      const; // Método para obtener el número actual de contenedores pesados
  int getMaxNumberOfHeavyContainers()
      const; // Método para obtener el número máximo de contenedores pesados
  int getCurrentNumberOfRefrigeratedContainers()
      const; // Método para obtener el número actual de contenedores
             // refrigerados
  int getMaxNumberOfRefrigeratedContainers()
      const; // Método para obtener el número máximo de contenedores
             // refrigerados
  int getCurrentNumberOfLiquidContainers()
      const; // Método para obtener el número actual de contenedores líquidos
  int getMaxNumberOfLiquidContainers()
      const; // Método para obtener el número máximo de contenedores líquidos
  double
  getFuel() const; // Método para obtener la cantidad de combustible actual
  double getFuelConsumptionPerKM()
      const; // Método para obtener el consumo de combustible por kilómetro
  Port *getCurrentPort() const; // Método para obtener el puerto actual
  std::list<Container *> getCurrentContainers()
      const; // Método para obtener la lista de contenedores actuales

  bool sailTo(Port *); // Método para hacer que el barco navegue a otro puerto
  void reFuel(double); // Método para reabastecer de combustible el barco
  bool load(Container *);   // Método para cargar un contenedor en el barco
  bool unLoad(Container *); // Método para descargar un contenedor del barco

  std::string toString()
      const; // Método para obtener una representación en cadena del barco

  virtual ~Ship(); // Destructor virtual
};

// ============ CONSTRUCTOR ============
//
// Constructor con ocho parámetros (identificador de la nave, puerto actual,
// peso total que puede llevar, máxima cantidad de contenedores (totales,
// pesados, refrigerados y líquidos) que puede llevar la nave y el consumo por
// kilómetro). Debe invocar al constructor de la clase superior con los
// parámetros correctos. El resto de las variables de instancia se inicializan a
// cero.
//
Ship::Ship(int id, Port *port, int totalWeight, int maxNumberOfAllContainers,
           int maxNumberOfHeavyContainers,
           int maxNumberOfRefrigeratedContainers,
           int maxNumberOfLiquidContainers, double fuelConsumptionPerKM)
    : SimpleShip(id), currentWeight(0), totalWeight(totalWeight),
      currentNumberOfAllContainers(0),
      maxNumberOfAllContainers(maxNumberOfAllContainers),
      currentNumberOfHeavyContainers(0),
      maxNumberOfHeavyContainers(maxNumberOfHeavyContainers),
      currentNumberOfRefrigeratedContainers(0),
      maxNumberOfRefrigeratedContainers(maxNumberOfRefrigeratedContainers),
      currentNumberOfLiquidContainers(0),
      maxNumberOfLiquidContainers(maxNumberOfLiquidContainers), fuel(0),
      fuelConsumptionPerKM(fuelConsumptionPerKM), currentPort(port),
      containers() {}

// ============ CONSTRUCTOR COPIAS ============
//
// Constructor de copia que copia las variables miembro de otro objeto Ship.
//
Ship::Ship(const Ship &other) : SimpleShip(other) {
  this->currentWeight = other.currentWeight;
  this->totalWeight = other.totalWeight;
  this->currentNumberOfAllContainers = other.currentNumberOfAllContainers;
  this->maxNumberOfAllContainers = other.maxNumberOfAllContainers;
  this->currentNumberOfHeavyContainers = other.currentNumberOfHeavyContainers;
  this->maxNumberOfHeavyContainers = other.maxNumberOfHeavyContainers;
  this->currentNumberOfRefrigeratedContainers =
      other.currentNumberOfRefrigeratedContainers;
  this->maxNumberOfRefrigeratedContainers =
      other.maxNumberOfRefrigeratedContainers;
  this->currentNumberOfLiquidContainers = other.currentNumberOfLiquidContainers;
  this->maxNumberOfLiquidContainers = other.maxNumberOfLiquidContainers;
  this->fuel = other.fuel;
  this->fuelConsumptionPerKM = other.fuelConsumptionPerKM;
  this->currentPort = other.currentPort;
  this->containers = other.containers;
}

// ============ GETTERS ============
// Métodos que devuelven los valores de las variables privadas.

int Ship::getId() const { return SimpleShip::getId(); }
int Ship::getCurrentWeight() const { return currentWeight; }
int Ship::getTotalWeight() const { return totalWeight; }
int Ship::getCurrentNumberOfAllContainers() const {
  return currentNumberOfAllContainers;
}
int Ship::getMaxNumberOfAllContainers() const {
  return maxNumberOfAllContainers;
}
int Ship::getCurrentNumberOfHeavyContainers() const {
  return currentNumberOfHeavyContainers;
}
int Ship::getMaxNumberOfHeavyContainers() const {
  return maxNumberOfHeavyContainers;
}
int Ship::getCurrentNumberOfRefrigeratedContainers() const {
  return currentNumberOfRefrigeratedContainers;
}
int Ship::getMaxNumberOfRefrigeratedContainers() const {
  return maxNumberOfRefrigeratedContainers;
}
int Ship::getCurrentNumberOfLiquidContainers() const {
  return currentNumberOfLiquidContainers;
}
int Ship::getMaxNumberOfLiquidContainers() const {
  return maxNumberOfLiquidContainers;
}
double Ship::getFuel() const { return fuel; }
double Ship::getFuelConsumptionPerKM() const { return fuelConsumptionPerKM; }
Port *Ship::getCurrentPort() const { return currentPort; }
std::list<Container *> Ship::getCurrentContainers() const { return containers; }

// ============ SAILTO ============
//
// Este método calcula el combustible necesario para ir de un puerto a otro con
// base en el consumo que genera cada uno de los contenedores que lleva la nave
// en ese momento, la distancia al puerto destino y el consumo por kilómetro de
// esta nave. Si la cantidad de combustible es menor al combustible actual,
// resta la cantidad calculada al combustible actual, elimina la nave del puerto
// actual, agrega la nave al puerto destino, cambia el puerto actual al puerto
// destino y regresa true para indicar que sí se pudo realizar el viaje.
//
bool Ship::sailTo(Port *port) {
  // Calcular la distancia entre el puerto actual y el puerto destino
  double distance = currentPort->getDistance(port);

  // Calcular el consumo de combustible total
  double totalFuelConsumption = 0.0;

  for (Container *container : containers) {
    totalFuelConsumption += container->getConsumption();
  }

  double requiredFuel =
      totalFuelConsumption * distance + (fuelConsumptionPerKM * distance);

  // Verificar si hay suficiente combustible
  if (fuel >= requiredFuel) {
    // Restar la cantidad requerida de combustible al combustible actual
    fuel -= requiredFuel;

    // Eliminar el barco del puerto actual
    currentPort->outgoingShip(this);

    // Agregar el barco al puerto destino
    port->incomingShip(this);

    // Actualizar el puerto actual
    currentPort = port;

    return true;
  } else {
    // Si no hay suficiente combustible, no se realiza el viaje
    return false;
  }
}

// ============ REFUEL ============
//
// Este método agrega combustible al tanque de la nave, siempre y cuando la
// cantidad de combustible no supere la capacidad máxima del tanque y sea
// positiva.
//
void Ship::reFuel(double fuel) {
  if (fuel > 0) {
    this->fuel += fuel;
  }
}

// ============ LOAD ============
//
// Este método deberá revisar varias condiciones. La primera, si el puerto
// actual no tiene el contenedor o si la cantidad actual de contenedores es
// mayor o igual a la cantidad máxima de contenedores o si el peso actual más el
// peso del contenedor excede el peso total que puede llevar la nave, no es
// posible cargar ese contenedor. A continuación, deberá verificar, de acuerdo
// al tipo de contenedor, que no se exceda de la cantidad máxima permitida de
// contenedores de un tipo determinado. En cualquier caso anterior, deberá
// regresar false. Si se puede hacer la carga, deberá remover el contenedor del
// puerto actual, agregar a la lista de contenedor, incrementar el número de
// contenedores que lleva la nave tanto en lo general, como en lo que respecta a
// un tipo determinado, regresando true para indicar que se realizó la carga del
// contenedor.
//
bool Ship::load(Container *container) {
  // Verificar si el puerto actual tiene el contenedor
  if (!currentPort->contains(container)) {
    return false;
  }

  // Verificar si se ha alcanzado la capacidad del barco
  if (currentNumberOfAllContainers >= maxNumberOfAllContainers ||
      currentWeight + container->getWeight() > totalWeight) {
    return false;
  }

  // Verificar los límites específicos de los tipos de contenedores
  if (dynamic_cast<HeavyContainer *>(container)) {
    if (currentNumberOfHeavyContainers >= maxNumberOfHeavyContainers) {
      return false;
    }
  }
  if (dynamic_cast<RefrigeratedContainer *>(container)) {
    if (currentNumberOfRefrigeratedContainers >=
        maxNumberOfRefrigeratedContainers) {
      return false;
    }
  }
  if (dynamic_cast<LiquidContainer *>(container)) {
    if (currentNumberOfLiquidContainers >= maxNumberOfLiquidContainers) {
      return false;
    }
  }

  // Si se cumplen las condiciones, cargar el contenedor
  currentPort->remove(container);
  containers.push_back(container);
  currentWeight += container->getWeight();
  currentNumberOfAllContainers++;

  // Actualizar el conteo de tipos específicos de contenedores
  if (dynamic_cast<HeavyContainer *>(container)) {
    currentNumberOfHeavyContainers++;
  }
  if (dynamic_cast<RefrigeratedContainer *>(container)) {
    currentNumberOfRefrigeratedContainers++;
  }
  if (dynamic_cast<LiquidContainer *>(container)) {
    currentNumberOfLiquidContainers++;
  }

  return true;
}

// ============ CONTAINS ============
// Indica si el contenedor se encuentra dentro de la lista de contenedores.
//
bool Ship::contains(Container *container) {
  // Iterar sobre cada contenedor en la lista de contenedores en el barco
  for (Container *c : containers) {
    // Verificar si el contenedor actual coincide con el contenedor objetivo
    if (c->getId() == container->getId()) {
      return true; // El contenedor se encuentra en el barco
    }
  }
  return false; // El contenedor no se encuentra en el barco
}

// ============ REMOVE ============
// Remueve un contenedor determinado de la lista de contenedores.
//
void Ship::remove(Container *container) {
  // Buscar y eliminar el contenedor de la lista
  containers.remove(container);
  // Actualizar el peso actual y el número de contenedores
  currentWeight -= container->getWeight();
  currentNumberOfAllContainers--;
  // Actualizar el conteo de tipos específicos de contenedores
  if (dynamic_cast<HeavyContainer *>(container)) {
    currentNumberOfHeavyContainers--;
  }
  if (dynamic_cast<RefrigeratedContainer *>(container)) {
    currentNumberOfRefrigeratedContainers--;
  }
  if (dynamic_cast<LiquidContainer *>(container)) {
    currentNumberOfLiquidContainers--;
  }
}

// ============ UNLOAD ============
//
// Este método, primero, deberá revisar si lleva el contenedor indicado. Si es
// así, deberá remover el contenedor de la lista de contenedores, agregarlo al
// puerto actual, reducir el número de contenedores que lleva la nave tanto en
// lo general, como en lo que respecta a un tipo determinado, regresando true
// para indicar que se realizó la descarga del contenedor. Si no, regresa false.
//
bool Ship::unLoad(Container *container) {
  // Verificar si el barco tiene el contenedor
  if (!contains(container)) {
    return false;
  }
  // Remover el contenedor de la lista del barco
  remove(container);
  // Agregar el contenedor al puerto actual
  currentPort->add(container);
  return true;
}

// ============ TOSTRING ============
//
// Regresa un string con el siguiente formato: "Ship #id : fuel", seguido de
// "\n\t\tLight Containers: " y la lista de contenedores ligeros, a continuación
// "\n\t\tHeavy Containers: " y la lista de contenedores pesados; y así para el
// resto de los contenedores refrigerados y líquidos (VER LOS EJEMPLOS DE
// SALIDA).
//
std::string Ship::toString() const {
  std::ostringstream oss;
  // Encabezado del barco
  oss << "Ship " << getId() << ": " << std::fixed << std::setprecision(2)
      << fuel << "\n";

  // Listas de contenedores
  std::list<int> lightContainers;
  std::list<int> heavyContainers;
  std::list<int> refrigeratedContainers;
  std::list<int> liquidContainers;

  for (Container *container : containers) {
    if (dynamic_cast<LightContainer *>(container)) {
      lightContainers.push_back(container->getId());
    } else if (dynamic_cast<RefrigeratedContainer *>(container)) {
      refrigeratedContainers.push_back(container->getId());
    } else if (dynamic_cast<LiquidContainer *>(container)) {
      liquidContainers.push_back(container->getId());
    } else if (dynamic_cast<HeavyContainer *>(container)) {
      heavyContainers.push_back(container->getId());
    }
  }

  // Añade contenedores ligeros
  oss << "\t\tLight Containers: ";
  for (int id : lightContainers) {
    oss << id << " ";
  }
  oss << "\n";

  // Añade contenedores pesados
  oss << "\t\tHeavy Containers: ";
  for (int id : heavyContainers) {
    oss << id << " ";
  }
  oss << "\n";

  // Añade contenedores refrigerados
  oss << "\t\tRefrigerated Containers: ";
  for (int id : refrigeratedContainers) {
    oss << id << " ";
  }
  oss << "\n";

  // Añade contenedores líquidos
  oss << "\t\tLiquid Containers: ";
  for (int id : liquidContainers) {
    oss << id << " ";
  }
  oss << "\n";

  return oss.str();
}

// ============ DESTRUCTOR ============
// Destructor virtual
Ship::~Ship() {}

#endif