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
        hello_root = hello_root->insert((int)hello_string[i]);

    // Temporary code
    // Example usage of Matt's toSVG function
    // Outputs hello_root graphically to a file "hello.svg"
    ofstream("hello.svg") << hello_root->toSVG();

    delete hello_root;


    // ============================================================================
    // Example usage/testing of Joseph's removeValue function
    // ============================================================================
    
    cout << "\n=== Testing removeValue ===" << endl;
    
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
    
    cout << "Created BST with values: 50, 30, 70, 20, 40, 60, 80" << endl;
    
    // Save initial tree
    ofstream("tree_initial.svg") << root->toSVG();
    cout << "Saved initial tree to tree_initial.svg" << endl;
    
    // Test 1: Remove a leaf node
    cout << "\nRemoving leaf node 20..." << endl;
    root = root->removeValue(20);
    ofstream("tree_after_remove_20.svg") << root->toSVG();
    cout << "Saved to tree_after_remove_20.svg" << endl;
    
    // Test 2: Remove a node with one child
    cout << "\nRemoving node 30 (has one child: 40)..." << endl;
    root = root->removeValue(30);
    ofstream("tree_after_remove_30.svg") << root->toSVG();
    cout << "Saved to tree_after_remove_30.svg" << endl;
    
    // Test 3: Remove a node with two children
    cout << "\nRemoving node 70 (has two children: 60, 80)..." << endl;
    root = root->removeValue(70);
    ofstream("tree_after_remove_70.svg") << root->toSVG();
    cout << "Saved to tree_after_remove_70.svg" << endl;
    
    // Test 4: Remove the root
    cout << "\nRemoving root node 50..." << endl;
    root = root->removeValue(50);
    ofstream("tree_after_remove_root.svg") << root->toSVG();
    cout << "Saved to tree_after_remove_root.svg" << endl;
    
    // Test 5: Verify search still works
    if (root != nullptr) {
        Node* found = root->search(80);
        if (found != nullptr) {
            cout << "\nSearch for 80: Found! Key = " << found->key << endl;
        } else {
            cout << "\nSearch for 80: Not found" << endl;
        }
        
        Node* notFound = root->search(20);
        if (notFound != nullptr) {
            cout << "Search for 20: Found! Key = " << notFound->key << endl;
        } else {
            cout << "Search for 20: Not found (correct, we deleted it)" << endl;
        }
    }


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
