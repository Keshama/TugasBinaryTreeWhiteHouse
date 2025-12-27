#include <iostream>
#include "WhiteHouse.h"

using namespace std;

int main(){
    Node* root = buildWhiteHouseTree();
    int choice;
    string searchName;
    Node* found = NULL;

   printTreeStructure(root);

};
