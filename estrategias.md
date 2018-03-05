# Estrategias

## Antes de hacer un envío
+ Crea un par de casos de prueba si los ejemplos no son suficientes. Revisa que la respuesta es correcta.
+ Está justo el tiempo límite? Genera casos de pruebas máximos para revisar que la solución no tarda demasiado. Recuerda que en general las prestaciones del servidor pueden ser mayores que las de tu computadora (Aunque deberían ser las mismas en competencias de ACM-ICPC oficiales).
+ Es válida la cantidad de memoria empleada?
+ Puede haber algún overflow?
+ Asegúrate enviar el fichero correcto.
+ No hagas ningún llamado a funciones del sistema ni intentes leer o escribir fuera de los ficheros establecidos.

## Wrong Answer
+ Imprime (en papel) tu solución con información en el código de debug. (Valores de variables intermedias para ciertos casos de prueba).
+ Estas reiniciando correctamente todas las estructuras de datos entre casos de prueba.
+ El algoritmo funciona para los límites establecidos en el problema?
+ Vuelve a leer detenidamente la orden del problema.
+ Existe algún caso de prueba particular que no hayas manejado? Que tal si n = 0 ó si n = 1, o si la lista es vacía?
+ Entendiste correctamente la orden del problema?
+ Estás usando alguna variable sin inicializar?
+ Está ocurriendo algún overflow?
+ Intercambiaste dos variables como `i` por `j` ó `N` por `M`?
+ Estás seguro de que el algoritmo es correcto?
+ Que casos especiales no has pensado aún?
+ Las funciones de la biblioteca estándar (STL) funcionan como crees o como la estás usando?
+ Añade algunos `asserts` al código. Prueba volver a enviar la solución.
+ Crea nuevos casos de prueba.
+ Revisa el algoritmo (sus pasos intermedios) corriendo un caso de prueba simple. 
+ Vuelve a revisar esta lista.
+ Explicale tu algoritmo a un compañero. Antes de explicarle el algoritmo dile que no te crea ni una palabra de lo que le vas a decir y que escuche criticamente para que te obligue hacerle entender cada paso.
+ Pídele a un compañero que revise el código.
+ Levántate de la computadora y estira las piernas. Aprovecha y ve al baño.
+ Estás imprimiendo la salida en el formato adecuado. 
    * Todos los números en la misma línea (o en líneas distintas). 
    * Sin espacio al final de cada línea. 
    * Un cambio de línea al final de la salida. 
    * Las cifras de precisión adecuadas. 
    * La respuesta en mayúscula/minúscula.
+ Vuelve a escribir tu solución desde cero o pídele a alguien que lo haga.

## Runtime Error:
+ Probaste todos los casos de prueba raros localmente?
+ Estás usando alguna variable sin inicializar?
+ Estas leyendo o escribiendo fuera de algún vector o array?
+ Algún `assert` puede estar fallando?
+ Estás haciendo alguna división por 0? (mod 0 por ejemplo)
+ Recursión infinita? Ciclos infinitos?
+ Estás usando algún puntero o iterador inválido?
+ Estás empleando demasiada memoria?

## Time Limit Exceeded
+ Tienes algún ciclo infinito
+ Cuál es la complejidad de tu algoritmo?
+ Estás copiando muchos datos por valor en vez de por referencia?
+ Cuán grande es la entrada del problema? Considera usar metodos de lectura y escritura rápida.
+ Que creen tus compañeros de equipo sobre el algoritmos.

## Memory Limit Exceeded
+ Cuál es la máxima cantidad de memorima que tu algoritmo debe consumir?
    * Un entero (int) son 4 bytes
    * Un long long son 8 bytes
    * Un bool y un char es 1 byte
    * Un array de `N` enteros pesa `4 * N` bytes.
    * Un vector de `N` enteros pesa `4 * N + Const` bytes.
    * 1MB = 1000KB
    * 1KB = 1000Byte

+ Estas reiniciando correctamente todas las estructuras de datos entre casos de prueba.

## Disclaimer

Estos consejos fueron extraídos del team reference del equipo Omogen Heap del KTH Royal Institute of Technology. Pueden ver el notebook completo [en github](https://github.com/kth-competitive-programming/kactl)