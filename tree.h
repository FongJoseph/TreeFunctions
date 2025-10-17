#pragma once
using namespace std;

struct Node
{
    int key;
    Node* left;
    Node* right;

    Node(int item);
    ~Node();

    Node* search(int search_key);
    string toSVGelement(double x, double y, double dx, int hue);
    string toSVG();

    Node* removeValue(int toRemove);
};
