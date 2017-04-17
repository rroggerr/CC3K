#ifndef __WALLET_H__
#define __WALLET_H__

struct Wallet {
  static Wallet *instance;
  static Wallet *getInstance();

  Wallet();

  int money;

  void addMoney(int amt);

  static void cleanup();
};

#endif
