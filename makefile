DEPS=FitAssitant
compile: main.cpp 
	 g++ main.cpp -o $(DEPS)

run: $(DEPS)
	 ./$(DEPS)

clean: $(DEPS)
	 rm $(DEPS)

AscProt: main.cpp
	./$(DEPS) order ascending protein

DesProt: main.cpp
	./$(DEPS) order descending protein

AscCal: main.cpp
	./$(DEPS) order ascending calories

DesCal: main.cpp
	./$(DEPS) order descending calories

meal1: main.cpp
	./$(DEPS) meal Beef 3 Pasta 5 Broccoli 2

meal2: main.cpp
	./$(DEPS) meal beef 3 Pastas 5 Brocoli 2

meal3: main.cpp
	./$(DEPS) meal Chicken 5 Potatoes 6 Lettuce 7

meal4: main.cpp
	./$(DEPS) meal Salmon 1 Egg_Noodles 3 Tomatoes 9

meal5: main.cpp
	./$(DEPS) meal Crab 9 Jasmine_Rice 1 Cauliflower 3
