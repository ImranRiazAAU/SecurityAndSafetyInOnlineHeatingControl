#include "start_em.h"
#include <sstream>

bool got_param = false;
int month;
int day;
int hour;
int simulation_period;
int intervals;
int controller;
int frequency;
double noise_sensor1;
double noise_sensor2;
double noise_sensor3;
double noise_sensor4;
int strategy_attack;
int reading_attack;

void _read_param(std::istream &in);

void read_param() {
    auto env = getenv("START_DATA");
    if (env == nullptr) {
        _read_param(std::cin);
    } else {
        std::stringstream ss(env);
        _read_param(ss);
    }
}

void _read_param(std::istream &ss) {
    if (got_param) return;
    // month number (select from 1...12)
    ss >> month;
    // day number (select from 1...31 depending on the number of days in inserted month)
    ss >> day;
    // simulation starting hour for that day (select from 0...23)
    ss >> hour;
    // simulation period in days
    ss >> simulation_period;
    // number of intervals to reuse a strategy
    ss >> intervals;
    // value 0 is for stratego and 1 is for bb
    ss >> controller;
    // sensor noise frequency in terms of intervals
    ss >> frequency;
    // Attack while computing a strategy 0 for no 1 for yes
    ss >> strategy_attack;
    // Attack while reading decision from strategy 0 for no 1 for yes
    ss >> reading_attack;
    // noise for sensor1
    ss >> noise_sensor1;
    // noise for sensor2
    ss >> noise_sensor2;
    // noise for sensor3
    ss >> noise_sensor3;
    // noise for sensor4
    ss >> noise_sensor4;
    got_param = true;
}

int get_month() {
    read_param();
    return month;
}

int get_day() {
    read_param();
    return day;
}

int get_hour() {
    read_param();
    return hour;
}

int get_simulation_period() {
    read_param();
    return simulation_period;
}

int get_intervals() {
    read_param();
    return intervals;
}

int get_selected_controller() {
    read_param();
    return controller;
}
int get_frequency() {
    read_param();
    return frequency;
}

double get_noise1() {
    read_param();
    return noise_sensor1;
}
double get_noise2() {
    read_param();
    return noise_sensor2;
}
double get_noise3() {
    read_param();
    return noise_sensor3;
}
double get_noise4() {
    read_param();
    return noise_sensor4;
}

int get_strategy_attack(){
    read_param();
    return strategy_attack;
}
int get_reading_attack(){
    read_param();
    return reading_attack;
}
