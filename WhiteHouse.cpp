#include "WhiteHouse.h"

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

void insertChild(adrNode root, string parentName, string name, string role, char position) {
    adrNode parent = searchNode(root, parentName);

    if (parent == NULL) {
        cout << "\n[ERROR] Parent dengan nama \"" << parentName << "\" tidak ditemukan!\n";
        return;
    }

    if (position == 'L' || position == 'l') {
        if (parent->left == NULL) {
            parent->left = newNode(name, role);
            cout << "\n[SUKSES] " << name << " berhasil ditambahkan sebagai anak KIRI dari " << parent->info.name << ".\n";
        } else {
            cout << "\n[GAGAL] Posisi KIRI dari " << parent->info.name << " sudah terisi oleh " << parent->left->info.name << "!\n";
        }
    }
    else if (position == 'R' || position == 'r') {
        if (parent->right == NULL) {
            parent->right = newNode(name, role);
            cout << "\n[SUKSES] " << name << " berhasil ditambahkan sebagai anak KANAN dari " << parent->info.name << ".\n";
        } else {
            cout << "\n[GAGAL] Posisi KANAN dari " << parent->info.name << " sudah terisi oleh " << parent->right->info.name << "!\n";
        }
    }
    else {
        cout << "\n[ERROR] Posisi salah! Masukkan 'L' untuk Kiri atau 'R' untuk Kanan.\n";
    }
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

void printRecursive(adrNode root, string indent, bool isLast) {
    if (root == NULL) return;
    cout << indent;
    if (isLast) {
        cout << "`-- ";
        indent += "    ";
    } else {
        cout << "|-- ";
        indent += "|   ";
    }
    cout << root->info.name << " (" << root->info.role << ")" << endl;

    if (root->left != NULL && root->right != NULL) {
        printRecursive(root->left, indent, false);
        printRecursive(root->right, indent, true);
    }
    else if (root->left != NULL) {
        printRecursive(root->left, indent, true);
    }
    else if (root->right != NULL) {
        printRecursive(root->right, indent, true);
    }
}

void printTreeStructure(adrNode root) {
    if (root == NULL) return;

    cout << root->info.name << " (" << root->info.role << ")" << endl;

    if (root->left != NULL && root->right != NULL) {
        printRecursive(root->left, "", false);
        printRecursive(root->right, "", true);
    }
    else if (root->left != NULL) {
        printRecursive(root->left, "", true);
    }
    else if (root->right != NULL) {
        printRecursive(root->right, "", true);
    }
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
