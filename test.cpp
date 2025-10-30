#include <gtest/gtest.h>
#include "tree.h"
using namespace std;

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

    delete testTree;
}

TEST(TreeTest, InsertNode) {
    Node* testTree = new Node(10);
    testTree = testTree->insert(5);
    testTree = testTree->insert(15);

    EXPECT_NE(testTree->search(5), nullptr);
    EXPECT_NE(testTree->search(15), nullptr);

    delete testTree;
}

TEST(TreeTest, ToSVGHeader) {
    Node* testNode = new Node(7);
    string svg = testNode->toSVG();
    EXPECT_EQ(svg.substr(0, svg.find('\n')),
        "<svg xmlns=\'http://www.w3.org/2000/svg\' viewBox='0 0 1024 600'>");
    delete testNode;
}

TEST(TreeTest, ToSVGElement) {
    Node* testNode = new Node(7);
    string svg = testNode->toSVGelement(512, 256, 50, 0);
    EXPECT_EQ(svg,
        "<circle stroke='#333' stroke-width='2' r='24' cx='512.000000' cy='50.000000' fill='#f2d9d9' />\n"
        "<text font-family='sans-serif' font-size='16' text-anchor='middle' x='512.000000' y='56.000000'>"
        "7"
        "</text>\n"
    );
    delete testNode;
}

TEST(TreeTest, ToSVGFooter) {
    Node* testNode = new Node(7);
    string svg = testNode->toSVG();
    EXPECT_EQ(svg.substr(svg.size() - 7),
        "</svg>\n");
    delete testNode;
}

TEST (TreeTest, TraverseLNR) {
    Node* root = new Node(2);
    root->left = new Node(1);
    root->right = new Node(3);
    string traversal = root->traverseLNR(root);
    EXPECT_EQ(traversal, "1 2 3 ");
    delete root;
}
