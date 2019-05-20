//main account definitions
#include "account.h"

account::account(std::string accname) {
    std::string name = accname; 
}

float account::sum(){
    float sum;
    for(std::pair<std::string, float> trans: transactions){
	sum += trans.second;
    }
    return sum;
}

void account::newtrans(std::string name, float value){
    transactions.emplace_back(std::pair<std::string, float>(name, value));
}
