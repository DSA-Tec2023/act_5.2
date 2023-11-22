#include <iostream>
#include "hash.hpp"

int main() { 
// arreglo con las llaves a procesar
//int a[] = {2, 15, 24, 11, 27, 8, 12};
int a[] = {234789, 1523456, 242345, 111234, 271456, 813456, 1209874};
int n = sizeof(a)/sizeof(a[0]);

// insertar las llaves en la tabla de hash
Hash h(9); // 7 es el número de buckets en la tabla de hash
for (int i = 0; i < n; i++)
	h.insertaElemento(a[i]);

// mostrar la tabla de Hash
h.imprimeHash();

// eliminar 11
//h.borraElemento(11);
h.borraElemento(242345);

// mostrar la tabla de Hash
h.imprimeHash();

}
