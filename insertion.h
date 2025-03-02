#ifndef SORT_H
#define SORT_H

#include <iostream>
#include "meat.h"
#include "vegetables.h"
#include "carbs.h"

void sortMeats(meat arr[], int size, std::string order, std::string type) {
    bool ascending = (order == "ascending");

    for (int i = 1; i < size; i++) {
        meat key = arr[i];
        int j = i - 1;

        double key_value = (type == "protein") ? key.get_protein() : key.get_calories();

        while (j >= 0) {
            double current_value = (type == "protein") ? arr[j].get_protein() : arr[j].get_calories();

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

    for (int i = 1; i < size; i++) {
        vegetables key = arr[i];
        int j = i - 1;

        double key_value = (type == "protein") ? key.get_protein() : key.get_calories();

        while (j >= 0) {
            double current_value = (type == "protein") ? arr[j].get_protein() : arr[j].get_calories();

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

    for (int i = 1; i < size; i++) {
        carbs key = arr[i];
        int j = i - 1;

        // Choose sorting criteria
        double key_value = (type == "protein") ? key.get_protein() : key.get_calories();

        while (j >= 0) {
            double current_value = (type == "protein") ? arr[j].get_protein() : arr[j].get_calories();

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