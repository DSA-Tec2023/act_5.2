#include "hash.hpp"
#include <fstream>
#include <iostream>

// Private functions

int Hash::funcionHash(const std::string& key) {
// A simple hash function for strings
    int sum = 0;
    for (char ch : key) {
        sum += static_cast<int>(ch); // Convert char to int and add to sum in order to get the sum of all chars in the string
    }
    return sum % BUCKET; // Return the sum of all chars in the string modulo the number of buckets, in order to get the index of the bucket

}

// Public functions
void Hash::insertaElemento(const std::string& key, int value) {
    int index = funcionHash(key);
    table[index].push_back(std::make_pair(key, value));
}

void Hash::imprimeHash() {
    std::cout << "Printing hash table...\n\n";
    for (int i = 0; i < BUCKET; i++) {
        std::cout << i;
        for (auto pair : table[i])
            std::cout << " --> " << pair.first << ":" << pair.second;
        std::cout << std::endl;
    }
}

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
            std::cout << subs << std::endl;
            counter += value;
        }

    } while (iss);
    return counter;
}

/**
 * @brief This function returns the value of a key in the hash table.
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
    return 0; // Return 0 if key is not found
}

/**
 * @brief This function prints the value of a key in the hash table.
 *
 * @param key
 */

void Hash::print_value(const std::string& key) {
    int val = get_value(key);
    if (val != 0) {
        std::cout << "Value of key " << key << ": " << val << std::endl;
    } else {
        std::cout << "Key not found." << std::endl;
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
    // first line is: the number of buckets and the sentences to be processed, separated by a space
    std::getline(file, line);
    std::istringstream iss(line);
    iss >> BUCKET;
    std::string sentence;
    iss >> sentence;

    std::cout << "Sentence: "  << sentence << std::endl;

    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string key;
            int value;
            iss >> key >> value;
            insertaElemento(key, value);
        }
        file.close();
    } else {
        std::cout << "Unable to open file: " << filename << std::endl;
    }
}