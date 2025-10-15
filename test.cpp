#include <gtest/gtest.h>
#include "tree.h"

TEST(TreeTest, NodeInitialization) {
    Node* testNode = new Node(42);
    EXPECT_EQ(testNode->key, 42);
    EXPECT_EQ(testNode->left, nullptr);
    EXPECT_EQ(testNode->right, nullptr);
    delete testNode;
}