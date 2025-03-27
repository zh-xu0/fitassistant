#ifndef BST_H
#define BST_H

#include <iostream>
#include <string>
using namespace std;

struct Node {
    string name;
    double calories;
    Node* left;
    Node* right;

    Node(string n, double c) : name(n), calories(c), left(nullptr), right(nullptr) {}
};

class BST {
private:
    Node* root;
    
    Node* insert(Node* node, string name, double calories) {
        if (!node) return new Node(name, calories);
        if (calories < node->calories)
            node->left = insert(node->left, name, calories);
        else
            node->right = insert(node->right, name, calories);
        return node;
    }

    void searchByCalories(Node* node, double minCalories, double maxCalories) {
        if (!node) return;
        if (node->calories >= minCalories)
            searchByCalories(node->left, minCalories, maxCalories);
        if (node->calories >= minCalories && node->calories <= maxCalories)
            cout << node->name << ": " << node->calories << " calories" << endl;
        if (node->calories <= maxCalories)
            searchByCalories(node->right, minCalories, maxCalories);
    }

public:
    BST() : root(nullptr) {}
    
    void insert(string name, double calories) {
        root = insert(root, name, calories);
    }

    void searchByCalories(double minCalories, double maxCalories) {
        cout << "Ingredients within " << minCalories << " - " << maxCalories << " calories:" << endl;
        searchByCalories(root, minCalories, maxCalories);
    }
};

#endif