#include "tree.h"

Node::Node(int item) {
    key = item;
    left = right = nullptr;
}

// Warning: This "dumb" destructor deletes all descendant nodes!
// A "smart" function to remove just one node is part of the assignment.
Node::~Node() {
    // Recursively delete left and right children
    delete left;
    delete right;
}

// Recursive function to search a Node's descendants for the value search_key
Node* Node::search(int search_key) {
    // Base case: search_key = this key
    if (search_key == key) {
        return this;
    }

    // search key is greater
    if (search_key > key && right != nullptr) {
        return right->search(search_key);
    }

    // search key is lesser
    if (search_key < key && left != nullptr) {
        return left->search(search_key);
    }

    return nullptr;
}