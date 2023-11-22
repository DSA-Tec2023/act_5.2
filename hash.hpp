#include <iostream>
#include <list>
#include <string>
#include <sstream>

class Hash {
public:
    int BUCKET; // número de buckets
    // apuntador a la lista que contiene los buckets
    std::list<int> *table;

    Hash(int V) { // Constructor
        BUCKET = V;
        table = new std::list<int>[BUCKET];
    }

private:
    // función de hash que calcula la posición en la tabla
    int funcionHash(int x);

public:
    //Insertar un elemento en la tabla
    void insertaElemento(int key); 
    void imprimeHash();
    void borraElemento(int variable);

    // These functions are in development and are not part of the initial template.
    int returnValues(std::string sentence, std::string word_to_search[]);
    int get_value(int key);
};
