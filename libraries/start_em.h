#include <cstring>
#include <iostream>

extern "C" {
int get_month();
int get_day();
int get_hour();
int get_simulation_period();
int get_intervals();
int get_selected_controller();
int get_frequency();
double get_noise1();
double get_noise2();
double get_noise3();
double get_noise4();
int get_strategy_attack();
int get_reading_attack();
}

