#ifndef WHITEHOUSE_H
#define WHITEHOUSE_H

#include <iostream>
#include <string>
using namespace std;

struct infotype {
    string name;
    string role;
};

typedef struct Node* adrNode;

struct Node {
    infotype info;
    adrNode left;
    adrNode right;
};

adrNode newNode(string name, string role);
adrNode buildWhiteHouseTree();
void printPreOrder(adrNode root);
void printInOrder(adrNode root);
void printPostOrder(adrNode root);
void printTreeStructure(adrNode root, int space = 0, int height = 10);
adrNode searchNode(adrNode root, string targetName);

#endif
