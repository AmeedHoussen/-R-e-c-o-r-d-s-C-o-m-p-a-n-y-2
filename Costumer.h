

#ifndef AVLTREE_H_COSTUMER_H
#define AVLTREE_H_COSTUMER_H
class Costumer
{
private:
    int c_id;
    int phone;
    bool Ismember;
    double MonthlyExpenses;

public:
    Costumer() = default ;
    Costumer(int cId, int phoneNum, bool Ismember = false,double MonthlyE=0) ;
    Costumer(const Costumer& other) = default ;
    Costumer& operator=(const Costumer& copyc) = default ;
    ~Costumer() = default ;

    int getCostumerID();
    int getPhone();
    double getMonthlyE();
    void setMonthlyE(double add);
    void freeMonthlyE();
    bool getIsMember();
    void setMember();

    bool operator==(const Costumer &costumer2) const;
    bool operator!=(const Costumer &costumer2) const;
    Costumer& operator+=(const double sum) ;

};
Costumer operator+(const Costumer& c ,const double sum) ;
Costumer operator/=(Costumer& c ,const int sum) ;

typedef Costumer *costumer;

#endif //AVLTREE_H_COSTUMER_H
