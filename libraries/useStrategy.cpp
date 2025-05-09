#include <libstrategy/SimpleTree.h>
#include <fstream>
#include <stdio.h>
#include "useStrategy.h"
#include <string>
#include <cstdint>
#include <filesystem>
#include <iostream>

const double min_heat_for_first_interval = 0.625;
const double heat_jump_in_each_level = 0.1875;
const int total_intensity_levels = 12;
const int ROOMS = 4;
double get_stratego_control_choice(double *discrete_time, double *room_temps, int reuse, int intervals, int strategy_num, int frequency, int read_attack, double *room_noise){
//double get_stratego_control_choice(double *discrete_time, double *room_temps, int reuse, int intervals, int strategy_num) {
    auto env = getenv("STRATEGY_DIR");
    std::string strategy_path = "./";
    if(env) {
        strategy_path = env;
    }
    string strategy_number = to_string(strategy_num); 
    std::ifstream strategy_input_file((strategy_path + "/strategy.json"));
    if (strategy_input_file) 
        std::cerr << "Strategy file found in " << strategy_path << std::endl;
    else 
        std::cerr << "Strategy file not found in " << strategy_path << std::endl;
    SimpleTree strategy = SimpleTree::parse(strategy_input_file, false, false, 0);
    double consumed_power;
    size_t best = -1;
    double best_value = std::numeric_limits<double>::infinity();
    std::ofstream strategy_choice_log;
    strategy_choice_log.open((strategy_path+"/control_choices_log.txt"), ios::app);
    for (size_t action = 1; action <= total_intensity_levels; ++action) {
        double action_value = strategy.value(discrete_time, room_temps, action);
        if (action == total_intensity_levels)
            strategy_choice_log << action_value << "\n";
        else
            strategy_choice_log << action_value << " ";
        if (best_value > action_value) {
            best_value = action_value;
            best = action;
        }
    }
    strategy_choice_log << "Best value is = " << best_value << " and best action is = " << best << "\n";
    strategy_choice_log.close();
    strategy_input_file.close();
    if (best != -1) {
        if (best != total_intensity_levels) {
            consumed_power = min_heat_for_first_interval + heat_jump_in_each_level * (best - 1);
        } else {
            consumed_power = 0;
        }
    } else {
        consumed_power = -1;
    }
    //std::cerr << "In use strategy room temps before saving "<< room_temps[1] << " " << room_temps[2] << " " << room_temps[3] << " " << room_temps[4]<< "\n";
    if (read_attack == 1){
        if (int(room_temps[0])%(frequency*15) == 0){
            for( int i=0; i<=ROOMS; i++)
            {   
               room_temps[i+1] = room_temps[i+1]- room_noise[i];
            }
        }
    }
    
    std::ofstream em_temps_and_control_choice;
    em_temps_and_control_choice.open((strategy_path+"/temps_and_choice.txt"), ios::app);
    em_temps_and_control_choice << best << " " << consumed_power << " " << *discrete_time << " " << room_temps[0] << " "
                                << room_temps[1] << " " << room_temps[2] << " " << room_temps[3] << " " << room_temps[4]
                                << "\n";
    em_temps_and_control_choice.close();
    //std::cerr << "In use strategy room temps after saving "<< room_temps[1] << " " << room_temps[2] << " " << room_temps[3] << " " << room_temps[4]<< "\n";
    std::cerr << "In use strategy reuse is "<<reuse<<" intervals is "<<intervals<<" strategy number is "<<strategy_number<< std::endl;
    if (reuse == intervals)
        std::filesystem::rename(strategy_path +"/strategy.json", strategy_path +"/strategy" + strategy_number + ".json");
    return consumed_power;
}

double get_bb_control_choice(double *room_temps, double target_temp) {
    int make_pump_on = 0;
    for (int i = 0; i < ROOMS; i++) {
        if (room_temps[i] < target_temp) {
            make_pump_on = 1;
        }
    }
    return make_pump_on * (min_heat_for_first_interval + heat_jump_in_each_level * (total_intensity_levels - 2));
}






