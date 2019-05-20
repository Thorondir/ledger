#include <string>
#include <vector>
#include <cctype>
#include <iostream>
#include <fstream>

#include "account.h"

using namespace std;
/* Main Ledger Program::
 * prompt user with menu if no command line arguments
 */

void menu(){
    string opt;
    cout << "Welcome to Thorondir's Ledger" << endl;
    cout << "(h)istory\n(n)ew transaction\n(a)ccounts" << endl;
    cin >> opt;	
    switch(tolower(opt[0])){
	case 'n':{
	}
	break;
    }
}

void newtrans(){
    if(accounts.size()){
	cout << "Please choose an account" << endl;
	for(account acc : accounts){
	    cout << acc.name << acc.sum() << endl;
	}
    } else {
	cout << "No accounts found. Please create an account." << endl;
	cin;
	newacc();
    }
}

void newacc(){

}

int main(int argc, char *argv[]){ 
    vector<account> accounts;
    
    if(argc == 1){
	newtrans();
    }
}
