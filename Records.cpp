
#include "Records.h"

Records::Records(int recordId , int numcopies , int sold) :
    r_id(recordId) , copies(numcopies) , sold(sold) {
}

int Records::getSold() const {
    return sold;
}

void Records::setSold() {
    sold++ ;
}

int Records::getCopies() const {
    return copies;
}
