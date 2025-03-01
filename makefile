DEPS=FitAssitant
compile: main.cpp 
	 g++ main.cpp -o $(DEPS)

run: $(DEPS)
	 ./$(DEPS)

clean: $(DEPS)
	 rm $(DEPS)

ingredients: main-lab.cpp 
	./$(DEPS) Beef 250.0 26.0
	Chicken 165.0 31.0
	Crab 82.0 18.0
	Duck 337.0 19.0
	Lamb 294.0 25.0
	Pork 242.0 22.0
	Salmon 208.0 20.0
	Shrimp 99.0 24.0
	Turkey 135.0 29.0