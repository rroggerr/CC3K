#ifndef __EXPENSE_H__
#define __EXPENSE_H__
#include <string>
#include "wallet.h"

struct Expense {
  const std::string desc;
  const int amt;
  Wallet *wallet;

  Expense(std::string desc, int amt);
  void pay();
};

#endif
