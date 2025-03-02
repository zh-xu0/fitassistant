#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>  
using namespace std;

template <typename T>
void display(T a[], int n) {
    for (int i = 0; i < n; i++)
        cout << a[i].get_name() << " (" << a[i].get_protein() << "g protein)  ";
    cout << endl;
}

// Swap function for objects
template <typename T>
void swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

#endif // FUNCTIONS_H
