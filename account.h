#ifndef GUARD_account_h
#define GUARD_account_h
//account.h

#include <vector>
#include <utility>
#include <string>

class account{
    public:
	std::vector<std::pair<std::string, float>> transactions;
	std::string name;

	account(std::string);

	float sum();
	
	void newtrans(std::string, float);
};
#endif
