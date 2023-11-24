#include "hash.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

// Private functions

int Hash::funcionHash(const std::string& key) {
// A simple hash function for strings
    int sum = 0;
    for (char ch : key) {
        sum += static_cast<int>(ch); 

        // Convierte char a int y agrega a la suma para obtener la suma de todos los caracteres en la cadena
    }
    return sum % BUCKET; 
    // Regresa el valor de la suma de todos los caracteres en la cadena modulo el número de buckets, para obtener el índice del bucket

}

// Public functions
void Hash::insertaElemento(const std::string& key, int value) {
    int index = funcionHash(key);
    table[index].push_back(std::make_pair(key, value));
}

void Hash::imprimeHash() {
    std::cout << "Printeando Tabla Hash...\n\n";
    for (int i = 0; i < BUCKET; i++) {
        std::cout << i;
        for (auto pair : table[i])
            std::cout << " --> " << pair.first << ":" << pair.second;
        std::cout << std::endl;
    }
}

/**
 * @brief Ésta función borra un elemento de la tabla hash, dado su key.
 * 
 * @param key 
 */
void Hash::borraElemento(const std::string& key) {
    int index = funcionHash(key);
    std::list<std::pair<std::string, int> >::iterator i;
    for (i = table[index].begin(); i != table[index].end(); i++) {
        if (i->first == key)
            break;
    }

    if (i != table[index].end())
        table[index].erase(i);
}

int Hash::returnValues(const std::string& sentence) {
    std::istringstream iss(sentence);
    int counter = 0;
    do {
        std::string subs;
        iss >> subs;
        int value = get_value(subs);
        if (value != 0) { // Check if value is not 0
            counter += value;
        }

    } while (iss);
    return counter;
}

/**
 * @brief Esta función regresa el valor de una key en la tabla hash.
 *
 * @param key
 * @return int
 */

int Hash::get_value(const std::string& key) {
    for (int i = 0; i < BUCKET; i++) {
        for (auto pair : table[i]) {
            if (pair.first == key) {
                return pair.second;
            }
        }
    }
    return 0; // Regresa 0 si no encuentra la key en la tabla hash.
}

/**
 * @brief Esta función printea un valor dependiendo de su clave o key.
 *
 * @param key
 */

void Hash::print_value(const std::string& key) {
    int val = get_value(key);
    if (val != 0) {
        std::cout << "El valor de la clave " << key << ": " << val << std::endl;
    } else {
        std::cout << "Clave no encontrada." << std::endl;
    }
}

/**
 * @brief Reads a file and inserts the keys and values into the hash table.
 *
 * @param filename
 */

void Hash::read_file(const std::string& filename) {
    std::ifstream file(filename);
    std::string line;
    std::getline(file, line);
    std::istringstream iss(line);
    int n, sentenceNo;

    iss >> n;
    iss >> sentenceNo;

    for (int i = 0; i < n; i++) {
        std::getline(file, line);
        std::istringstream iss(line);
        std::string key;
        int value;
        iss >> key >> value;
        insertaElemento(key, value);
    }

    for (int i = 0; i < sentenceNo; i++) {
        int contador = 0;
        while (std::getline(file, line) && line != ".") {
            std::istringstream iss(line);
            std::string sentence;
            std::getline(iss, sentence);
            contador += returnValues(sentence);
        }
        std::cout << contador << std::endl;
        contador = 0;
    }
}