#ifndef MEAT_H
#define MEAT_H

#include <iostream>
#include <string>

class meat {
private:
    std::string name; // ingredient
    float protein, calories;
public:
    // Constructor
    meat(std::string n = "", float c = 0.0, float p = 0.0) : name(n), calories(c), protein(p) {}

    // Getter functions
    float get_calories() const { return calories; }
    float get_protein() const { return protein; }
    std::string get_name() const { return name; }

    // Display function
    void print_all() {
        std::cout << "Name: " << name << ", Calories: " << calories << ", Protein: " << protein << std::endl;
    }
};

#endif
