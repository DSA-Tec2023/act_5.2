# Actividad 5.2 
## Programación de Estructuras de Datos y Algoritmos Fundamentales

## Equipo 
- Andrés Martínez, A00227463
- Fernanda Granados, A01252895
- Santiago Poblete, A01254609
- Martín Tánori, A01252900

## Instrucciones

**¿Qué tengo que hacer?**

De manera individual, desarrolla la solución del siguiente problema:

Como en cualquier empresa, en la compañía naviera "International Seas, LTD." cada empleado tiene una descripción de su puesto de trabajo. Una descripción contiene unos pocos párrafos que describe las responsabilidad del puesto. Esta, junto con otros factores, como la antigüedad, se utiliza para determinar su salario.

En la empresa hemos desarrollado el sistema "Unlimited Seas". Este sistema libera al departamento de Recursos Humanos de tener que hacer un juicio inteligente sobre el valor del empleado; la descripción del puesto simplemente se escanea en busca de palabras y frases que indiquen responsabilidad. En particular, las descripciones de puestos que indican el control de un gran presupuesto o la gestión de un gran número de personas producen puntuaciones alta en "Unlimited Seas".

Lo que haremos en este activad, será implementar un sistema "Unlimited Seas" simplificado. Recibirás como entrada un diccionario y una serie de descripciones de puestos. Para cada descripción, deberás calcular el salario asociado con el puerto, de acuerdo con el sistema.

**Entrada**

La primera línea de entrada contiene 2 números enteros positivos: m 1,000, el número de palabras en diccionario "Unlimited Seas", y n 100, el número de descripciones de puestos. Las siguientes m líneas; cada una contiene una palabra y un valor en dólares (un número entero entre 0 y 1,000,000). A continuación, se encuentran las n descripciones de puestos. Cada descripción de puesto de trabajo consta de uno o más líneas de texto; para mayor facilidad, el texto se ha convertido a minúsculas y no tiene más caracteres que letras, números y espacios. Cada descripción de puesto de trabajo con una línea que contiene un punto.

**Salida**

Para cada descripción de puesto de trabajo, deberás calcular el salario correspondiente calculado como la suma de los valores de "Unlimited Seas" para todas las palabras que aparecen en la descripción. Las palabras que no aparecen en el diccionario tienen un valor de 0.

A continuación encontrarás un ejemplo de entrada y salida.

### Ejemplo de entrada

```
7 2
administer 100000
spending 200000
manage 50000
responsibility 25000
expertise 100
skill 50
money 75000
the incumbent will administer the spending of kindergarden milk money
and exercise responsibility for making change he or she will share
responsibility for the task of managing the money with the assistant
whose skill and expertise shall ensure the successful spending exercise
.
this individual must have the skill to perform a heart transplant and
expertise in rocket science
.
```
### Ejemplo de salida

```
700150
150
```

Realiza en forma individual una investigación y reflexión de la importancia y eficiencia del uso de tablas de hash en una situación problema de esta naturaleza,  generando un documento llamado "ReflexAct5.2.pdf ".



## Makefile 
Este proyecto cuenta con un archivo `makefile`, por lo tanto, es posible correr nuestro proyecto con los siguientes comandos: 

```
make run
```

Con este comando podemos compilar nuestro proyecto.

```
make clean
```
Este comando lo podemos utilizar para borrar las carpetas creadas al momento de compilar. 

```
make
```
Finalmente, con este comando podemos crear un archivo compilado `a.out` que posteriormente podremos ejecutar usando `./a.out` en la terminal. 

