#include "Hashmap.h"
#include <cmath>

Hashmap::Hashmap() : CostumersNum(0), mapSize(INITILAZIE_MAP_SIZE), addCounter(0) {
    map = new costumer[INITILAZIE_MAP_SIZE];
    for (int i = 0; i < this->mapSize; i++) {
        map[i] = nullptr ;
    }
}

Hashmap::Hashmap(Hashmap& map1) : CostumersNum(map1.CostumersNum), mapSize(map1.mapSize),
    addCounter(map1.addCounter) {
    map = new costumer[map1.mapSize];
    for (int i = 0; i < mapSize; i++) {
        map[i] = map1.map[i];
    }
}

Hashmap::~Hashmap() {
    int i = 0 ;
    while (mapSize > i){
        if (map[i] != nullptr) {
            delete this->map[i];
        }
        i++ ;
    }
    delete[] map;
}

/*
void Hashmap::cleanMap() {
    costumer* newMap = new costumer[mapSize];
    costumer* oldMap = map;
    map = newMap ;
    for (int i = 0; i < mapSize; i++) {
        map[i] = nullptr;
        if (oldMap[i] != nullptr ) {
            AddNode(oldMap[i]);
        }
    }
    delete[] oldMap;
}*/

void Hashmap::extendMap() {
    int oldSize = mapSize - 1 ;
    mapSize = mapSize + INITILAZIE_MAP_SIZE;
    costumer* newMap = new costumer[this->mapSize];
    costumer* oldMap = map;
    map = newMap;
    for (int i = 0; i < mapSize; i++) {
        this->map[i] = nullptr;
    }
    while (oldSize >= 0){
        if (oldMap[oldSize] != nullptr) {
            this->AddNode(oldMap[oldSize]);
        }
        oldSize-- ;
    }
    delete[] oldMap;
}

int Hashmap::calucate(int c_id, int oftens) {
    double fe = (sqrt(5) - 1) / 2;
    double a = fe * c_id;
    int b = (int)a;
    double total = (a - b) * mapSize;
    int result = (int)total;
    return (result + oftens) % mapSize;
}

int Hashmap::find(int c_id) {
    for (int i = 0; i < mapSize; i++) {
        if (map[i] != nullptr){
            if( map[i]->getCostumerID() == c_id) {
                return i;
            }
        }
    }
    return -1;
}

int Hashmap::CheckNode(int x) {
    if (map[x] != nullptr) {
        return 2;
    }
    return 0;
}

void Hashmap::AddNode(costumer costumer) {
    if (addCounter == mapSize) {
            this->extendMap();
    }
    for (int i = 0; i < mapSize; i++) {
        int place = calucate(costumer->getCostumerID(), i);
        if (CheckNode(place) != 2) {
            map[place] = costumer;
            return ;
        }
    }
}

/*
int Hashmap::Step(int c_id) {
    int a = 5;
    while (this->mapSize % a == 0) {
        a = a + 2;
    }
    int step = (c_id) % a;
    if (step == 0) {
        step++;
    }
    return step;
}*/

void Hashmap::AddCostumer(int c_id, int phone) {
    costumer toAdd = new Costumer(c_id, phone);
    if (addCounter == mapSize) {
        extendMap();
    }
    for (int i = 0; i < mapSize; i++) {
        int place = calucate(c_id, i);
        if (CheckNode(place) != 2) {
            addCounter++ ;
            map[place] = toAdd;
            return ;
        }
    }
}

costumer Hashmap::GetCostumer(int  c_id) {
    int index = find(c_id);
    if (index < 0) {
        return nullptr;
    }
    return map[index];
}

bool Hashmap:: IsClubMember(int c_id) {
    int index = find(c_id);
    return map[index]->getIsMember();
}

void Hashmap::makeMember(int c_id) {
    int index = find(c_id);
    if (index == -1) {
        return ;
    }
    map[index]->setMember();
}

int Hashmap::getPhone(int c_id) {
    int index = find(c_id);
    if (index < 0) {
        return index;
    }
    return map[index]->getPhone();
}

void Hashmap::freedemBillCost() {
    for ( int i = 0 ; i < CostumersNum ; i++){
        map[i]->freeMonthlyE() ;
    }
}
