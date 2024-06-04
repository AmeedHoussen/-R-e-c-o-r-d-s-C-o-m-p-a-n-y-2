
#ifndef AVLTREE_H_UNION_H
#define AVLTREE_H_UNION_H
#include "AVLTree.h"
#include "Records.h"

class Union {
public:
    int size;
    int* parents;
    int* son ;
    int* high ;
    record* array;

    Union() ;
    Union(int size, record* array);
    ~Union();

    void makeSet(int x);
    int Find(int x);
    void unionf(int p, int q);

};
typedef Union* unionfind;

#endif //AVLTREE_H_UNION_H
