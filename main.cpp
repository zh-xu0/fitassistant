#include <iostream>
#include <algorithm>
#include "meal.h"
#include "meat.h"
#include "carbs.h"
#include "vegetables.h"

#define SIZE 9 // Fixed macro definition

using namespace std;

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
        {"Bell Peppers", 31.0, 1.0},
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
        {"Brown Rice", 362.0, 7.0},
        {"Egg Noodles", 138.0, 5.0},
        {"Jasmine Rice", 365.0, 7.0},
        {"Oats", 389.0, 16.0},
        {"Spaghetti", 158.0, 6.0},
        {"Udon", 127.0, 3.0}
    };

    // Terminal work FitAssistant
    string action = argv[1];
    cout << "Welcome to Fit Assistant Ver.2" << endl;

    if (action == "meal") {
        //cout << "\nCreating your meal\n";
       // meal(meats, SIZE);
    } else if (action == "order") {
        string order = argv[2];
        string type = argv[3];

        if (order == "ascending") { // Order from lowest to highest
            if (type == "protein") {
                sort(meats, meats + SIZE, [](const meat& a, const meat& b) {
                    return a.get_protein() < b.get_protein();
                });
            } else if (type == "calories") {
                sort(meats, meats + SIZE, [](const meat& a, const meat& b) {
                    return a.get_calories() < b.get_calories();
                });
            } else {
                cout << "Error, wrong type of ingredient input" << endl;
            }
        } else if (order == "descending") {  // Order from highest to lowest
            if (type == "protein") {
                sort(meats, meats + SIZE, [](const meat& a, const meat& b) {
                    return a.get_protein() > b.get_protein();
                });
            } else if (type == "calories") {
                sort(meats, meats + SIZE, [](const meat& a, const meat& b) {
                    return a.get_calories() > b.get_calories();
                });
            } else {
                cout << "Error, wrong type of ingredient input" << endl;
            }
        } else {
            cout << "Error, wrong order input" << endl;
        }
    }

    // Print sorted results
    cout << "\nSorted Ingredients:\n";
    for (int i = 0; i < SIZE; i++) {
        meats[i].print_all();
    }

    delete[] meats;
    delete[] veglist;
    delete[] carblist;

    return 0;
}