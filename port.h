// =========================================================
// File: port.h
// Author: Lizeth Niniz Corona - a01711740
// Date: 09 de Junio del 2024
// Description:
// Este archivo define la clase Port.
// La clase Port incluye información sobre la ubicación (x, y) y el
// identificador (id) del puerto. Además, mantiene listas de contenedores
// (containers), naves que han estado en el puerto (history), y naves que están
// actualmente en el puerto (current). Se proporcionan métodos para obtener
// información, calcular distancias, y manejar la llegada y salida de naves.
// =========================================================
#ifndef PORT_H
#define PORT_H

#include "container.h"
#include "heavy.h"
#include "light.h"
#include "liquid.h"
#include "refrigerated.h"
#include "simpleship.h"
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <list>
#include <sstream>
#include <string>

class Port {
private:
  int id;      // Identificador del puerto
  double x, y; // Coordenadas del puerto en un plano cartesiano
  std::list<Container *> containers; // Lista de contenedores en el puerto
  std::list<SimpleShip *> history; // Lista de naves que han estado en el puerto
  std::list<SimpleShip *>
      current; // Lista de naves que están actualmente en el puerto

public:
  Port(int, double, double); // Constructor que toma id, x e y
  Port(const Port &);        // Constructor de copia

  int getId() const;   // Método para obtener el id del puerto
  double getX() const; // Método para obtener la coordenada x del puerto
  double getY() const; // Método para obtener la coordenada y del puerto
  std::list<Container *>
  getContainers() const; // Método para obtener la lista de contenedores
  std::list<SimpleShip *>
  getHistory() const; // Método para obtener la lista de naves que han estado en
                      // el puerto
  std::list<SimpleShip *>
  getCurrent() const; // Método para obtener la lista de naves que están
                      // actualmente en el puerto

  double getDistance(
      Port *) const; // Método para calcular la distancia entre dos puertos
  void incomingShip(SimpleShip *); // Método para agregar una nave a la lista de
                                   // naves actuales
  void outgoingShip(
      SimpleShip *); // Método para manejar la salida de una nave del puerto

  bool contains(Container *); // Verifica si un contenedor está en el puerto
  void add(Container *);      // Agrega un contenedor al puerto
  void remove(Container *);   // Elimina un contenedor del puerto

  std::string toString()
      const; // Método para obtener una representación en string del puerto

  virtual ~Port(); // Destructor virtual
};

// ============ CONSTRUCTOR ============
Port::Port(int id, double x, double y) {
  this->id = id;
  this->x = x;
  this->y = y;
}
// ============ CONSTRUCTOR COPIAS ============
Port::Port(const Port &other) {
  this->id = other.id;
  this->x = other.x;
  this->y = other.y;
  this->containers = other.containers;
  this->history = other.history;
  this->current = other.current;
}
// ============ GETTERS ============
int Port::getId() const { return id; }
double Port::getX() const { return x; }
double Port::getY() const { return y; }
std::list<Container *> Port::getContainers() const { return containers; }
std::list<SimpleShip *> Port::getHistory() const { return history; }
std::list<SimpleShip *> Port::getCurrent() const { return current; }

// ============ GETDISTANCE ============
// Calcula la distancia euclidiana entre dos puertos
double Port::getDistance(Port *other) const {
  // Obtiene las coordenadas del otro puerto
  double otherX = other->getX();
  double otherY = other->getY();
  // Calcula la diferencia de coordenadas
  double diffX = otherX - this->x;
  double diffY = otherY - this->y;
  // Aplica la fórmula de la distancia euclidiana
  return sqrt(diffX * diffX + diffY * diffY);
}

// ============ OUTGOING ============
// Maneja la salida de una nave del puerto
void Port::outgoingShip(SimpleShip *ship) {
  // Busca la nave en la lista de naves actuales
  for (std::list<SimpleShip *>::iterator it = current.begin();
       it != current.end(); ++it) {
    if ((*it)->getId() == ship->getId()) {
      // Elimina la nave de la lista de actuales
      current.erase(it);
      // Verifica si la nave está en la lista de histórico
      bool foundInHistory = false;
      for (std::list<SimpleShip *>::iterator hist_it = history.begin();
           hist_it != history.end(); ++hist_it) {
        if ((*hist_it)->getId() == ship->getId()) {
          foundInHistory = true;
          break;
        }
      }
      // Si no está en histórico, la agrega
      if (!foundInHistory) {
        history.push_back(ship);
      }
      return; // Sale de la función después de procesar la nave
    }
  }
}

// ============ INCOMING ============
// Maneja la llegada de una nave al puerto
void Port::incomingShip(SimpleShip *ship) {
  // Verifica si la nave ya está en el puerto
  for (std::list<SimpleShip *>::iterator it = current.begin();
       it != current.end(); ++it) {
    if ((*it)->getId() == ship->getId()) {
      return;
    }
  }
  // Si no está en el puerto, se agrega a la lista
  current.push_back(ship);
}

// ============ CONTAINS ============
// Verifica si un contenedor específico está en el puerto
bool Port::contains(Container *container) {
  for (std::list<Container *>::iterator it = containers.begin();
       it != containers.end(); ++it) {
    if ((*it)->getId() == container->getId()) {
      return true; // El contenedor está en el puerto
    }
  }
  return false; // El contenedor no está en el puerto
}

// ============ ADD ============
// Agrega un contenedor al puerto
void Port::add(Container *container) { containers.push_back(container); }

// ============ REMOVE ============
// Elimina un contenedor del puerto
void Port::remove(Container *container) { containers.remove(container); }

// ============ TOSTRING ============
// Regresa un string con el siguiente formato: "Port #id : (x, y)", seguido de
// la lista de contenedores y naves que se encuentran en el puerto
std::string Port::toString() const {
  std::ostringstream oss;
  oss << "Port " << id << ": (" << std::fixed << std::setprecision(2) << x
      << ", " << y << ")\n";

  std::list<int> lightContainers, heavyContainers, refrigeratedContainers,
      liquidContainers;

  // Itera sobre contenedores y los clasifica
  for (auto container : containers) {
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

  // Añade las IDs de los contenedores a la cadena de salida
  oss << "  Light Containers: ";
  for (auto id : lightContainers) {
    oss << id << " ";
  }
  oss << "\n  Heavy Containers: ";
  for (auto id : heavyContainers) {
    oss << id << " ";
  }
  oss << "\n  Refrigerated Containers: ";
  for (auto id : refrigeratedContainers) {
    oss << id << " ";
  }
  oss << "\n  Liquid Containers: ";
  for (auto id : liquidContainers) {
    oss << id << " ";
  }

  // Añade las IDs de las naves actuales a la cadena de salida
  for (auto ship : current) {
    oss << "\n" << ship->toString();
  }

  return oss.str();
}

// ============ DESTRUCTOR ============
// Implementación del destructor
Port::~Port() {}

#endif