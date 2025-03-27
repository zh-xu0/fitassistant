#include <iostream>
#include <sstream>

using namespace std;

#include "meal.h"
#include "meat.h"
#include "carbs.h"
#include "vegetables.h"
#include "insertion.h"
#include "functions.h"
#include "stack.h"
#include "node.h"
#include "BST.h"

#define SIZE 9


int main(int argc, char* argv[]) {
    meat* meats = new meat[SIZE]{
        {"Beef", 250.0, 26.0},
        {"Chicken", 165.0, 31.0},
        {"Crab", 82.0, 18.0},
        {"Duck", 337.0, 19.0},
        {"Lamb", 294.0, 25.0},
        {"Pork", 242.0, 22.0},
        {"Salmon", 208.0, 20.0},
        {"Shrimp", 99.0, 24.0},
        {"Turkey", 135.0, 29.0}
    };

    vegetables* veglist = new vegetables[SIZE]{
        {"Basil", 23.0, 3.0},
        {"Bell_Peppers", 31.0, 1.0},
        {"Broccoli", 55.0, 3.0},
        {"Carrots", 41.0, 1.0},
        {"Cauliflower", 25.0, 2.0},
        {"Garlic", 149.0, 6.0},
        {"Lettuce", 15.0, 1.0},
        {"Potatoes", 77.0, 2.0},
        {"Tomatoes", 18.0, 1.0}
    };

    carbs* carblist = new carbs[SIZE]{
        {"Bread", 265.0, 9.0},
        {"Brown_Rice", 362.0, 7.0},
        {"Egg_Noodles", 138.0, 5.0},
        {"Jasmine_Rice", 365.0, 7.0},
        {"Oats", 389.0, 16.0},
        {"Pasta", 158.0, 6.0},
        {"Udon", 127.0, 3.0},
        {"White_Rice", 350.0, 6.0},
        {"Black_Rice", 365.5, 8.0}
    };

    // Terminal work FitAssistant
    string action = argv[1];
    cout << "Welcome to Fit Assistant -Ver.2-  Ver.3!!" << endl;

    if (action == "meal") {
        createMeal(argc, argv, meats, SIZE, carblist, SIZE, veglist, SIZE);
    
        // Find the selected ingredients
        string meat_choice = argv[2];
        string carb_choice = argv[4];
        string veg_choice = argv[6];
    
        int meatQty = stoi(argv[3]) * 100;
        int carbQty = stoi(argv[5]) * 100;
        int vegQty = stoi(argv[7]) * 100;
    
        meat selectedMeat;
        carbs selectedCarb;
        vegetables selectedVeg;
    
        for (int i = 0; i < SIZE; i++) {
            if (meats[i].get_name() == meat_choice) {
                selectedMeat = meats[i];
                break;
            }
        }
    
        for (int i = 0; i < SIZE; i++) {
            if (carblist[i].get_name() == carb_choice) {
                selectedCarb = carblist[i];
                break;
            }
        }
    
        for (int i = 0; i < SIZE; i++) {
            if (veglist[i].get_name() == veg_choice) {
                selectedVeg = veglist[i];
                break;
            }
        }
    
        // Calculate initial totals
        double total_protein = (meatQty / 100.0) * selectedMeat.get_protein() +
                               (carbQty / 100.0) * selectedCarb.get_protein() +
                               (vegQty / 100.0) * selectedVeg.get_protein();
    
        double total_calories = (meatQty / 100.0) * selectedMeat.get_calories() +
                                (carbQty / 100.0) * selectedCarb.get_calories() +
                                (vegQty / 100.0) * selectedVeg.get_calories();
    
        // Allow the user to increase portion sizes
        increasePortion(selectedMeat, selectedCarb, selectedVeg, meatQty, carbQty, vegQty, total_protein, total_calories);

    } else if (action == "order") {
        string order = argv[2];
        string type = argv[3];

        if (order == "ascending") { // Order from lowest to highest
            if (type == "protein") {
                sortMeats(meats, SIZE, order, type);
                sortVegetables(veglist, SIZE, order, type);
                sortCarbs(carblist, SIZE, order, type);
            } else if (type == "calories") {
                sortMeats(meats, SIZE, order, type);
                sortVegetables(veglist, SIZE, order, type);
                sortCarbs(carblist, SIZE, order, type);
            } else {
                cout << "Error, wrong type of ingredient input" << endl;
            }
        } else if (order == "descending") {  // Order from highest to lowest
            if (type == "protein") {
                sortMeats(meats, SIZE, order, type);
                sortVegetables(veglist, SIZE, order, type);
                sortCarbs(carblist, SIZE, order, type);
            } else if (type == "calories") {
                sortMeats(meats, SIZE, order, type);
                sortVegetables(veglist, SIZE, order, type);
                sortCarbs(carblist, SIZE, order, type);
            } else {
                cout << "Error, wrong type of ingredient input" << endl;
            }
        } else {
            cout << "Error, wrong order input" << endl;
        }
    }else if (action == "workout") { // Workout section
        WorkoutStack workoutHistory;
        string input;
        int choice = -1;
        
        cout << "\n=== Workout Tracker ===" << endl;
        cout << "1. Add workout\n2. Undo last\n3. View history\n0. Exit\n" << endl;

        while(true) {
            cout << "Enter choice: ";
            getline(cin, input);
            stringstream ss(input);
            ss >> choice;

            if(choice == 0) {
                cout << "Exiting workout tracker..." << endl;
                break;
            }

            switch(choice) {
                case 1: { // Add workout
                    double calories;
                    cout << "Enter calories burned: ";
                    getline(cin, input);
                    try {
                        calories = stod(input);
                        workoutHistory.push(calories);
                        cout << "Added: " << calories << " calories" << endl;
                    } catch(...) {
                        cout << "Invalid input! Use numbers only." << endl;
                    }
                    break;
                }
                case 2: // Undo
                    if(!workoutHistory.isEmpty()) {
                        workoutHistory.pop();
                        cout << "Undid last workout entry" << endl;
                    } else {
                        cout << "History is already empty!" << endl;
                    }
                    break;
                case 3: // History
                    cout << "\n=== Workout History (" << workoutHistory.getStreak() << " workout streak) ===" << endl;
                    workoutHistory.displayHistory();
                    cout << endl;
                    break;
                default:
                    cout << "Invalid choice! Valid options: 0-3" << endl;
            }
        }
        return 0;
    }else if (action == "search") {
        BST bst;
        for (int i = 0; i < SIZE; i++) {
            bst.insert(meats[i].get_name(), meats[i].get_calories());
            bst.insert(veglist[i].get_name(), veglist[i].get_calories());
            bst.insert(carblist[i].get_name(), carblist[i].get_calories());
        }
        double minCalories = stod(argv[2]);
        double maxCalories = stod(argv[3]);
        bst.searchByCalories(minCalories, maxCalories);
        }
    

     // Print sorted results
     if (action == "order"){
     cout << "\nSorted Meats:\n";
     for (int i = 0; i < SIZE; i++) {
         meats[i].print_all();
     }
 
     cout << "\nSorted Vegetables:\n";
     for (int i = 0; i < SIZE; i++) {
         veglist[i].print_all();
     }
 
     cout << "\nSorted Carbs:\n";
     for (int i = 0; i < SIZE; i++) {
         carblist[i].print_all();
     }
    }

    delete[] meats;
    delete[] veglist;
    delete[] carblist;

    return 0;
}