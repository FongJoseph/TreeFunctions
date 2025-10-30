#include <fstream>
#include <iostream>
#include "tree.h"
using namespace std;

int main() {
    // Temporary code
    // Stores "Hello, World!" as a tree, right nodes only
    string hello_string = "Hello, World!";

    Node* hello_root = new Node((int)hello_string[0]);

    for (int i = 1; hello_string[i] != '\0'; i++)
        hello_root->insert((int)hello_string[i]);

    // Temporary code
    // Example usage of Matt's toSVG function
    // Outputs hello_root graphically to a file "hello.svg"
    ofstream("hello.svg") << hello_root->toSVG();

    delete hello_root;


    // ============================================================================
    // Example usage of Joseph's removeValue function
    // ============================================================================
    
    // Create a sample BST
    //       50
    //      /  \
    //    30    70
    //   /  \   / \
    //  20  40 60 80
    
    Node* root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);
    root->left->left = new Node(20);
    root->left->right = new Node(40);
    root->right->left = new Node(60);
    root->right->right = new Node(80);
    
    // Save tree before and after removing a node
    ofstream("tree_before.svg") << root->toSVG();
    root = root->removeValue(70);
    ofstream("tree_after.svg") << root->toSVG();

    // print out if tree is balanced or not - Marc Cabrera
      cout << (root->isBalanced() ? "The tree is balanced" : "Tree is not balanced") << endl;

	//Test 6: Traverse LNR - David Nutley
    if (root != nullptr) {
        cout << "\nLNR Traversal of current tree: ";
        string traversal = root->traverseLNR(root);
        for (char c : traversal) {
            cout << c << " ";
        }
        cout << endl;
	}

    // Clean up
    delete root;
    
    cout << "\n=== Testing complete ===" << endl;
    return 0;
}
