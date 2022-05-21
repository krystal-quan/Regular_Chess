#ifndef RANDOM_H
#define RANDOM_H
#include <random>
#include <SDL.h>
#include <ctime>
std::random_device rd;
std::mt19937 mt(time(nullptr));

std::uniform_int_distribution<int> borderRandom(1, 16);
#endif // RANDOM_H
