#ifndef MEAL_H
#define MEAL_H

#include <iostream>
#include <string>
#include <cstdlib> // for std::stoi
#include "meat.h"
#include "carbs.h"
#include "vegetables.h"

using namespace std;

// Function to create a meal from user input
void createMeal(int argc, char* argv[], meat meats[], int meatSize, carbs carblist[], int carbSize, vegetables veglist[], int vegSize) {

    string meat_choice = argv[2];
    int meat_qty = stoi(argv[3]) * 100;  // Convert to grams

    string carb_choice = argv[4];
    int carb_qty = stoi(argv[5]) * 100;

    string veg_choice = argv[6];
    int veg_qty = stoi(argv[7]) * 100;

    // Variables to store macros
    double total_protein = 0;
    double total_calories = 0;

    int failcheck = 0;  // Fail check mechanism to detect wrong input and thus wrong results
    // Find and process meat
    for (int i = 0; i < meatSize; i++) {
        if (meats[i].get_name() == meat_choice) {
            total_protein += (meat_qty / 100.0) * meats[i].get_protein();
            total_calories += (meat_qty / 100.0) * meats[i].get_calories();
            failcheck++;
            break;
        }
    }
    if (failcheck==0){cout<<"wrong meat input"<<endl;} // Fail check mechanism to detect wrong input and thus wrong results
    failcheck = 0;
    // Find and process carb
    for (int i = 0; i < carbSize; i++) {
        if (carblist[i].get_name() == carb_choice) {
            total_protein += (carb_qty / 100.0) * carblist[i].get_protein();
            total_calories += (carb_qty / 100.0) * carblist[i].get_calories();
            failcheck++;
            break;
        }
    }
    if (failcheck==0){cout<<"wrong carb input"<<endl;} // Fail check mechanism to detect wrong input and thus wrong results
    failcheck = 0;
    // Find and process vegetable
    for (int i = 0; i < vegSize; i++) {
        if (veglist[i].get_name() == veg_choice) {
            total_protein += (veg_qty / 100.0) * veglist[i].get_protein();
            total_calories += (veg_qty / 100.0) * veglist[i].get_calories();
            failcheck++;
            break;
        }
    }
    if (failcheck==0){cout<<"wrong vegetable input"<<endl;}  // Fail check mechanism to detect wrong input and thus wrong results
    
    // Output the meal summary
    cout << "==== Meal ====" << endl;
    cout << "Meat choice: " << meat_choice << endl;
    cout << "Portion: " << meat_qty << "g" << endl;
    cout << "Carbs choice: " << carb_choice << endl;
    cout << "Portion: " << carb_qty << "g" << endl;
    cout << "Vegetable choice: " << veg_choice << endl;
    cout << "Portion: " << veg_qty << "g" << endl;
    cout << "===================" << endl;
    cout << "Total Macronutrients:" << endl;
    cout << "Protein: " << total_protein << "g" << endl;
    cout << "Calories: " << total_calories << " kcal" << endl;
}

#endif
