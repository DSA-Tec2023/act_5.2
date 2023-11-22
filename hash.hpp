#include <iostream>
#include <fstream>
#include <list>

class Hash{
    public:
    int BUCKET; // número de buckets
    // apuntador a la lista que contiene los buckets
    std::list<int> *table;

     Hash(int V){ // Constructor
        BUCKET = V;
        table = new std::list<int>[BUCKET];
    }

  	private:
    // función de hash que calcula la posición en la tabla
    int funcionHash(int x) {
    //    return (x % BUCKET);
        return (x % BUCKET);
    }
  
  	public:
  	//Insertar un elemento en la tabla
    void insertaElemento(int key){
        int index = funcionHash(key);
        table[index].push_back(key);
    }

    void imprimeHash() { 
      for (int i = 0; i < table->size(); i++) { 
        std::cout << &table[i] << " "; // print with space 
      }
      std::cout << std::endl; 
    }

    void borraElemento(int variable) { // template for now, just so it runs
                                       // to be changed later on 
      std::cout << variable << std::endl; 
    }
}; 
