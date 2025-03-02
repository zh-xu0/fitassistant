#ifndef SORT_H
#define SORT_H

#include <iostream>
#include <cstring>
#include "meat.h"
#include "vegetables.h"
#include "carbs.h"


void sortMeats(meat arr[], int size, std::string order, std::string type) {
    bool ascending = (order == "ascending");
    double key_value;

    for (int i = 1; i < size; i++) {
        meat key = arr[i];
        int j = i - 1;

        if (type == "protein") { 
            key_value = key.get_protein();  // If type is "protein"
        }
        else {
            key_value = key.get_calories(); // If type is not "protein"
        }        

        while (j >= 0) {
            double current_value;
        
            if (type == "protein") {
                current_value = arr[j].get_protein();  // If type is "protein"
            }
            else {
                current_value = arr[j].get_calories(); // If type is not "protein"
            }

            if ((ascending && current_value > key_value) || (!ascending && current_value < key_value)) {
                arr[j + 1] = arr[j];  // Shift element
                j--;
            } else {
                break;
            }
        }
        arr[j + 1] = key;
    }
}

// Sorting function for vegetables
void sortVegetables(vegetables arr[], int size, std::string order, std::string type) {
    bool ascending = (order == "ascending");
    double key_value;

    for (int i = 1; i < size; i++) {
        vegetables key = arr[i];
        int j = i - 1;

        if (type == "protein") { 
            key_value = key.get_protein();  // If type is "protein"
        }
        else {
            key_value = key.get_calories(); // If type is not "protein"
        }        

        while (j >= 0) {
            double current_value;
        
            if (type == "protein") {
                current_value = arr[j].get_protein();  // If type is "protein"
            }
            else {
                current_value = arr[j].get_calories(); // If type is not "protein"
            }

            if ((ascending && current_value > key_value) || (!ascending && current_value < key_value)) {
                arr[j + 1] = arr[j];
                j--;
            } else {
                break;
            }
        }
        arr[j + 1] = key;
    }
}


// Sorting function for carbs
void sortCarbs(carbs arr[], int size, std::string order, std::string type) {
    bool ascending = (order == "ascending");
    double key_value;

    for (int i = 1; i < size; i++) {
        carbs key = arr[i];
        int j = i - 1;

        // Choose sorting criteria

        if (type == "protein") {
            key_value = key.get_protein();  // If type is "protein"
        }
        else {
            key_value = key.get_calories(); // If type is not "protein"
        }        

        while (j >= 0) {
            double current_value;
        
            if (type == "protein") {
                current_value = arr[j].get_protein();  // If type is "protein"
            }
            else {
                current_value = arr[j].get_calories(); // If type is not "protein"
            }        

            // Check if we need to swap
            if ((ascending && current_value > key_value) || (!ascending && current_value < key_value)) {
                arr[j + 1] = arr[j];  // Shift element to the right
                j--;
            } else {
                break;  // Stop shifting when order is correct
            }
        }
        arr[j + 1] = key;  // Insert element in the correct position
    }
}


#endif