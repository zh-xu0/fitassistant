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

  //Ingredient carbs
  ("Bread", 265.0, 9.0)
  ("Brown Rice", 362.0, 7.0)
  ("Egg Noodles", 138.0, 5.0)
  ("Jasmine Rice", 365.0, 7.0)
  ("Oats", 389.0, 16.0)
  ("Spaghetti", 158.0, 6.0)
  ("Udon", 127.0, 3.0)