#include <iostream>
#include "BSTree.h"

int main()
{
    BSTree<int> t;
    for (int i = 1; i <= 10; ++i) t.insert(i);
    for (int i = 20; i > 10; --i) t.insert(i);
    t.remove(18);
    BSTree<int>::BSNode *u = t.search(17);
    if (u == nullptr) printf("not exist!\n");
    else printf("found!\n"); 
    t.inorder();
    return 0;
}
