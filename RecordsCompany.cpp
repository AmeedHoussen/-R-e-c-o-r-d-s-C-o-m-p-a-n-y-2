

#include "recordsCompany.h"

RecordsCompany::RecordsCompany() : recording(new Union()) , costumerTable(new Hashmap()) , memberCost(){
}

RecordsCompany::~RecordsCompany() {
    delete recording;
    delete costumerTable; 
}

StatusType_t RecordsCompany::newMonth(int *records_stocks, int number_of_records) {
    if(number_of_records < 0){
        return StatusType::INVALID_INPUT ;
    }
    record *array = (record*) malloc(sizeof(record)*(number_of_records)) ;
    for (int i = 0 ; i < number_of_records ; i++){
        array[i] = new Records(i,records_stocks[i]) ;
    }
    unionfind newOne = new Union(number_of_records,array) ;
    delete recording ;
    recording = newOne ;
    costumerTable->freedemBillCost() ;
    memberCost.inorderFreedem(memberCost.tree_root) ;
    return StatusType::SUCCESS ;
}

StatusType RecordsCompany::addCostumer(int c_id, int phone) {
    if(c_id < 0 || phone < 0){
        return StatusType::INVALID_INPUT ;
    }
    if(costumerTable->find(c_id) != -1 ){
        return StatusType::ALREADY_EXISTS ;
    }
    costumerTable->AddCostumer(c_id,phone) ;
    return StatusType::SUCCESS ;
}

Output_t<int> RecordsCompany::getPhone(int c_id){
    if(c_id < 0 ){
        return Output_t<int>(StatusType::INVALID_INPUT) ;
    }
    if(costumerTable->find(c_id) == -1 ){
        return Output_t<int>(StatusType::DOESNT_EXISTS) ;
    }
    return Output_t<int>(costumerTable->getPhone(c_id)) ;
}

StatusType RecordsCompany::makeMember(int c_id){
    if(c_id < 0){
        return StatusType::INVALID_INPUT ;
    }
    if(costumerTable->find(c_id) == -1 ){
        return StatusType::DOESNT_EXISTS ;
    }
    if(costumerTable->IsClubMember(c_id) == true){
        return StatusType::ALREADY_EXISTS ;
    }
    costumerTable->makeMember(c_id) ;
    memberCost.insert(c_id,*costumerTable->GetCostumer(c_id)) ;
    return StatusType::SUCCESS ;
}

Output_t<bool> RecordsCompany::isMember(int c_id) {
    if(c_id < 0){
        return Output_t<bool>(StatusType::INVALID_INPUT) ;
    }
    if(costumerTable->find(c_id) == -1 ){
        return Output_t<bool>(StatusType::DOESNT_EXISTS) ;
    }
    return Output_t<bool>(costumerTable->IsClubMember(c_id));
}

StatusType RecordsCompany::buyRecord(int c_id, int r_id){
    if(c_id < 0 || r_id < 0){
        return StatusType ::INVALID_INPUT ;
    }
    if(costumerTable->find(c_id) == -1){
        return StatusType ::DOESNT_EXISTS ;
    }
    if(r_id >= recording->size) {
        return StatusType ::DOESNT_EXISTS ;
    }
    if(costumerTable->IsClubMember(c_id)){
        memberCost.find(c_id)->data->setMonthlyE(100 + recording->array[r_id]->getSold()) ;
    }
    recording->array[r_id]->setSold() ;
    return StatusType::SUCCESS ;
}

StatusType RecordsCompany::addPrize(int c_id1, int c_id2, double  amount){
    if(c_id1 < 0 || c_id2 < c_id1 || amount <= 0){
        return StatusType ::INVALID_INPUT ;
    }
    memberCost.inorderPrize(memberCost.tree_root , c_id1 , c_id2 , -amount) ;
    return StatusType::SUCCESS ;
}

Output_t<double> RecordsCompany::getExpenses(int c_id){
    if(c_id < 0){
        return Output_t<double>(StatusType::INVALID_INPUT) ;
    }
    if(memberCost.find(c_id) == nullptr){
        return Output_t<double>(StatusType::DOESNT_EXISTS) ;
    }
    return Output_t<double>(memberCost.find(c_id)->data->getMonthlyE());
}

StatusType RecordsCompany::putOnTop(int r_id1, int r_id2){
    if(r_id1 < 0 || r_id2 < 0) {
        return StatusType ::INVALID_INPUT ;
    }
    if(r_id1 >= recording->size || r_id2 >= recording->size ){
        return StatusType::DOESNT_EXISTS ;
    }
    if(recording->Find(r_id1) == recording->Find(r_id2)){
        return StatusType::FAILURE ;
    }
    recording->unionf(r_id1 , r_id2 ) ;
    return StatusType::SUCCESS ;
}

StatusType RecordsCompany::getPlace(int r_id, int *column, int *hight) {
    if (r_id < 0 || column == nullptr || hight == nullptr ) {
        return StatusType ::INVALID_INPUT ;
    }
    if (r_id >= recording->size){
        return StatusType ::DOESNT_EXISTS ;
    }
    *column = recording->Find(r_id);
    *hight = recording->high[r_id] ;
    return StatusType::SUCCESS ;
}
