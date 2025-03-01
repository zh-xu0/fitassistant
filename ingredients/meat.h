#ifndef meat.h
#define meat.h

class meat{
private:
	string name; //ingredient
	float protein, calories;
public:
	void set_all(string n, float c, float p);
	void print_all();
};

void meat::meat(string n, float c, float p) {
	name=n;
	calories=c;
	protein=p;
  }
    //Ingredient meat
    ("Beef", 250.0, 26.0)
    ("Chicken", 165.0, 31.0)
    ("Crab", 82.0, 18.0)
    ("Duck", 337.0, 19.0)
    ("Lamb", 294.0, 25.0)
    ("Pork", 242.0, 22.0)
    ("Salmon", 208.0, 20.0)
    ("Shrimp", 99.0, 24.0)
    ("Turkey", 135.0, 29.0)