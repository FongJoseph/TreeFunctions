#include <iostream>
#include "tree.h"
using namespace std;

int main() {
    char* hello_string = "Hello, World!";

    Node* hello_root = new Node((int)hello_string[0]);
    Node* hello_current = hello_root;

    for (int i = 1; hello_string[i] != '\0'; i++) {
        hello_current->right = new Node((int)hello_string[i]);
        hello_current = hello_current->right;
    }

    hello_current = hello_root;
    while (hello_current != nullptr) {
        cout << (char)(hello_current->key);
        hello_current = hello_current->right;
    }

    return 0;
}
