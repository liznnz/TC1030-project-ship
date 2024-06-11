# TC1030-project-ship

### Índice

1. [Introducción](#introducción)
2. [Funcionamiento del Sistema](#funcionamiento-del-sistema)
3. [Objetivo](#objetivo)
4. [Explicación de Archivos](#explicación-de-archivos)
    - [Archivo Container](#archivo-container)
    - [Archivo Heavy](#archivo-heavy)
    - [Archivo Light](#archivo-light)
    - [Archivo Liquid](#archivo-liquid)
    - [Archivo Main](#archivo-main)
    - [Archivo Port](#archivo-port)
    - [Archivo Refrigereted](#archivo-refri)
    - [Archivo Ship](#archivo-ship)
    - [Archivo SimpleShip](#simple)
5. [¿Quién Soy?](#who)

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

## [Explicación de Archivos](#explicación-de-archivos)


> [!NOTE]
> Para usar el archivo es con consola de preferencia
> Usando el comando : ./main.cpp Archivo_Entrada.txt Archivo_Salida.txt

### [Container.h](#archivo-container)
---

El archivo [`container.h`](https://github.com/liznnz/TC1030-project-ship/blob/main/container.h) define la clase base `Container` y una enumeración `ContainerType` que representa diferentes tipos de contenedores (ligeros, pesados, refrigerados, líquidos). La clase `Container` incluye atributos protegidos para almacenar el identificador, el peso del contenedor y su tipo. Además, se proporcionan métodos públicos para obtener estos valores, así como operadores sobrecargados para comparar contenedores.

El archivo también define un método virtual puro llamado `getConsumption()`, que obliga a las clases derivadas a implementar su propia versión de este método para calcular el consumo específico de cada tipo de contenedor. Se incluye un constructor que inicializa las variables miembro y un constructor de copia. Para asegurar una correcta destrucción de los objetos derivados, se utiliza un destructor virtual. La definición y declaración de la clase se encuentran entre las guardas de inclusión para evitar múltiples inclusiones del archivo en el mismo proyecto.

### [Heavy.h](#archivo-heavy)
---


El archivo [`heavy.h`](https://github.com/liznnz/TC1030-project-ship/blob/main/heavy.h) define la clase `HeavyContainer`, que está diseñada para manejar contenedores pesados en un sistema de gestión portuaria. Esta clase hereda de una clase más general llamada `Container`, lo que significa que utiliza sus atributos y métodos. Dentro del archivo  se implementan un constructor que toma un ID y un peso para inicializar el contenedor, y un constructor de copia que permite crear un nuevo contenedor copiando uno existente.


Además, la clase incluye un método llamado `getConsumption()`, que calcula el consumo de combustible específicamente para contenedores pesados, multiplicando el peso del contenedor por 3. El archivo también utiliza mecanismos de protección para evitar que se incluya más de una vez en el mismo proyecto, asegurando así una correcta compilación del código.

### [Light.h](#archivo-light)
---

El archivo [`light.h`](https://github.com/liznnz/TC1030-project-ship/blob/main/light.h) define la clase `LightContainer` que hereda de la clase base `Container`. Esta clase está diseñada específicamente para manejar contenedores ligeros en el sistema de gestión portuaria. Incluye un constructor que toma dos parámetros para inicializar el contenedor con un `ID` y un `peso`, y establece el tipo de contenedor como `LIGHT`. También tiene un constructor de copia que permite crear un nuevo objeto `LightContainer` copiando los atributos de otro objeto del mismo tipo.

El archivo igual implementa el método `getConsumption()`, que calcula el consumo de combustible para los contenedores ligeros multiplicando el peso del contenedor por 2.5. Al igual que en otros archivos de encabezado, se utilizan guardas de inclusión `(#ifndef y #define)` para evitar múltiples inclusiones del mismo archivo durante la compilación.

### [Liquid.h](#archivo-liquid)
---

Esta clase está especializada para manejar contenedores de líquidos en el sistema de gestión portuaria. Inicializa estos contenedores utilizando el constructor de `HeavyContainer` (ya que es clase heredada) , pero proporciona su propia implementación del método getConsumption(), que calcula el consumo de combustible para contenedores líquidos multiplicando su peso por 4 incluyendo nuevamente polimorfismo.

### [Main.cpp](#archivo-main)
---

Este archivo es el núcleo del proyecto de simulación de gestión portuaria. 

Se encarga de leer datos de un archivo de entrada y realizar una serie de operaciones basadas en esos datos para gestionar contenedores, barcos y puertos. Las operaciones incluyen la creación de contenedores, barcos y puertos, así como la carga y descarga de contenedores, el reabastecimiento de combustible de los barcos y la navegación de los barcos entre puertos. Cada operación se lleva a cabo utilizando diversos métodos y clases definidas en archivos de encabezado asociados. 

Los resultados de estas operaciones se registran en un archivo de salida, proporcionando una representación detallada del estado de los puertos y barcos después de todas las operaciones.

A lo largo del archivo, se utilizan estructuras de control y métodos de las clases para gestionar y manipular objetos dinámicamente, asegurando una simulación precisa y eficiente. 


### [Port.h](#archivo-port)
---

Primeramente el archivo define la clase `Port`, que representa un puerto en el sistema de gestión portuaria. Esta clase incluye atributos para almacenar el identificador del puerto, sus coordenadas en un plano cartesiano, y listas para gestionar los contenedores presentes en el puerto, así como las naves que han estado y están actualmente en él. 

Esta clase proporciona métodos públicos para acceder a estos atributos, calcular la distancia a otros puertos, y manejar la llegada y salida de naves. 

Entre las funcionalidades clave, se incluyen métodos para agregar y eliminar contenedores del puerto, verificar si un contenedor específico está presente, y obtener una representación en cadena del puerto y su contenido.

### [Refrigerated.h](#archivo-refri)
---

Este archivo define la clase `RefrigeratedContainer`, que hereda de la clase `HeavyContainer`, y está específicamente diseñada para manejar contenedores refrigerados en el sistema de gestión portuaria. 


Esta clase incorpora un constructor que toma dos parámetros, el identificador y el peso del contenedor, inicializándolos mediante el constructor de HeavyContainer. También incluye un constructor de copia para crear nuevos objetos RefrigeratedContainer a partir de una instancia existente. 

La característica distintiva de esta clase es su método getConsumption(), que calcula el consumo de combustible para los contenedores refrigerados multiplicando el peso del contenedor por cinco.

### [Ship.h](#archivo-ship)
---

La clase Ship encapsula datos sobre el estado del barco, como su peso actual y máximo, la cantidad de contenedores que lleva (tanto en total como de tipos específicos), el combustible disponible y su consumo. También almacena información sobre el puerto en el que se encuentra actualmente y una lista de los contenedores que transporta.

El archivo proporciona una serie de métodos para interactuar con el barco. Estos métodos permiten realizar acciones como navegar a otro puerto (teniendo en cuenta el consumo de combustible y la distancia), recargar combustible, cargar y descargar contenedores, y obtener información sobre el estado del barco.

Además, el archivo incluye constructores para crear objetos Ship, tanto desde cero como a partir de otro objeto Ship existente. También hay un destructor virtual para liberar los recursos utilizados por el objeto cuando ya no se necesita.


### [SimpleShip](#simple)
---

La clase SimpleShip está diseñada como una clase base para otras clases que representan diferentes tipos de naves. Proporciona una funcionalidad básica común a todas las naves: un identificador único y la capacidad de comparar naves por su identificador.

El método toString() es virtual puro, lo que significa que debe ser implementado por las clases derivadas. Esto permite que cada tipo de nave tenga su propia forma de representarse como una cadena de texto.

En el contexto del archivo ship.h que se presentó anteriormente, la clase Ship hereda de SimpleShip y amplía su funcionalidad para incluir detalles específicos de un barco de carga, como la capacidad de carga, el consumo de combustible, y las operaciones de carga y descarga.

# [¿ Quién Soy ?](#who)

![](images/logotecmty.png)


Nombre - Lizeth Niniz Corona

Matrícula - A01711740

Correo Electrónico - a01711740@tec.mx
