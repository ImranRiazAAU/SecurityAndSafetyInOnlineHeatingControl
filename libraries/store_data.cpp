#include "store_data.h"
#include <fstream>
#include <sstream>

void save_cost_and_discomfort(double discomfort, double cost) {
    auto env = getenv("STRATEGY_DIR");
    std::string strategy_path = "./";
    if (env) {
        strategy_path = env;
    }
    std::ofstream cost_and_discomfort;
    cost_and_discomfort.open((strategy_path + "/cost_and_discomfort_values.txt"));
    cost_and_discomfort << discomfort << "\n";
    cost_and_discomfort << cost << "\n";
    cost_and_discomfort.close();
}

void save_envelop_temp(double te, int room_id, const char *model, int global_time) {
    auto env = getenv("STRATEGY_DIR");
    std::string strategy_path = "./";
    if (env) {
        strategy_path = env;
    }
    std::string room_num = std::to_string(room_id);
    if (!strcmp(model, "LM")) {
        std::ofstream envelop_temp;
        envelop_temp.open((strategy_path + "/LM_envelop_temp_room" + room_num + ".txt"));
        envelop_temp << te;
        envelop_temp.close();
    }
    std::ofstream envelop_temp_log;
    if (!strcmp(model, "LM"))
        envelop_temp_log.open((strategy_path + "/LM_envelop_temp_log.txt"), std::ios_base::app);
    else {
        envelop_temp_log.open((strategy_path + "/EM_envelop_temp_log.txt"), std::ios_base::app);
    }
    if (room_id == 3)
        envelop_temp_log << te << "\n";
    else
        envelop_temp_log << te << ",";
    envelop_temp_log.close();
}

void save_floor_temp(double th, int room_id, const char *model, int global_time) {
    auto env = getenv("STRATEGY_DIR");
    std::string strategy_path = "./";
    if (env) {
        strategy_path = env;
    }
    std::string room_num = std::to_string(room_id);
    if (!strcmp(model, "LM")) {
        std::ofstream floor_temp;
        floor_temp.open((strategy_path + "/LM_floor_temp_room" + room_num + ".txt"));
        floor_temp << th;
        floor_temp.close();
    }
    std::ofstream floor_temp_log;
    if (!strcmp(model, "LM"))
        floor_temp_log.open((strategy_path + "/LM_floor_temp_log.txt"), std::ios_base::app);
    else {
        floor_temp_log.open((strategy_path + "/EM_floor_temp_log.txt"), std::ios_base::app);
    }
    if (room_id == 3)
        floor_temp_log << th << "\n";
    else
        floor_temp_log << th << ",";
    floor_temp_log.close();
}
