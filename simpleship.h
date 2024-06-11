// =========================================================
// File: simpleship.h
// Author: Lizeth Niniz Corona - a01711740
// Date: 09 de Junio del 2024
// Description:
// Esta clase representa una nave simple con un identificador único.
// Contiene métodos para obtener el identificador, comparar naves
// y un método virtual puro para obtener una representación en cadena.
// =========================================================

#ifndef SIMPLE_SHIP_H
#define SIMPLE_SHIP_H

#include <iostream>

class SimpleShip {
protected:
  int id; // Identificador único para la nave

public:
  SimpleShip(
      int); // Constructor que toma un parámetro: el identificador de la nave
  SimpleShip(const SimpleShip &); // Constructor de copia

  int getId() const; // Método para obtener el identificador de la nave

  bool operator==(const SimpleShip *); // Sobrecarga del operador "==" para
                                       // comparar dos naves usando punteros
  bool operator==(const SimpleShip &); // Sobrecarga del operador "==" para
                                       // comparar dos naves por referencia

  bool operator<(const SimpleShip *); // Sobrecarga del operador "<" para
                                      // comparar dos naves usando punteros
  bool operator<(const SimpleShip &); // Sobrecarga del operador "<" para
                                      // comparar dos naves por referencia

  virtual std::string
  toString() const = 0; // Método virtual puro para obtener una representación
                        // en cadena de la nave
};

// ============ CONSTRUCTOR ============
// Implementación del constructor que inicializa el identificador de la nave
SimpleShip::SimpleShip(int id) { this->id = id; }

// ============ CONSTRUCTOR COPIAS ============
// Implementación del constructor de copia que copia el identificador de otra
// nave
SimpleShip::SimpleShip(const SimpleShip &other) { this->id = other.id; }

// ============ GETTERS ============
// Implementación del método para obtener el identificador de la nave
int SimpleShip::getId() const { return id; }

// ============ OPERADORES ============
// Implementación de la sobrecarga del operador "==" para comparar dos naves
// usando punteros
bool SimpleShip::operator==(const SimpleShip *other) {
  return this->id == other->id;
}
// Implementación de la sobrecarga del operador "==" para comparar dos naves por
// referencia
bool SimpleShip::operator==(const SimpleShip &other) {
  return this->id == other.id;
}
// Implementación de la sobrecarga del operador "<" para comparar dos naves
// usando punteros
bool SimpleShip::operator<(const SimpleShip *other) {
  return this->id < other->id;
}
// Implementación de la sobrecarga del operador "<" para comparar dos naves por
// referencia
bool SimpleShip::operator<(const SimpleShip &other) {
  return this->id < other.id;
}

#endif