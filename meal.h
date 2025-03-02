#ifndef MEAL_H
#define MEAL_H

#include <iostream>
#include <string>
#include <cstdlib>
#include "meat.h"
#include "carbs.h"
#include "vegetables.h"

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

void increasePortion(meat& m, carbs& c, vegetables& v, int& meatQty, int& carbQty, int& vegQty, double& total_protein, double& total_calories) {
    string choice;
    int portionIncrease = 100; // Increase by 100g

    while (true) {
        cout << "Do you want to increase the portion size of an ingredient? (yes/no): ";
        cin >> choice;

        if (choice == "yes") {
            cout << "Which ingredient do you want to increase? (meat/carbs/vegetables): ";
            string ingredient;
            cin >> ingredient;

            if (ingredient == "meat") {
                meatQty += portionIncrease;
                total_protein += (portionIncrease / 100.0) * m.get_protein();
                total_calories += (portionIncrease / 100.0) * m.get_calories();
                cout << "Increased meat portion by 100g. New portion size: " << meatQty << "g" << endl;
            } else if (ingredient == "carbs") {
                carbQty += portionIncrease;
                total_protein += (portionIncrease / 100.0) * c.get_protein();
                total_calories += (portionIncrease / 100.0) * c.get_calories();
                cout << "Increased carbs portion by 100g. New portion size: " << carbQty << "g" << endl;
            } else if (ingredient == "vegetables") {
                vegQty += portionIncrease;
                total_protein += (portionIncrease / 100.0) * v.get_protein();
                total_calories += (portionIncrease / 100.0) * v.get_calories();
                cout << "Increased vegetables portion by 100g. New portion size: " << vegQty << "g" << endl;
            } else {
                cout << "Invalid ingredient choice. Please try again." << endl;
            }

            // Print updated totals
            cout << "\nUpdated Meal Macronutrients:" << endl;
            cout << "Total Protein: " << total_protein << "g" << endl;
            cout << "Total Calories: " << total_calories << " kcal" << endl;
        } else if (choice == "no") {
            break;
        } else {
            cout << "Invalid input. Please enter 'yes' or 'no'." << endl;
        }
    }
}

#endif
