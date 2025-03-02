#ifndef MEAT_H
#define MEAT_H

#include <iostream>
#include <string>

class meat {
private:
    string name; // ingredient
    float protein, calories;
public:
    // Constructor
    meat(string n = "", float c = 0.0, float p = 0.0) : name(n), calories(c), protein(p) {}

    // Getter functions
    float get_calories() const { return calories; }
    float get_protein() const { return protein; }
    string get_name() const { return name; }

    // Display function
    void print_all() {
        cout << "Name: " << name << ", Calories: " << calories << ", Protein: " << protein << endl;
    }

    meat operator+(int portionIncrease) {
        float newCalories = this->calories + (portionIncrease / 100.0) * this->calories;
        float newProtein = this->protein + (portionIncrease / 100.0) * this->protein;
        return meat(this->name, newCalories, newProtein);
    }
};

#endif
