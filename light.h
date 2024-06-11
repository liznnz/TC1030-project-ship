// =========================================================
// File: light.h
// Author: Lizeth Niniz Corona - a01711740
// Date: 09 de Junio del 2024
// Descripción: este archivo contiene la definición de la clase LightContainer,
// que hereda de la clase base Container. Incluye constructores para
// creando objetos LightContainer y un método para obtener el consumo.
// =========================================================
#ifndef LIGHT_H
#define LIGHT_H

#include "container.h"

// Definición de la clase LightContainer que hereda de Container
class LightContainer : public Container {
public:
  // Constructor que toma dos parámetros: id y peso.
  LightContainer(int, int);
  // Constructor de copia.
  LightContainer(const LightContainer &);

  // Método para obtener el consumo específico de un contenedor ligero.
  double getConsumption() const;
};

// ============ CONSTRUCTOR ============

// Implementación del constructor que toma dos parámetros: id y peso.
// Inicializa el contenedor ligero con el tipo LIGHT.
LightContainer::LightContainer(int id, int weight)
    : Container(id, weight, LIGHT) {}

// ============ CONSTRUCTOR COPIAS ============

// Implementación del constructor de copia.
// Inicializa un nuevo objeto LightContainer copiando las variables miembro de
// otro objeto LightContainer.
LightContainer::LightContainer(const LightContainer &other)
    : Container(other) {}

// ============ GETTERS ============

// Implementación del método getConsumption, que devuelve el consumo del
// contenedor ligero. El consumo de un contenedor ligero se calcula como el peso
// multiplicado por 2.5.
double LightContainer::getConsumption() const { return weight * 2.5; }

#endif