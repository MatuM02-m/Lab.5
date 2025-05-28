# Trabajo Práctico de Laboratorio N° 5

- Milenkovitch, Matías
- Electrónica IV
- Laboratorio 5

Se deberá crear un repositorio git con acceso público que tenga el código fuente de un proyecto en C que cumpla con los siguientes requisitos:
- Debe diseñar una calculadora abstracta que al ser creada no sepa hacer ninguna operación. El programa identificará, en la operación a realizar, los operandos y el operador. Luego, deberá buscar en una tabla dinámica cuál es la función correspondiente a esa operación y utilizarla para completar el cálculo.
- La implementación de la calculadora se realizará en un archivo independiente del programa principal.
- Deberá escribir también un programa principal de prueba que cree una calculadora abstracta , agregue las operaciones básicas de suma, resta multiplicación y división, y la pruebe efectuando un cálculo con cada operación.
- Los archivos calculadora.c y calculadora.h deberán ubicarse en la carpeta src. El ejecutable deberá ubicarse en la carpeta build/bin y los archivos objeto intermedios en la carpeta build/obj. El programa principal estará compuesto solo por la función main, que se ubicará en el archivo main.c.
- Se definirá un archivo de makefile para poder compilar el proyecto con el comando make all. Se documentará todo el código utilizando doxygen. El comando make doc deberá generar la documentación en HTML en la carpeta build/doc.
- Se deberá mantener un formato consistente en todo el código desarrollado (posición de llaves, formatos de identificadores y niveles de identado). Se deberá evitar la repetición de código utilizando, adecuadamente, macros y archivos de cabecera.