#include <fstream>
#include <iostream>
#include "tree.h"
using namespace std;

int main() {
    // Temporary code
    // Stores "Hello, World!" as a tree, right nodes only
    string hello_string = "Hello, World!";

    Node* hello_root = new Node((int)hello_string[0]);
    Node* hello_current = hello_root;

    for (int i = 1; hello_string[i] != '\0'; i++) {
        hello_current->right = new Node((int)hello_string[i]);
        hello_current = hello_current->right;
    }

    // Print the tree in order, right nodes only
    hello_current = hello_root;
    while (hello_current != nullptr) {
        cout << (char)(hello_current->key);
        hello_current = hello_current->right;
    }
    cout << endl;

    // Temporary code
    // Example usage of Matt's toSVG function
    ofstream svgfile("hello.svg");
    svgfile << hello_root->toSVG();
    svgfile.close();

    delete hello_root;

    return 0;
}
