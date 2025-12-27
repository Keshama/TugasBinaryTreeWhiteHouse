#ifndef WHITEHOUSE_H
#define WHITEHOUSE_H

#include <string>
#include <iostream>

#define Nil NULL

using namespace std;

typedef Pejabat infotype;
typedef struct Node *adrNode;

struct Pejabat {
    string jabatan;
    string nama;
};

struct Node {
    infotype info;
    adrNode left;   //** Menunjuk ke Bawahan (Anak)
    adrNode right;  //** Menunjuk ke Rekan Kerja (Saudara)
};

void createTree(adrNode &root);
adrNode createNode(infotype x);
void insertChild(adrNode &parent, adrNode p);
void displayTree(adrNode root);
infotype newInfo(string jabatan, string nama);
void printPreOrder(adrNode root);
void printInOrder(adrNode root);
void printPostOrder(adrNode root);

#endif
