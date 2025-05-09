#include <iostream>
#include <sstream>
#include <stdio.h>
#include <random>


#include "connectUPPAALCTRL.h"

using namespace std;
const int ROOMS = 4;
bool loaded_seed = false;
std::default_random_engine rng;

void compute_strategy(double *room_temps, int global_t, int off, double *envelope_temps, double *floor_temps, int month,
                      int day, double forward_temp, double *Treturn, int reuse, double consumed_power) {

    {
        if (!loaded_seed) {
            size_t seed;
            auto env = getenv("LM_SEED");
            if (env) {
                std::stringstream ss(env);
                ss >> seed;
            } else {
                seed = time(nullptr);
            }
            rng.seed(seed);
            loaded_seed = true;
        }
        piper p;
        string learning_model = "./models/LM.xml";
        const char *learning_model_path = learning_model.c_str();
        string queries_path;
        fprintf(stderr, "\nreuse in connectUppall is %i \n", reuse);
        fprintf(stderr, "consumed power connectUppall is %f \n", consumed_power);
        fprintf(stderr, "global time in connectUppall is %i \n", global_t);
        auto env = getenv("SET_RUNS");
        std::stringstream ss(env);
        string run;
        string iteration;
        if (reuse == 1) {
            ss >> run;
            queries_path = "./models/compute_strategy.q";
        } else {
            run = "5";
            queries_path = "./models/load_strategy.q";
        }
        const char *queries = queries_path.c_str();
        fprintf(stderr, "query file is %s \n", queries);
        ss >> iteration;
        const char *runs = run.c_str();
        const char *iterations = iteration.c_str();
        fprintf(stderr, "number is runs is %s \n", runs);
        std::string rand_num = std::to_string(rng());
        std::vector<const char *> args{"verifyta", "--seed", rand_num.c_str(), "-s", "--good-runs", runs,
                                       "--total-runs", runs, "--runs-pr-state",
                                       runs, "--eval-runs", "100", "--max-iterations", iterations, "--reset-no-better",
                                       iterations,
                                       "--learning-method", "4", "-D", "0.1", learning_model_path, queries,
                                       nullptr};//args can accept any number of space separated arguments
        if (!p.run("./uppaal/bin/verifyta", args)) {
            string temp;
            temp = to_string(global_t) + "\n";
            p.send(temp.c_str());
            temp = to_string(off) + "\n";
            p.send(temp.c_str());
            temp = to_string(month) + "\n";
            p.send(temp.c_str());
            temp = to_string(day) + "\n";
            p.send(temp.c_str());
            temp = to_string(forward_temp) + "\n";
            p.send(temp.c_str());
            temp = to_string(consumed_power) + "\n";
            p.send(temp.c_str());

            for (size_t i = 0; i < ROOMS; ++i) {
                temp = to_string(room_temps[i]) + "\n";
                p.send(temp.c_str());
            }

            for (size_t i = 0; i < ROOMS; ++i) {
                temp = to_string(Treturn[i]) + "\n";
                p.send(temp.c_str());
            }
            for (size_t i = 0; i < ROOMS; ++i) {
                temp = to_string(envelope_temps[i]) + "\n";
                p.send(temp.c_str());
            }
            for (size_t i = 0; i < ROOMS; ++i) {
                temp = to_string(floor_temps[i]) + "\n";
                p.send(temp.c_str());
            }
            std::stringstream ss;
            p.block(ss);
            std::string r = ss.str();
            //fprintf(stderr, "string that we send to LM from connectUppaal is %s", r.c_str());
            fprintf(stderr, "DONE VERIFYTA\n");
            fprintf(stderr, "from compute_strategy calling %s \n", learning_model_path);

        } else fprintf(stderr, "ERROR\n");

    }

}



