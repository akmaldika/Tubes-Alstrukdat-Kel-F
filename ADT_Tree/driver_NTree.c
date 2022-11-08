#include <stdio.h>
#include <stdlib.h>
#include "NTree.h"

int main() {
    int i, k, n;
    NTree t, r, s, g, v;
    Address p;


    
    scanf("%d", &n);


    CreateNTree(&t);
    t = newNode(10);
    addChildInfo(&t, 2);
    addChildInfo(&t, 5);
    
    // CreateNTree(&r);
    // r = newNode(50);
    // addChildInfo(&r, 5);
    // addChildInfo(&r, 10);
    // addChildBySpecificInfo(&r, t);

    // s = newNode(5);
    // addChildInfo(&s, 10);
    // addChildBySpecificInfo(&r, s);
    // addChildBySpecificInfo(&r, s);
    // CreateNTree(&s);
    // s = newNode(12);
    // CreateNTree(&g);
    // g = newNode(13);
    // CreateNTree(&v);
    // v = newNode(12);
    // addChildAddress(&t, r);
    // addChildAddress(&t, s);
    // addChildAddress(&r, g);
    // // addChild(&s, g);
    // // addChild(&r, v);
    // addChildAddress(&g, r);

    printNTree(t, 0);
    // printf("%d", searchNTree(t, 11));
}