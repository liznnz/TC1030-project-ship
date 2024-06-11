// =========================================================
// File: refrigerated.h
// Author: Lizeth Niniz Corona - a01711740
// Date: 09 de Junio del 2024
// Description:
// Descripción: Este archivo define la clase RefrigeratedContainer que hereda de
// HeavyContainer.
// =========================================================
#ifndef REFRIGERATED_H
#define REFRIGERATED_H

#include "heavy.h"

// Definición de la clase RefrigeratedContainer que hereda de HeavyContainer
class RefrigeratedContainer : public HeavyContainer {
public:
  RefrigeratedContainer(int,
                        int); // Constructor que toma dos parámetros: id y peso.
  RefrigeratedContainer(const RefrigeratedContainer &); // Constructor de copia.

  double getConsumption() const; // Método para obtener el consumo específico de
                                 // un contenedor refrigerado.
};

// ============ CONSTRUCTOR ============

// Implementación del constructor que toma dos parámetros: id y peso.
// Inicializa el contenedor refrigerado utilizando el constructor de
// HeavyContainer.
RefrigeratedContainer::RefrigeratedContainer(int id, int weight)
    : HeavyContainer(id, weight) {}

// ============ CONSTRUCTOR COPIAS ============

// Implementación del constructor de copia.
// Inicializa un nuevo objeto RefrigeratedContainer copiando las variables
// miembro de otro objeto RefrigeratedContainer.
RefrigeratedContainer::RefrigeratedContainer(const RefrigeratedContainer &other)
    : HeavyContainer(other) {}

// ============ GETTERS ============

// Implementación del método getConsumption, que devuelve el consumo del
// contenedor refrigerado. El consumo de un contenedor refrigerado se calcula
// como el peso multiplicado por 5.
double RefrigeratedContainer::getConsumption() const { return weight * 5; }

#endif