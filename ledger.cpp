#include <string>
#include <cstdlib>
#include <vector>
#include <cctype>
#include <iostream>
#include <fstream>

#include "account.h"

using namespace std;
/* Main Ledger Program::
 * prompt user with menu if no command line arguments
 */

void newacc(vector<account> *accounts){
    string accname;
    cout << "Please enter the name of the account you will be creating" << endl;
    cin >> accname;
    accounts->emplace_back(account(accname));
}

void newtrans(vector<account> *accounts){
    int opt;
    if(accounts->size()){
	cout << "Please choose an account from the following list (choose by number):" << endl;
	int num = 0;
	string transname;
	float transval;
	for(account acc : *accounts){
	    cout << "(" << num << ")\t" << acc.name << "\t" << acc.sum() << endl;
	    ++num;
	}
	cin >> opt;
	cout << "Please enter the name of the transaction" << endl;
	cin >> transname;	
	cout << "Please input the value of the transaction" << endl;
	cin >> transval;

	(*accounts)[opt].newtrans(transname, transval);
    } else {
	cout << "No accounts found. Please create an account." << endl;
	newacc(accounts);
    }
}

void menu(vector<account> *accounts){
    system("clear");
    string opt;
    cout << "Welcome to Thorondir's Ledger" << endl;
    cout << "(h)istory\n(n)ew transaction\n(a)ccounts" << endl;
    cin >> opt;	
    switch(tolower(opt[0])){
	case 'n':{
	    newtrans(accounts);
	}
	break;
    }
}

int main(int argc, char *argv[]){ 
    vector<account> accounts;
    
    if(argc == 1){
	while (true){
	    menu(&accounts);
	}
    }
}
