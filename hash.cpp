#include "hash.hpp"

// Private functions

int Hash::funcionHash(const std::string& key) {
// A simple hash function for strings
    int sum = 0;
    for (char ch : key) {
        sum += static_cast<int>(ch);
    }
    return sum % BUCKET;

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

void Hash::print_value(const std::string& key) {
    for (int i = 0; i < BUCKET; i++) {
        for (auto pair : table[i]) {
            if (pair.first == key) {
                std::cout << pair.first << " has the value of " << pair.second << std::endl;
            }
        }
    }
}