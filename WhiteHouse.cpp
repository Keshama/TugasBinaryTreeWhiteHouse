#include "WhiteHouse.h"

infotype newInfo(string jabatan, string nama) {
    infotype data;
    data.jabatan = jabatan;
    data.nama = nama;
    return data;
}

void createTree(adrNode &root) {
    root = Nil;
}

adrNode createNode(infotype x) {
    adrNode p = new Node;
    p->info = x;
    p->left = Nil;
    p->right = Nil;
    return p;
}

void insertChild(adrNode &parent, adrNode p) {
    if (parent != Nil && p != Nil) {
        if (parent->left == Nil) {
            parent->left = p;
        } else {
            adrNode temp = parent->left;
            while (temp->right != Nil) {
                temp = temp->right;
            }
            temp->right = p;
        }
    }
}

void displayRecursive(adrNode root, int level) {
    if (root != Nil) {
        for (int i = 0; i < level; i++) {
            cout << "    |";
        }
        cout << "-- [" << root->info.jabatan << "] " << root->info.nama << endl;
        displayRecursive(root->left, level + 1);
        displayRecursive(root->right, level);
    }
}

void displayTree(adrNode root) {
    cout << "=== STRUKTUR WHITE HOUSE (Trump 2.0) ===" << endl;
    displayRecursive(root, 0);
    cout << "========================================" << endl;
}
void printPreOrder(adrNode root) {
    if (root != Nil) {
        cout << root->info.nama << ", ";
        printPreOrder(root->left);
        printPreOrder(root->right);
    }
}

void printInOrder(adrNode root) {
    if (root != Nil) {
        printInOrder(root->left);
        cout << root->info.nama << ", ";
        printInOrder(root->right);
    }
}

void printPostOrder(adrNode root) {
    if (root != Nil) {
        printPostOrder(root->left);
        printPostOrder(root->right);
        cout << root->info.nama << ", ";
    }
}
