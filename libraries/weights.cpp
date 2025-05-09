#include "weights.h"
#include <sstream>

bool got_param = false;
double weight_alpha_beta;
double weight_gamma;
double normalization_factor;

void _read_param(std::istream &in);

void read_param() {
    auto env = getenv("WEIGHT_VALUES");
    if (env == nullptr) {
        _read_param(std::cin);
    } else {
        std::stringstream ss(env);
        _read_param(ss);
    }
}

void _read_param(std::istream &ss) {
    if (got_param) return;
    ss >> weight_alpha_beta;
    ss >> weight_gamma;
    ss >> normalization_factor;
    got_param = true;
}


double get_alpha_beta() {
    read_param();
    return weight_alpha_beta;
}

double get_gamma() {
    read_param();
    return weight_gamma;
}

double get_normalization_factor() {
    read_param();
    return normalization_factor;
}
