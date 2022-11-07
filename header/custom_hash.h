#include <iostream>
#include <cstdlib>
#include <string>


using namespace std;

#ifndef CUSTOM_HASH_H
#define CUSTOM_HASH_H


class custom_hash{
    private:
        static const int tableSize = 10;
        
        struct item {
          string name;
          string favoriteDrink;
          item* next;
        };
        
        item* HashTable[tableSize];
    
    public:
        custom_hash(); //construtor precisa ter o mesmo nome da classe
        int Hash(string key); // retorna o index para ser armazenado a chave-valor
        void AddItem(string name, string favoriteDrink);
        int NumberOfItemsInIndex(int index);
        void PrintTable();
        void PrintItemsInIndex(int index);
        void FindDrink(string name);
        void RemoveItem(string name);
};

#endif