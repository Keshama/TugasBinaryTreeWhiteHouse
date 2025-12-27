#include <iostream>
#include "WhiteHouse.h"

using namespace std;

int main() {
    adrNode root = buildWhiteHouseTree();

    int choice;
    string searchName, newName, newRole, parentName;
    char pos;
    adrNode found = NULL;

    do {
        cout << "\n============================================\n";
        cout << "   STRUKTUR ORGANISASI WHITE HOUSE (ADT)    \n";
        cout << "============================================\n";
        cout << "1. Tampilkan Visualisasi Tree\n";
        cout << "2. Traversal Pre-Order\n";
        cout << "3. Traversal In-Order\n";
        cout << "4. Traversal Post-Order\n";
        cout << "5. Cari Pejabat (Search)\n";
        cout << "6. Tambah Pejabat (Insert)\n";
        cout << "0. Keluar\n";
        cout << "============================================\n";
        cout << "Pilihan Anda: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            cout << "\n[Visualisasi Struktur Tree]\n";
            printTreeStructure(root);
            break;
        case 2:
            cout << "\n--- Pre-Order Traversal ---\n";
            printPreOrder(root);
            cout << "END" << endl;
            break;
        case 3:
            cout << "\n--- In-Order Traversal ---\n";
            printInOrder(root);
            cout << "END" << endl;
            break;
        case 4:
            cout << "\n--- Post-Order Traversal ---\n";
            printPostOrder(root);
            cout << "END" << endl;
            break;
        case 5:
            cout << "\nMasukkan Nama Pejabat yang dicari: ";
            getline(cin, searchName);
            found = searchNode(root, searchName);
            if (found != NULL) {
                cout << "\n[DITEMUKAN!]\n";
                cout << "Nama   : " << found->info.name << endl;
                cout << "Jabatan: " << found->info.role << endl;
            } else {
                cout << "\n[TIDAK DITEMUKAN]\n";
            }
            break;

        case 6:
            cout << "\n--- Tambah Pejabat Baru ---\n";

            cout << "Masukkan Nama Atasan (Parent) : ";
            getline(cin, parentName);

            if (searchNode(root, parentName) == NULL) {
                cout << "[ERROR] Atasan tidak ditemukan. Cek ejaan nama (Case Sensitive).\n";
                break;
            }

            cout << "Masukkan Nama Pejabat Baru    : ";
            getline(cin, newName);
            cout << "Masukkan Jabatan              : ";
            getline(cin, newRole);
            cout << "Posisi (L = Kiri, R = Kanan)  : ";
            cin >> pos;
            cin.ignore();

            insertChild(root, parentName, newName, newRole, pos);
            break;

        case 0:
            cout << "Program Selesai.\n";
            break;
        default:
            cout << "Input salah.\n";
        }
    } while (choice != 0);

    return 0;
}
