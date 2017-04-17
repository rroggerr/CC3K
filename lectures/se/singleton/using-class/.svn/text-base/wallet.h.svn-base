#ifndef __WALLET_H__
#define __WALLET_H__

class Wallet {
  static Wallet *instance;

  Wallet();

  int money;
  static void cleanup();

 public:
  static Wallet *getInstance();
  int getMoney() const;
  void addMoney(int amt);

};

#endif
