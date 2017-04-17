//
//  scoreboard.cc
//
//
#include <iostream>
#include "scoreboard.h"
using namespace std;
/*
    int numplayers;
    int currval;
    int maxded;
    int player_a_wins;
    int player_b_wins;*/

Scoreboard::Scoreboard(int val,int max){
    numplayers=0;
    currval = val;
    maxded = max;
    player_a_wins=0;
    player_b_wins=0;
}

Scoreboard::Scoreboard(int val,int max, string pain, string pbin){
    numplayers=0;
    currval = val;
    maxded = max;
    player_a_wins=0;
    player_b_wins=0;
}
    
int Scoreboard::get_numPlayers(){
    return numplayers;
}
int Scoreboard::get_player_a_wins(){
    return player_a_wins;
}
int Scoreboard::get_player_b_wins(){
    return player_b_wins;
}
void Scoreboard::set_scoreboard(int val, int max){
    currval=val;
    maxded=max;
}

int Scoreboard::get_curr(){
    return currval;
}

int Scoreboard::get_maxded(){
    return maxded;
}
