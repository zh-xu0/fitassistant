#ifndef CARBS_H
#define CARBS_H

#include <iostream>
#include <string>

class carbs {
private:
    string name;
    float protein, calories;
public:
    carbs(string n = "", float c = 0.0, float p = 0.0) : name(n), calories(c), protein(p) {}

    float get_calories() const { return calories; }
    float get_protein() const { return protein; }
    string get_name() const { return name; }

    void print_all() {
        cout << "Name: " << name << ", Calories: " << calories << ", Protein: " << protein << endl;
    }

    carbs operator+(int portionIncrease) {
        float newCalories = this->calories + (portionIncrease / 100.0) * this->calories;
        float newProtein = this->protein + (portionIncrease / 100.0) * this->protein;
        return carbs(this->name, newCalories, newProtein);
    }
};

#endif
