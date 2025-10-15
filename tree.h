#pragma once

struct Node
{
    int key;
    Node* left;
    Node* right;

    Node(int item);
    ~Node();

    Node* search(int search_key);
};