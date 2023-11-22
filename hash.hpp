#include <iostream>
#include <list>
#include <string>
#include <sstream>

class Hash {
public:
   int BUCKET; // número de buckets
    // apuntador a la lista que contiene los buckets
    std::list<std::pair<std::string, int> > *table;

    Hash(int V) { // Constructor
        BUCKET = V;
        table = new std::list<std::pair<std::string, int> >[BUCKET];
    }

private:
    // función de hash que calcula la posición en la tabla
    int funcionHash(const std::string& key);

public:
    //Insertar un elemento en la tabla
    void insertaElemento(const std::string& key, int value); 
    void imprimeHash();
    void borraElemento(const std::string& key);

    // These functions are in development and are not part of the initial template.
    int returnValues(const std::string& sentence);
    int get_value(const std::string& key);
    void print_value(const std::string& key); 
};
