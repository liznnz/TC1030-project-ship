// =========================================================
// File: heavy.h
// Author: Lizeth Niniz Corona - a01711740
// Date: 09 de Junio del 2024
// Description:
// Este archivo define la clase HeavyContainer, que hereda de la clase
// Container. La clase HeavyContainer está equipada con constructores, incluido
// un constructor de copia y proporciona un método para obtener el valor de
// consumo específico para contenedores pesados.
// =========================================================

#ifndef HEAVY_H
#define HEAVY_H

#include "container.h"

// Definición de la clase HeavyContainer que hereda de Container
class HeavyContainer : public Container {
public:
  // Constructor que toma dos parámetros: id y peso.
  HeavyContainer(int, int);
  // Constructor que toma tres parámetros: id, peso y tipo.
  HeavyContainer(int, int, ContainerType);
  // Constructor de copia.
  HeavyContainer(const HeavyContainer &);

  // Método para obtener el consumo específico de un contenedor pesado.
  double getConsumption() const;
};

// ============ CONSTRUCTOR ============

// Implementación del constructor que toma dos parámetros: id y peso.
// Inicializa el contenedor pesado con el tipo HEAVY.
HeavyContainer::HeavyContainer(int id, int weight)
    : Container(id, weight, HEAVY) {}

// ============ CONSTRUCTOR COPIAS ============

// Implementación del constructor de copia.
// Inicializa un nuevo objeto HeavyContainer copiando las variables miembro de
// otro objeto HeavyContainer.
HeavyContainer::HeavyContainer(const HeavyContainer &other)
    : Container(other) {}

// ============ GETTERS ============

// Implementación del método getConsumption, que devuelve el consumo del
// contenedor pesado. El consumo de un contenedor pesado se calcula como el peso
// multiplicado por 3.
double HeavyContainer::getConsumption() const { return weight * 3; }

#endif