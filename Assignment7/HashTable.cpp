
#include <iostream>
#include <cmath>
#include <chrono>
#include "HashTable.h"

HashTable::HashTable(int size) {
    hashSize = size;
    array = new node[hashSize];
    for (int i = 0; i < hashSize; i++) {
        array[i].next = nullptr; //array[i] holds a pointer of type node, set to nullptr
    }
}

int HashTable::hashFunction(Word word) {
    std::string text = word.getWord();
    int sum = 0;
    for (int i = 0; i < text.length(); i++) {
        sum = (sum * 101) + int(text[i]); //prime numbers are great for hash functions
    }
    return (std::abs(sum % hashSize));
}

void HashTable::insertWord(Word word) {
    int index = hashFunction(word);
    node *nodeOne = new node, *nodeTwo = nullptr;
    nodeOne->value = word;
    nodeOne->next = nullptr;

    //if array[i] does not point to an existing node
    if (array[index].next == nullptr) {
        array[index].next = nodeOne;
    }
    //if there is an existing node, traverse linked list and add at the end
    else {
        nodeTwo = array[index].next;
        while (nodeTwo->next != nullptr) {
            nodeTwo = nodeTwo->next;
        }

        nodeTwo->next = nodeOne;
    }
}

int HashTable::searchWord(Word word) {
    int index = hashFunction(word);
    auto start = std::chrono::high_resolution_clock::now();

    if (array[index].next->value.getWord() == word.getWord()) { //if word found at first node

        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = duration_cast<std::chrono::microseconds>(stop - start);
        std::cout << "\nDuration: " << duration.count() << std::endl;

        return index;
    }
    else { //if word is not at first node, traverse linked list until node is found

        node *traverse = array[index].next;
        while (traverse != nullptr) {

            if (traverse->value.getWord() == word.getWord()) {

                auto stop = std::chrono::high_resolution_clock::now();
                auto duration = duration_cast<std::chrono::microseconds>(stop - start);
                std::cout << "\nDuration: " << duration.count() << std::endl;

                return index;
            } //end if

            traverse = traverse->next;
        } //end while
    } //end else

    return -1; //return -1 if word is never found
}




