# TC1030-project-ship

### Índice

1. [Introducción](#introducción)
2. [Funcionamiento del Sistema](#funcionamiento-del-sistema)
3. [Objetivo](#objetivo)

## [Introducción](#introducción)

A continuación se detallará el desarrollo y el funcionamiento de un sistema de gestión portuaria, diseñado para administrar de manera eficiente los contenedores y los barcos que los transportan. Este proyecto simula diversas operaciones comunes en la gestión de puertos, tales como la carga y descarga de contenedores, el reabastecimiento de combustible de los barcos, y la navegación entre diferentes puertos.

**Descripción del Proyecto**

El sistema se compone de varias clases clave, cada una con su propia responsabilidad y comportamiento. Las clases principales incluidas en el proyecto son:

1. **Clases de Contenedores**
    - [`Container`](https://github.com/liznnz/TC1030-project-ship/blob/main/container.h) : Clase base para todos los tipos de contenedores.
    - [`LightContainer`](https://github.com/liznnz/TC1030-project-ship/blob/main/light.h) : Contenedores ligeros destinados a cargas de menor peso.

    - [`HeavyContainer`](https://github.com/liznnz/TC1030-project-ship/blob/main/heavy.h) : Contenedores pesados para cargas más grandes y pesadas.
    - [`RefrigeratedContainer`](https://github.com/liznnz/TC1030-project-ship/blob/main/refrigerated.h) : Contenedores con capacidad de refrigeración para mercancías perecederas.

    - [`LiquidContainer`](https://github.com/liznnz/TC1030-project-ship/blob/main/liquid.h) : Contenedores diseñados para transportar líquidos.

2. **Clases de Barcos**
    - [`SimpleShp`](https://github.com/liznnz/TC1030-project-ship/blob/main/simpleship.h) : Clase base que representa una nave simple con un identificador único.
    - [`Ship`](https://github.com/liznnz/TC1030-project-ship/blob/main/ship.h) : Clase derivada de [SimpleShip](https://github.com/liznnz/TC1030-project-ship/blob/main/simpleship.h), que añade atributos y métodos específicos como capacidad de carga, consumo de combustible, y la capacidad de navegar entre puertos.

3. **Clases de Puertos**
    -[`Port`](https://github.com/liznnz/TC1030-project-ship/blob/main/port.h) : Clase que representa un puerto con su ubicación geográfica (coordenadas), una colección de contenedores, y una lista de barcos que han estado o están actualmente en el puerto.


## [Funcionamiento del sistema](#funcionamiento-del-sistema)

El archivo [`main.cpp`](https://github.com/liznnz/TC1030-project-ship/blob/main/main.cpp)  se encarga de ejecutar las operaciones principales. Este archivo lee datos de un archivo de entrada para crear y gestionar los objetos (contenedores, barcos y puertos), y simula las acciones necesarias para la gestión portuaria. Las operaciones incluyen:

- Creación de contenedores y barcos: Basado en los datos de entrada.
- Carga y descarga de contenedores: En diferentes barcos según las reglas de capacidad y tipo de contenedor.
- Navegación entre puertos: Basado en la disponibilidad de combustible y la distancia.
- Reabastecimiento de combustible: Para asegurar que los barcos puedan realizar sus viajes.
- Actualización y monitoreo del estado: Los resultados se imprimen en un formato detallado que muestra el estado actual de los puertos y barcos.

## [Objetivo](#objetivo)

El objetivo de esta sección es ayudar a entender los conceptos de polimorfismo, clases, objetos, métodos, atributos y más, integrándolos de manera que se comprendan fácil y claramente.

De igual manera es simular un sistema realista de gestión portuaria que permita la manipulación eficiente de contenedores y barcos. La simulación proporciona una herramienta valiosa para la comprensión y optimización de operaciones portuarias.

# ¿ Quién Soy?

![](images/logotecmty.png)


Nombre - Lizeth Niniz Corona

Matrícula - A01711740

Correo Electrónico - a01711740@tec.mx
