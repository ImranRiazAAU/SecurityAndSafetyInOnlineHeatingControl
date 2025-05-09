#include <cstring>
#include <iostream>

using namespace std;

extern "C" {
double get_stratego_control_choice(double *discrete_time, double *room_temps, int reuse, int intervals, int strategy_num, int freq, int read_attack, double *room_noise);
double get_bb_control_choice(double *room_temps, double target_temp);
}
