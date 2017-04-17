//--------------------------------------------------------------------------------------------------------------------
// Header for the Scoreboard class
//--------------------------------------------------------------------------------------------------------------------
#ifndef __SCOREBOARD_H_
#define __SCOREBOARD_H
#include <iostream>
#include "player.h"

const int MAXPLAYERS = 2;
static class Scoreboard {
    int numplayers;
    int currval;
    int maxded;
    int player_a_wins;
    int player_b_wins;
    
public:
    Scoreboard(int val, int max);
    Scoreboard(int val, int max, std::string pain, std::string pbin);
    int get_numPlayers();
    int get_player_a_wins();
    int get_player_b_wins();
    void set_scoreboard(int val, int max);
    int get_curr();
    int get_maxded();
};

#endif