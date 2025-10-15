#pragma once

struct Node
{
    int key;
    Node* left;
    Node* right;

    Node(int item) : key(item), left(nullptr), right(nullptr) {}
};