#include "tree.h"

Node::Node(int item) {
    key = item;
    left = right = nullptr;
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