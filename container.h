// =========================================================
// File: container.h
// Author: Lizeth Niniz Corona
// Date:9 de Junio del 2024
// Description:
// Este archivo contiene la definición de la clase Container
// y una enumeración ContainerType que define diferentes tipos de contenedores.
// =========================================================
#ifndef CONTAINER_H
#define CONTAINER_H

// Definimos una enumeración llamada ContainerType, que representa diferentes
// tipos de contenedores.
typedef enum {
  LIGHT,        // Contenedores ligeros
  HEAVY,        // Contenedores pesados
  REFRIGERATED, // Contenedores refrigerados
  LIQUID        // Contenedores de líquidos
} ContainerType;

// Definición de la clase Container.
class Container {
protected:
  int id, weight; // Variables protegidas para almacenar el identificador y el
                  // peso del contenedor.
  ContainerType
      type; // Tipo de contenedor definido por la enumeración ContainerType.

public:
  // Constructor que toma tres parámetros: id, weight y type.
  Container(int, int, ContainerType);
  // Constructor de copia.
  Container(const Container &);

  // Métodos de acceso (getters) para obtener el tipo, id y peso del contenedor.
  ContainerType getType() const;
  int getId() const;
  int getWeight() const;

  // Sobrecarga del operador "==" para comparar si dos contenedores son iguales.
  bool operator==(const Container *);
  bool operator==(const Container &);

  // Sobrecarga del operador "<" para comparar si un contenedor es menor que
  // otro.
  bool operator<(const Container *);
  bool operator<(const Container &);

  // Método virtual puro que debe ser implementado por las clases derivadas para
  // obtener el consumo del contenedor.
  virtual double getConsumption() const = 0;

  // Destructor virtual para permitir la destrucción adecuada de objetos
  // derivados.
  virtual ~Container();
};

// ============ CONSTRUCTOR ============

// Implementación del constructor que inicializa las variables miembro id,
// weight y type.
Container::Container(int id, int weight, ContainerType type) {
  this->id = id;
  this->weight = weight;
  this->type = type;
}

// ============ CONSTRUCTOR COPIAS ============

// Implementación del constructor de copia que copia las variables miembro de
// otro objeto Container.
Container::Container(const Container &other) {
  this->id = other.id;
  this->weight = other.weight;
  this->type = other.type;
}
// ============ GETTERS ============

// Implementación de los métodos de acceso para obtener el tipo, id y peso del
// contenedor.
ContainerType Container::getType() const { return type; }
int Container::getId() const { return id; }
int Container::getWeight() const { return weight; }

// ============ OPERADORES ============

// Implementación de la sobrecarga del operador "==" para comparar si dos
// contenedores (objeto tipo puntero) son iguales basándose en su id.
bool Container::operator==(const Container *other) {
  return this->id == other->id;
}

// Implementación de la sobrecarga del operador "==" para comparar si dos
// contenedores (pasados por referencia) son iguales basándose en su id.
bool Container::operator==(const Container &other) {
  return this->id == other.id;
}

// Implementación de la sobrecarga del operador "<" para comparar si un
// contenedor (objeto tipo puntero) es menor que otro, basándose en el id.
bool Container::operator<(const Container *other) {
  return this->id < other->id;
}

// Implementación de la sobrecarga del operador "<" para comparar si un
// contenedor (pasado por referencia) es menor que otro, basándose en el id.
bool Container::operator<(const Container &other) {
  return this->id < other.id;
}

// ============ DESTRUCTOR ============

// Implementación del destructor.
Container::~Container() {}

#endif