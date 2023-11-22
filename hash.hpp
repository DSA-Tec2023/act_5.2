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
    int funcionHash(int x) {
        //    return (x % BUCKET);
        return (x % BUCKET);
    }

public:
    //Insertar un elemento en la tabla
    void insertaElemento(int key) {
        int index = funcionHash(key);
        table[index].push_back(key);
    }

    void imprimeHash() {
        std::cout << "Printing hash table...\n\n";
        for (int i = 0; i < BUCKET; i++) {
            std::cout << i;
            for (auto x : table[i])
                std::cout << " --> " << x;
            std::cout << std::endl;
        }
    }

    void borraElemento(int variable) {
        int index = funcionHash(variable);
        std::list<int>::iterator i;
        for (i = table[index].begin();
                i != table[index].end(); i++) {
            if (*i == variable)
                break;
        }

        if (i != table[index].end())
            table[index].erase(i);
    }

/**
 * @brief This function is _suposed_ to be used to return the values of the words that are found in the sentence. It is not working yet. It is still in development. 
 * 
 * @param sentence 
 * @param word_to_search 
 * @return int 
 */

    int returnValues(std::string sentence, std::string word_to_search[]) {
        std::istringstream iss(sentence);
        int counter = 0;
        do {
            std::string subs;

            // Get the word from the istringstream
            iss >> subs;

            // if word is found in the sentence then increment counter based on the value of the word
            std::cout << subs << std::endl;
            
        } while (iss);
        return counter;
    }
};
