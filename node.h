#ifndef NODE_H
#define NODE_H
#include <ctime>

class NODE {
    time_t timestamp;
    double value;
    NODE* nextPtr;
public:
    NODE(time_t t, double c);
    ~NODE();
    void set_next(NODE*);
    NODE* get_next();
    time_t get_time();
    double get_value();
};

typedef NODE* NodePtr;

// Modified constructor
NODE::NODE(time_t t, double c) {
    timestamp = t;
    value = c;
    nextPtr = nullptr;
}

NODE* NODE::get_next() { return nextPtr; }
time_t NODE::get_time() { return timestamp; }
double NODE::get_value() { return value; }
void NODE::set_next(NODE* t) { nextPtr = t; }
NODE::~NODE() {}

#endif