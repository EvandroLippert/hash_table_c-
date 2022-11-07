#include <iostream>
#include <cstdlib>
#include <string>

#include "custom_hash.h"

using namespace std;


// Construtor
custom_hash::custom_hash() {
    
    for(int i = 0; i < tableSize; i++) {
        
        HashTable[i] = new item;
        HashTable[i] -> name = "empty";
        HashTable[i] -> favoriteDrink = "empty";
        HashTable[i] -> next = NULL;
    }
}

void custom_hash::AddItem(string name, string favoriteDrink) {
    int index = Hash(name);
    if (HashTable[index] -> name == "empty") {
        HashTable[index] -> name = name;
        HashTable[index] -> favoriteDrink = favoriteDrink;
    } else {
        item* Ptr = HashTable[index];
        item* n = new item;
        
        n -> name = name;
        n -> favoriteDrink = favoriteDrink;
        n -> next = NULL;
        while (Ptr->next != NULL) { //Enquanto o próximo ponteiro não for null
            Ptr = Ptr->next; // O Ponteiro seguinte é atribuído ao atual
        }
        
        Ptr->next = n; // Quando o próximo ponteiro for null, adicionamos o novo item
                    // ligando ao, agora, penúltimo ponteiro
    } 

}


int custom_hash::NumberOfItemsInIndex(int index) {
    int count = 0;
    
    if(HashTable[index]->name == "empty") {
        return count;
    } else {
        count++;
        item* Ptr = HashTable[index];
        while(Ptr->next != NULL){
            count++;
            Ptr = Ptr->next;
        }
    
        return count;
    }
}

void custom_hash::PrintTable() {
    int number;
    for(int i=0; i< tableSize; i++) {
        number = NumberOfItemsInIndex(i);
        cout << "----------------------------------------\n";
        cout << "Index = " << i <<endl;
        cout << "Name: " << HashTable[i]->name << endl;
        cout << "Favorite Drink: " << HashTable[i]->favoriteDrink << endl;
        cout << "# of items " << number << endl;
        cout << "----------------------------------------\n";
    }
}

void custom_hash::PrintItemsInIndex(int index){
    int numberOfItems = NumberOfItemsInIndex(index);
    
    if (index == 0) {
        cout << "No item at index " << index << endl;
    } else {
        cout << "Index = " << index << " contains the following items\n";
        item* Ptr = HashTable[index];
        while (Ptr->next != NULL) {
            cout << "----------------------------------------\n";
            cout << "Name: " << Ptr -> name << endl;
            cout << "Favorite Drink: " << Ptr -> favoriteDrink << endl;
            cout << "----------------------------------------\n";
            Ptr = Ptr -> next;
        }
    }
}

void custom_hash::FindDrink(string name){
    
    int index = Hash(name);
    
    int numberOfItems = NumberOfItemsInIndex(index);
    
    if (numberOfItems == 0) {
        cout << "No items at index " << index << endl;
    } else { 
        item * Ptr = HashTable[index];
        while(Ptr -> next != NULL) {
            if(Ptr -> name == name) {
                cout << name << "'s favorite drink is " << Ptr->favoriteDrink << endl;
                return;
            }
            
        }
        cout << name << " is not in our Hash Table"<< endl;
    }
}

void custom_hash::RemoveItem(string name){
    int index = Hash(name);
    
    item* delPtr;
    item* P1;
    item* P2;
    
    // Case 0 - bucket is empty
    cout << "INDEX TO REMOVE = " <<index <<endl;
    if (NumberOfItemsInIndex(index) == 0) {
        cout << "No items to remove at this index" << endl;
    }
    
    // Case 1 - only 1 item in the bucket and that item has matching name;
    else if (HashTable[index] -> name == name && HashTable[index] -> next == NULL){
        
        HashTable[index] -> name = "empty";
        HashTable[index] -> favoriteDrink = "empty";
        
        cout << name << " was removed from the Hash Table\n";
    
    }
    // Case 2 - match the first item, but there are more items in bucket;
    else if (HashTable[index] -> name == name){
        
        delPtr = HashTable[index];
        HashTable[index] = HashTable[index]->next;
        delete delPtr;
        
        cout << name << " was removed from the Hash Table\n";
    
    } 
    // Case 3 - match is not in the first item:
    else {
        
        
        P1 = HashTable[index] -> next;
        P2 = HashTable[index];
        
        cout << "P1 VALUE: " << P1 << endl;
        
        while (P1 != NULL & P1-> name != name){
            cout << "NO WHILE LOOPING"<<endl;
            P2 = P1;
            P1 = P1->next;
        } if (P1 == NULL) {
            // Case 3.1 - No Match;
            cout << name << " was not found in the Hash Table\n";
        } else {
            // Case 3.2 - Match is found;
            delPtr = P1;
            P1 = P1 -> next;
            P2 -> next = P1;
            delete delPtr;
            cout << name << " was removed from the Hash Table\n";
        }
    }

}

int custom_hash::Hash(string key) { // Função para calcular o index da hash table 
                                    // baseado na key (Aceita keys repetidas)

    int hash = 0;
    int index;
    
    for(int i = 0; i < key.length(); i++) {
        hash = hash + (int)key[i];
    }

    index = hash % tableSize;

    return index;

}
