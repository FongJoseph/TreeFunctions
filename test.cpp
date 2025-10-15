#include <gtest/gtest.h>
#include "tree.h"

TEST(TreeTest, NodeInitialization) {
    Node* testNode = new Node(42);
    EXPECT_EQ(testNode->key, 42);
    EXPECT_EQ(testNode->left, nullptr);
    EXPECT_EQ(testNode->right, nullptr);
    delete testNode;
}

TEST(TreeTest, NodeSearch) {
    Node* testTree = new Node(10);
    testTree->left = new Node(5);
    testTree->right = new Node(15);

    EXPECT_NE(testTree->search(10), nullptr);
    EXPECT_NE(testTree->search(5), nullptr);
    EXPECT_NE(testTree->search(15), nullptr);
    EXPECT_EQ(testTree->search(20), nullptr);

    delete testTree->left;
    delete testTree->right;
    delete testTree;
}