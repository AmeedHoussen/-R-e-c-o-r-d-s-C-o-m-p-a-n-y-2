
#include "utilesWet2.h"
#include "Costumer.h"
#define INITILAZIE_MAP_SIZE 5

class Hashmap
{
private:
    costumer* map;
    int CostumersNum;
    int mapSize;
    int addCounter;

public :
    Hashmap();
    Hashmap(Hashmap& map1);
    ~Hashmap();

    //void cleanMap();
    void extendMap();
    int calucate(int c_id, int oftens);
    int find(int c_id);
    int CheckNode(int x);
    void AddNode(costumer costumer);

    //int Step(int c_id);
    void AddCostumer(int c_id, int phone);
    costumer GetCostumer(int c_id);
    bool IsClubMember(int c_id);
    void makeMember(int c_id);
    int getPhone(int c_id);
    void freedemBillCost();
};
typedef Hashmap* hashmap;
