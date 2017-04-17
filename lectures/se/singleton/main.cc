#include <iostream>
#include <string>
#include "wallet.h"
#include "expense.h"
using namespace std;

int main() {
  Expense mortgage("Mortgage", 1000);
  Expense car("Car", 300);
  Expense insurance("Insurance", 200);

  Wallet *myWallet = Wallet::getInstance();

  Expense payCheque("Pay Cheque", -2000);

  cout << "Initial money: " << myWallet->money << endl;

  payCheque.pay();
  mortgage.pay();
  car.pay();
  car.pay();
  insurance.pay();

  payCheque.pay(); mortgage.pay(); car.pay(); car.pay(); insurance.pay();

 cout << "Final money: " << myWallet->money << endl;

}
