#include "hash.hpp"

// Private functions

int Hash::funcionHash(int x) {
    return (x % BUCKET);
}

// Public functions

void Hash::insertaElemento(int key) {
    int index = funcionHash(key);
    table[index].push_back(key);
}

void Hash::imprimeHash() {
    std::cout << "Printing hash table...\n\n";
    for (int i = 0; i < BUCKET; i++) {
        std::cout << i;
        for (auto x : table[i])
            std::cout << " --> " << x;
        std::cout << std::endl;
    }
}

void Hash::borraElemento(int variable) {
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

int Hash::returnValues(std::string sentence, std::string word_to_search[]) {
    std::istringstream iss(sentence);
    int counter = 0;
    do {
        std::string subs;

        // Get the word from the istringstream
        iss >> subs;

        int value = get_value(std::hash<std::string>()(subs));

        // If the value is not zero, print the word and add its value to the counter
        if (value != 0) {
            std::cout << subs << std::endl;
            counter += value;
        }

    } while (iss);
    return counter;
}

int Hash::get_value(int key) {
    int index = funcionHash(key);
    std::list<int>::iterator i;
    for (i = table[index].begin();
            i != table[index].end(); i++) {
        if (*i == key)
            break;
    }

    if (i != table[index].end())
        std::cout << *i << std::endl;
    else
        std::cout << "No se encontró el valor" << std::endl;
}