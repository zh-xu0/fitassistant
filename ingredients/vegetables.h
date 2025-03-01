#ifndef vegetables.h
#define vegetables.h

class vegetables{
private:
	string name; //ingredient
	float protein, calories;
public:
	void set_all(string n, float c, float p);
	void print_all();
};

void vegetables::vegetables(string n, float c, float p) {
	name=n;
	calories=c;
	protein=p;
  }
  //Ingredient vegetables
  ("Basil", 23.0, 3.0)
  ("Bell Peppers", 31.0, 1.0)
  ("Broccoli", 55.0, 3.0)
  ("Carrots", 41.0, 1.0)
  ("Cauliflower", 25.0, 2.0)
  ("Garlic", 149.0, 6.0)
  ("Lettuce", 15.0, 1.0)
  ("Onions", 40.0, 1.0)
  ("Potatoes", 77.0, 2.0)
  ("Tomatoes", 18.0, 1.0)