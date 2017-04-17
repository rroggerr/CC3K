//--------------------------------------------------------------------------------------------------------------------
// Header for the Player class
//--------------------------------------------------------------------------------------------------------------------
#ifndef __PLAYER_H_
#define __PLAYER_H
#include <iostream>

class Player{
    std::string input;
    bool si;
    bool configured;
public:
    Player makePlayer(std::string);
    Player makePlayer();
    bool is_stdin();
    std::string get_filename();
    void set_player(std::string);
};

#endif

