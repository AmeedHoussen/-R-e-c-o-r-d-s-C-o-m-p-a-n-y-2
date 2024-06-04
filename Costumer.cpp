#include "Costumer.h"

Costumer::Costumer(int cId, int phoneNum, bool Ismember ,double MonthlyE) :
    c_id(cId) , phone(phoneNum) , Ismember(Ismember) , MonthlyExpenses(MonthlyE){
}

int Costumer::getCostumerID(){
    return c_id ;
}

int Costumer::getPhone(){
    return phone ;
}

double Costumer::getMonthlyE(){
    return MonthlyExpenses ;
}

void Costumer::setMonthlyE(double add) {
    MonthlyExpenses += add ;
}

void Costumer::freeMonthlyE() {
    MonthlyExpenses = 0 ;
}

bool Costumer::getIsMember() {
    return Ismember ;
}

void Costumer::setMember() {
    Ismember = true ;
}

bool Costumer::operator==(const Costumer& costumer2) const {
    return c_id == costumer2.c_id ;
}

bool Costumer::operator!=(const Costumer& costumer2) const {
    return !(costumer2 == *this);
}

Costumer& Costumer::operator+=(const double sum) {
    MonthlyExpenses += sum ;
    return *this;
}

Costumer operator+(const Costumer& c ,const double sum){
    Costumer result = c ;
    result += sum ;
    return result ;
}

Costumer operator/=(Costumer& c ,const int sum){
    Costumer result = c ;
    c.freeMonthlyE() ;
    return result ;
}