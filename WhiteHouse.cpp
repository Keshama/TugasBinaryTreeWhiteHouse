#include "whitehouse.h"

adrNode newNode(string name, string role) {
    adrNode p = new Node;
    p->info.name = name;
    p->info.role = role;
    p->left = NULL;
    p->right = NULL;
    return p;
}
adrNode buildWhiteHouseTree() {
    // Level 0 (Root)
    adrNode root = newNode("Donald J. Trump", "President of USA");

    // Level 1
    root->left = newNode("J.D. Vance", "Vice President");
    root->right = newNode("Susie Wiles", "Chief of Staff");

    // Level 2 (Anak J.D. Vance - Sisi Kiri)
    root->left->left = newNode("Jacob Reses", "VP Chief of Staff");
    root->left->right = newNode("Chirag Parikh", "Exec. Sec. Nat. Space");

    // Level 2 (Anak Susie Wiles - Sisi Kanan)
    root->right->left = newNode("Marco Rubio", "Nat. Security Council");
    root->right->right = newNode("Russell Vought", "OMB Director");

    // Level 3 (Anak Marco Rubio)
    root->right->left->left = newNode("Stephen Miller", "Homeland Security");
    root->right->left->right = newNode("Devin Nunes", "Intel. Advisory Board");

    // Level 3 (Anak Russell Vought)
    root->right->right->left = newNode("Stephen Miran", "Eco. Advisers");
    root->right->right->right = newNode("Joshua Fisher", "Office of Admin");

    // Level 4 (Bawah Stephen Miller)
    root->right->left->left->left = newNode("Sean Cairncross", "Nat. Cyber Director");

    // Level 4 (Bawah Stephen Miran)
    root->right->right->left->left = newNode("Jamieson Greer", "US Trade Rep");
    root->right->right->left->right = newNode("Michael Krastios", "Science Office");

    // Level 4 (Bawah Joshua Fisher)
    root->right->right->right->left = newNode("Katherine Scarlett", "Env. Quality Council");
    root->right->right->right->right = newNode("Robert B. Downing", "WH Chief Usher");

    return root;
}


void printPreOrder(adrNode root) {
    if (root == NULL) return;
    cout << root->info.name << " -> ";
    printPreOrder(root->left);
    printPreOrder(root->right);
}

void printInOrder(adrNode root) {
    if (root == NULL) return;
    printInOrder(root->left);
    cout << root->info.name << " -> ";
    printInOrder(root->right);
}

void printPostOrder(adrNode root) {
    if (root == NULL) return;
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->info.name << " -> ";
}

void printTreeStructure(adrNode root, int space, int height) {
    if (root == NULL) return;

    space += height;

    printTreeStructure(root->right, space);
    cout << endl;
    for (int i = height; i < space; i++) cout << " ";
    cout << "[" << root->info.name << "]\n";
    for (int i = height; i < space; i++) cout << " ";
    cout << "(" << root->info.role << ")\n";
    printTreeStructure(root->left, space);
}

adrNode searchNode(adrNode root, string targetName) {
    if (root == NULL) return NULL;

    string rootName = root->info.name;
    if (rootName.find(targetName) != string::npos) {
        return root;
    }

    adrNode foundLeft = searchNode(root->left, targetName);
    if (foundLeft != NULL) return foundLeft;

    return searchNode(root->right, targetName);
}
