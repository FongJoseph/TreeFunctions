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
    ofstream svg1("tree_initial.svg");
    svg1 << root->toSVG();
    svg1.close();
    cout << "Saved initial tree to tree_initial.svg" << endl;
    
    // Test 1: Remove a leaf node
    cout << "\nRemoving leaf node 20..." << endl;
    root = root->removeValue(20);
    ofstream svg2("tree_after_remove_20.svg");
    svg2 << root->toSVG();
    svg2.close();
    cout << "Saved to tree_after_remove_20.svg" << endl;
    
    // Test 2: Remove a node with one child
    cout << "\nRemoving node 30 (has one child: 40)..." << endl;
    root = root->removeValue(30);
    ofstream svg3("tree_after_remove_30.svg");
    svg3 << root->toSVG();
    svg3.close();
    cout << "Saved to tree_after_remove_30.svg" << endl;
    
    // Test 3: Remove a node with two children
    cout << "\nRemoving node 70 (has two children: 60, 80)..." << endl;
    root = root->removeValue(70);
    ofstream svg4("tree_after_remove_70.svg");
    svg4 << root->toSVG();
    svg4.close();
    cout << "Saved to tree_after_remove_70.svg" << endl;
    
    // Test 4: Remove the root
    cout << "\nRemoving root node 50..." << endl;
    root = root->removeValue(50);
    ofstream svg5("tree_after_remove_root.svg");
    svg5 << root->toSVG();
    svg5.close();
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
    
    // Clean up
    delete root;
    
    cout << "\n=== Testing complete ===" << endl;
    return 0;
}
