#ifndef nutritions.h
#define nutritions.h

class ingredients{
private:
	string name; //ingredient
	float protein, calories;
public:
	void Attack(monster &);
          void heal();
	monster(string, int,int);
};
#endif


class student {
	private:
	  long id;
	  int age;
	  string name;
	  float gpa;
	public:
	  void set_all(string n, int a, float g);
	  int get_age(); 
	  void print_all();
	};
	
	void student::set_all(string n, int a, float g) {
	  name=n;
	  age=a;
	  gpa=g;
	}



typedef struct {
	char name[50];
	float calories; // per 100g
	float protein;  // per 100g
  } Ingredient;
  
  // Predefined list of ingredients
  Ingredient meat[] = {
	{"Beef", 250.0, 26.0},
	{"Chicken", 165.0, 31.0},
	{"Crab", 82.0, 18.0},
	{"Duck", 337.0, 19.0},
	{"Lamb", 294.0, 25.0},
	{"Pork", 242.0, 22.0},
	{"Salmon", 208.0, 20.0},
	{"Shrimp", 99.0, 24.0},
	{"Turkey", 135.0, 29.0},
  };
  
  Ingredient vegetables[] = {
	{"Basil", 23.0, 3.0},
	{"Bell Peppers", 31.0, 1.0},
	{"Broccoli", 55.0, 3.0},
	{"Carrots", 41.0, 1.0},
	{"Cauliflower", 25.0, 2.0},
	{"Garlic", 149.0, 6.0},
	{"Lettuce", 15.0, 1.0},
	{"Onions", 40.0, 1.0},
	{"Potatoes", 77.0, 2.0},
	{"Tomatoes", 18.0, 1.0},
  };
  
  Ingredient fruits[] = {
	{"Apples", 52.0, 0.0},
	{"Avocado", 160.0, 2.0},
	{"Bananas", 89.0, 1.0},
	{"Blueberries", 57.0, 1.0},
	{"Grapes", 69.0, 0.0},
	{"Mangoes", 60.0, 1.0},
	{"Oranges", 47.0, 1.0},
	{"Peach", 39.0, 1.0},
	{"Pineapple", 50.0, 1.0},
	{"Strawberries", 33.0, 1.0},
	{"Watermelon", 30.0, 1.0},
  };
  
  Ingredient carbs[] = {
	{"Bread", 265.0, 9.0},
	{"Brown Rice", 362.0, 7.0},
	{"Egg Noodles", 138.0, 5.0},
	{"Jasmine Rice", 365.0, 7.0},
	{"Oats", 389.0, 16.0},
	{"Spaghetti", 158.0, 6.0},
	{"Udon", 127.0, 3.0},
  };
  
  Ingredient dairy[] = {
	{"Butter", 717.0, 0.9},
	{"Cheddar", 402.0, 25.0},
	{"Greek Yoghurt", 59.0, 10.0},
	{"Ice Cream", 207.0, 4.0},
	{"Milk", 42.0, 3.4},
	{"Mozzarella", 280.0, 18.0},
	{"Parmesan", 431.0, 38.0},
  };