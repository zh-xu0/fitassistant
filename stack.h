// stack2.h
#ifndef STACK_H
#define STACK_H
#include "node.h"
#include <iostream>
#include <ctime>

class WorkoutStack {
    NodePtr top;
    int size;
public:
    void push(double calories);
    void pop();
    void displayHistory();
    int getStreak();
    WorkoutStack();
    ~WorkoutStack();
    bool isEmpty() { return size == 0; }
};

void WorkoutStack::push(double calories) {
    time_t now = time(nullptr); // Current timestamp
    NodePtr new_node = new NODE(now, calories);
    if (new_node) {
        new_node->set_next(top);
        top = new_node;
        size++;
    }
}

void WorkoutStack::pop() {
    if (!isEmpty()) {
        NodePtr t = top;
        top = t->get_next();
        delete t;
        size--;
    }
}

void WorkoutStack::displayHistory() {
    NodePtr current = top;
    while (current != nullptr) {
        char buffer[80];
        time_t rawtime = current->get_time(); // Store in variable first
        tm* timeinfo = localtime(&rawtime);   // Now take address
        strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", timeinfo);
        std::cout << "[" << buffer << "] Calories burned: " 
                  << current->get_value() << std::endl;
        current = current->get_next();
    }
}

int WorkoutStack::getStreak() {
    // Simplification: Stack size = streak (assuming one workout/day)
    return size;
}

WorkoutStack::WorkoutStack() {
    top = nullptr;
    size = 0;
}

WorkoutStack::~WorkoutStack() {
    while (!isEmpty()) pop();
}

#endif