#include <string>
#include "tree.h"
using namespace std;

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

//helper find min function
findMin(Node* node){
    while(node->left != nullptr)
        node = node->left;

    return node;
}

//remove a node with specified value from the tree
//returns the new root of subtree after deletion
Node* Node::removeValue(int toRemove){
    if(toRemove < key){
        if(left != nullptr){
            left = left->removeValue(toRemove)
        }
    return this;
    }
    else if(toRemove > key){
        if(right != nullptr){
            right = right->removeValue(toRemove);
        }
    return this;
    }

    else{
        if(left == nullptr && right == nullptr){ // case 1 Node has no children
            delete this;
            return nullptr;
        }
        else if(left == nullptr){ // case 2 Node has only right child
            Node* temp = right;
            right = nullptr;
            delete this;
            return temp;
        }
        else if(right == nullptr){ // case 3 Node has only left child
            Node* temp = left;
            left = nullptr;
            delete this;
            return temp;
        }
        else{ // case 4 Node has two children
            Node* successor = findMin(right);

            key = successor->key;

            right = right->removeValue(successor->key);
            return this;
        }
    }
}

// Recursive function to generate SVG elements for a node and its descendants
// Levels more than 5 deep are truncated
#define SVG_DY 100
#define SVG_MAX_Y 500
string Node::toSVGelement(double x, double dx, double y, int hue) {
    string svg;
    
    if (left != nullptr) {
        if (y + SVG_DY < SVG_MAX_Y) {
            svg += "<line class='edge' x1='" + to_string(x) + "' y1='" + to_string(y) +
               "' x2='" + to_string(x - dx) +
               "' y2='" + to_string(y + SVG_DY) +
               "' />\n";
            svg += left->toSVGelement(x - dx, dx / 2, y + SVG_DY, hue + 60);
        }
        else {
            svg += "<line class='edge truncated' x1='" + to_string(x) + "' y1='" + to_string(y) +
               "' x2='" + to_string(x - dx) +
               "' y2='" + to_string(y + SVG_DY) +
               "' />\n";
        }
    }

    if (right != nullptr) {
        if (y + SVG_DY < SVG_MAX_Y) {
            svg += "<line class='edge' x1='" + to_string(x) + "' y1='" + to_string(y) +
               "' x2='" + to_string(x + dx) +
               "' y2='" + to_string(y + SVG_DY) +
               "' />\n";
            svg += right->toSVGelement(x + dx, dx / 2, y + SVG_DY, hue + 60);
        }
        else {
            svg += "<line class='edge truncated' x1='" + to_string(x) + "' y1='" + to_string(y) +
               "' x2='" + to_string(x + dx) +
               "' y2='" + to_string(y + SVG_DY) +
               "' />\n";
        }
    }

    svg += "<circle class='node' r='24' cx='" + to_string(x) + "' cy='" + to_string(y) +
                 "' fill='hsl(" + to_string(hue) + ", 50%, 90%)' />\n";
    svg += "<text class='node-text' x='" + to_string(x) + "' y='" + to_string(y) +
           "'>" +
           to_string(key) + "</text>\n";

    return svg;
}

// "Display Tree Graphically" by Matt Fitzpatrick
// Generates an SVG document for the tree rooted at this node
string Node::toSVG() {
    string svg_header =
        "<svg xmlns='http://www.w3.org/2000/svg' viewBox='0 0 1024 600'>\n"
        "<style>\n"
        ".edge { stroke: #333; stroke-width: 2px; }\n"
        ".truncated { stroke-dasharray: 8 4; }\n"
        ".node { stroke: #333; stroke-width: 2px; }\n"
        ".node-text { font: 16px sans-serif; text-anchor: middle; dominant-baseline: central; }\n"
        "</style>\n";

    string svg_body = toSVGelement(512, 256, 50, 0);

    string svg_footer = "</svg>\n";

    return svg_header + svg_body + svg_footer;
}
