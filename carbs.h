#ifndef CARBS_H
#define CARBS_H

#include <iostream>
#include <string>

class carbs {
private:
    std::string name;
    float protein, calories;
public:
    carbs(std::string n = "", float c = 0.0, float p = 0.0) : name(n), calories(c), protein(p) {}

    float get_calories() const { return calories; }
    float get_protein() const { return protein; }
    std::string get_name() const { return name; }

    void print_all() {
        std::cout << "Name: " << name << ", Calories: " << calories << ", Protein: " << protein << std::endl;
    }
};

#endif
