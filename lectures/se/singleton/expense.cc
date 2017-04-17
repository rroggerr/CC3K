#include "expense.h"
#include <iostream>
#include <string>
#include "wallet.h"
using namespace std;

Expense::Expense(string desc, int amt): desc(desc), amt(amt) {
  wallet = Wallet::getInstance();
}

void Expense::pay() {
  cout << "Paying expense: " << desc << " (" << amt << ")" << endl;
  wallet->addMoney(-amt);
}

