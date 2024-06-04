
#ifndef AVLTREE_H_RECORDS_H
#define AVLTREE_H_RECORDS_H
#include "utilesWet2.h"

class Records {
private:
    int r_id ;
    int copies ;
    int sold ;

public:
    Records() = default ;
    Records( int recordId , int numcopies , int sold = 0 ) ;
    Records(const Records& other) = default ;
    Records& operator=(const Records& copyc) = default ;
    ~Records() = default ;

    int getSold() const;
    void setSold();
    int getCopies() const;
};

typedef Records *record;


#endif //AVLTREE_H_RECORDS_H
