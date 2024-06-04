#include "Union.h"

Union::Union()  : size(0), parents(nullptr),son(nullptr) , high(nullptr) , array(nullptr) {
}

Union::Union(int size, record* array) :size(size), array(array) {
    parents = new int[size];
    son = new int[size] ;
    high = new int[size];
    for (int i = 0; i < size; ++i) {
        parents[i] = -1 ;
        son[i] = -1 ;
        high[i] = 0 ;
    }
}

Union::~Union() {
    delete[] parents;
    delete[] son;
    delete[] high;
    for( int i = 0 ; i< size ; i++){
        delete array[i] ;
    }
    free(array) ;
}

void Union::makeSet(int x) {
    this->parents[x] = -1;
    this->son[x] = -1;
    this->high[x] = 0 ;
}

int Union::Find(int x) {
    int old_parent = x;
    int parent = this->parents[x];
    int tmp = x;
    int save_current_parent;
    while (parent > -1) {
        old_parent = parent;
        parent = this->parents[parent];
    }
    parent = old_parent ;
    while (parent != tmp) {
        save_current_parent = parents[tmp];
        parents[tmp] = parent;
        tmp = save_current_parent;
    }
    return parent;
}

void Union::unionf(int p, int q) {
    int p_parent = this->parents[p];
    int tmp = p;
    while (p_parent > -1){
        tmp = p_parent;
        p_parent = this->parents[p_parent];
    }
    p_parent = tmp;
    int q_parent = this->parents[q];
    tmp = q;
    while (q_parent > -1){
        tmp = q_parent;
        q_parent = this->parents[q_parent];
    }
    q_parent = tmp;
    p=p_parent;
    q=q_parent;
    if (p == q) return;
    parents[p] = q;
    tmp = q ;
    int q_son = this->son[q];
    while (q_son > -1){
        tmp = q_son ;
        q_son = this->son[q_son] ;
    }
    son[tmp] = p ;
    tmp = q ;
    q_son = this->son[q];
    int x = 0 ;
    while (q_son > -1){
        x = array[tmp]->getCopies()  + high[tmp] ;
        high[q_son] = x ;
        tmp  = q_son ;
        q_son = this->son[q_son];
    }
}
