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