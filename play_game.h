#ifndef _PLAY_GAME_H_
#define _PLAY_GAME_H_

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <fstream>

void play_game();
void print_guess(std::vector<int> guess);
void update_highscore(int curr_score);

#endif