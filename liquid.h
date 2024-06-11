// =========================================================
// File: liquid.h
// Author: Lizeth Niniz Corona - a01711740
// Date: 09 de Junio del 2024
// Description: este archivo define la clase LiquidContainer,
// que hereda de la clase HeavyContainer. La clase LiquidContainer
// está equipada con constructores, incluido un constructor de copia
// y proporciona un método para obtener el valor de consumo específico
// para contenedores líquidos.
// =========================================================
#ifndef LIQUID_H
#define LIQUID_H

#include "heavy.h"

// Definición de la clase LiquidContainer que hereda de HeavyContainer
class LiquidContainer : public HeavyContainer {
public:
  // Constructor que toma dos parámetros: id y peso.
  LiquidContainer(int, int);
  // Constructor de copia.
  LiquidContainer(const LiquidContainer &);

  // Método para obtener el consumo específico de un contenedor líquido.
  double getConsumption() const;
};

// ============ CONSTRUCTOR ============

// Implementación del constructor que toma dos parámetros: id y peso.
// Inicializa el contenedor líquido utilizando el constructor de HeavyContainer.
LiquidContainer::LiquidContainer(int id, int weight)
    : HeavyContainer(id, weight) {}

// ============ CONSTRUCTOR COPIAS ============

// Implementación del constructor de copia.
// Inicializa un nuevo objeto LiquidContainer copiando las variables miembro
// de otro objeto LiquidContainer.
LiquidContainer::LiquidContainer(const LiquidContainer &other)
    : HeavyContainer(other) {}

// ============ GETTERS ============

// Implementación del método getConsumption, que devuelve el consumo del
// contenedor líquido. El consumo de un contenedor líquido se calcula como
// el peso multiplicado por 4.
double LiquidContainer::getConsumption() const { return weight * 4; }

#endif