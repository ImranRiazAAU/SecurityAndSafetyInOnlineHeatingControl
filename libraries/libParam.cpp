#include "libParam.h"
#include <stdio.h>
#include <sstream>
#include <unistd.h>
#include <fstream>
#include <string>

bool got_param = false;
double room_temperature[4];
double envelop_temperature[4];
double floor_temperature[4];
double return_temperature[4];
int global_time;
int offset;
int month;
int day;
double forward_temp;
double consumed_power;
const int ROOMS = 4;

bool changed = false;
void change_dir() {
    auto env = getenv("STRATEGY_DIR");
    if(env && !changed) {
        changed = true;
        std::cerr << "Changed to " << env << std::endl;
        chdir(env);
    }
}

void _read_param(std::istream &in);
void read_stored_Th_Te(int room_id, std::string th_or_ti, std::string strategy_path);

void read_param() {
    auto env = getenv("LEARN_DATA");
    if (env == nullptr) {
        _read_param(std::cin);
    } else {
        std::stringstream ss(env);
        _read_param(ss);
    }
}
void read_stored_Th_Te(int room_id, std::string th_or_ti, std::string strategy_path){
    std::string room_num = std::to_string(room_id);
    std::ifstream read_temps;
    read_temps.open((strategy_path+th_or_ti+room_num+".txt"));
    if(th_or_ti == "/LM_envelop_temp_room") {
        read_temps >> envelop_temperature[room_id];
        std::cerr << "envelop temp for room"<<room_id<<" is "<<envelop_temperature[room_id]<< std::endl;
    }
    else {
        read_temps >> floor_temperature[room_id];
        std::cerr << "floor temp for room"<<room_id<<" is "<<floor_temperature[room_id]<< std::endl;
    }
    read_temps.close();
}
void _read_param(std::istream &ss) {
    if (got_param) return;
    ss >> global_time;
    std::cerr << "global time  in libparam is "<<global_time<< std::endl;
    ss >> offset;
    std::cerr << "offset in libparam is "<<offset<< std::endl;
    ss >> month;
    std::cerr << "month in libparam is "<<month<< std::endl;
    ss >> day;
    std::cerr << "day in libparam is "<<day<< std::endl;
    ss >> forward_temp;
    std::cerr << "forward_temp in libparam is "<<forward_temp<< std::endl;
    ss >> consumed_power;
    std::cerr << "consumed_power in libparam is "<<consumed_power<< std::endl;
    for (size_t i = 0; i < ROOMS; ++i) {
        ss >> room_temperature[i];
        std::cerr << "room temp for room"<<i<<" is "<<room_temperature[i]<< std::endl;
    }
    for (size_t i = 0; i < ROOMS; ++i) {
        ss >> return_temperature[i];
        std::cerr << "return temp for room"<<i<<" is "<<return_temperature[i]<< std::endl;
    }
    auto env_str = getenv("STRATEGY_DIR");
    std::string strategy_path = "./";
    if(env_str) {
        strategy_path = env_str;
    }
    std::cerr << "strategy path in libparam is "<<strategy_path<< std::endl;
    auto env_load = getenv("LOAD_ESTIMATED_TH_TE");
    std::stringstream sss(env_load);
    int use_Th_Te_from_LM;
    sss >> use_Th_Te_from_LM;
    for (size_t i = 0; i < ROOMS; ++i) {
        std::cerr << "LOAD_ESTIMATED_TH_TE is "<<use_Th_Te_from_LM<< std::endl;
        if(use_Th_Te_from_LM == 0)
            ss >> envelop_temperature[i];
        else{
            read_stored_Th_Te(i, "/LM_envelop_temp_room", strategy_path);
        }
    }
    for (size_t i = 0; i < ROOMS; ++i) {
        std::cerr << "LOAD_ESTIMATED_TH_TE is "<<use_Th_Te_from_LM<< std::endl;
        if(use_Th_Te_from_LM == 0)
            ss >> floor_temperature[i];
        else{
            read_stored_Th_Te(i, "/LM_floor_temp_room", strategy_path);
        }

    }
    got_param = true;
}
double get_room_temp(int room_id) {
    read_param();
    return room_temperature[room_id];
}

double get_envelop_temp(int room_id) {
    read_param();
    return envelop_temperature[room_id];
}

double get_floor_temp(int room_id) {
    read_param();
    return floor_temperature[room_id];
}

int get_global_time() {
    read_param();
    return global_time;
}

int get_offset() {
    read_param();
    return offset;
}

int get_month() {
    read_param();
    return month;
}

int get_day() {
    read_param();
    return day;
}

double get_return_temp(int i) {
    read_param();
    return return_temperature[i];
}
double get_forward_temp() {
    read_param();
    return forward_temp;
}
double get_consumed_power(){
    read_param();
    return consumed_power;

}


