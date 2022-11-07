/**
 * @file main.cpp
 * @author Evandro Lippert
 * @brief hash table in c++
 * @version 0.1
 * @date 2022-11-07
 * 
 * @copyright Copyright (c) 2022
 * 
 * 
 * @details: Hash table with an linked list for each index
 * from tutorial : https://www.youtube.com/watch?v=oj6YWN4W-jk&
 */


#include <iostream>
#include <cstdlib>
#include <string>

#include "custom_hash.h"

using namespace std;

int main() {

    custom_hash Hashy; // Chama o Construtor e vai criar 10 items 
                      //na hash table com valores empty
                      
    Hashy.PrintTable();
    
    Hashy.AddItem("Evandro", "Capuccino");
    Hashy.AddItem("Evandro", "Cachaça");
    Hashy.AddItem("Silmara", "Café");
    Hashy.AddItem("Sarah", "Suco");
    Hashy.AddItem("Eva", "Chimarrão");
    Hashy.AddItem("André", "Chimarrão");
    Hashy.AddItem("Simião", "Café");
    Hashy.AddItem("Marildete", "Café");
    Hashy.AddItem("Paul", "Locha");
    Hashy.AddItem("Kim", "Mocha");
    Hashy.AddItem("Annie", "Toddy");
    
    Hashy.PrintTable();
    Hashy.PrintItemsInIndex(9);
    Hashy.PrintItemsInIndex(0);
    Hashy.FindDrink("Evandro");
    Hashy.FindDrink("Larry");
    
    Hashy.RemoveItem("Evandro");
    Hashy.PrintItemsInIndex(9);
    Hashy.RemoveItem("Larry");
    
    return 0;
}