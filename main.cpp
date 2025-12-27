#include <iostream>
#include "WhiteHouse.h"

using namespace std;

int main(){
    adrNode root;
    adrNode p, cos, press;
    infotype data;

    createTree(root);

    data = newInfo("PRESIDENT", "Donald Trump");
    root = createNode(data);

    data = newInfo("Vice President", "JD Vance");
    p = createNode(data);
    insertChild(root, p);
};
