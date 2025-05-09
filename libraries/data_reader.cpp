#include "data_reader.h"

#define CSV_IO_NO_THREAD

#include <limits>
#include "csv.h"
#include <stdio.h>
#include <map>
#include <functional>
#include <random>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
#include <fstream>
#include <string>
#include <math.h>
#include <limits>

using namespace std;

std::vector <WeatherData> weather;

int _initialize_data(const char *weather_path) {
    if (!weather_path) {
        weather_path = std::getenv("MODEL_INPUT_OLD_CSV"); // access to the list of environment variables
    }
    if (!weather_path) {

        fprintf(stderr, "No CSV data path given\n");
        exit(-1);
    }
    fprintf(stderr, "Loading data from Temp %s \n", weather_path);
    if (weather_path) {
        io::CSVReader<10, io::trim_chars<' ', '\t'>, io::no_quote_escape<';'>> reader(weather_path);
        reader.next_line();
        reader.next_line();
        reader.next_line();
        bool more_to_read = true;
        while (more_to_read) {
            WeatherData data;
            char *ignored;
            std::string amb, wind, dir, diff, vert;
            more_to_read = reader.read_row(ignored, ignored, ignored, data.time, amb, wind, dir, diff, vert,
                                           data.spot_price);
            data.ambient_temp = (amb == "NaN" || amb == "nan" || amb == "") ? 0.0 : std::stod(amb);
            data.wind_speed = (wind == "NaN" || wind == "nan" || wind == "") ? 0.0 : std::stod(wind);
            data.direct_sun[1] = (dir == "NaN" || dir == "nan" || dir == "") ? 0.0 : std::stod(dir);
            data.direct_sun[0] = data.direct_sun[1] * 20.0;
            data.direct_sun[2] = data.direct_sun[0] / 25.0;
            data.direct_sun[3] = data.direct_sun[0] / 6.4;
            data.diffuse_sun = (diff == "NaN" || diff == "nan" || diff == "") ? 0.0 : std::stod(diff);
            data.direct_sun_vertical = (vert == "NaN" || vert == "nan" || vert == "") ? 0.0 : std::stod(vert);
            if (more_to_read) {
                weather.push_back(data);
            }
        }
    }
    return weather.size() == 0;
}

int initialize_data(const char *path) { return _initialize_data(path); }

void _check_init() {
    if (weather.size() == 0) {
        initialize_data(nullptr);
    }
}

int data_reading_point(int index, int month, int day) {
    auto data = weather[index];
    int m_Days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    time_t init_epoch = 1514764800;//(36*365+12*366)*86400;
    for (int i = 0; i < month - 1; i++) {
        init_epoch += m_Days[i] * 86400;
    }
    init_epoch += ((day - 1) * 86400 + (index * 3600));
    bool run = true;
    while (run) {
        if (data.time == init_epoch) { run = false; }
        else {
            data = weather[++index];
        }
    }
    return index;
}

double historical_data(double current_time, const char *field, int month, int day, int position) {
    auto index = (int) (current_time);
    _check_init();
    index = data_reading_point(index, month, day);
    auto data = weather[index];
    if (!strcmp(field, "direct_sun")) { return data.direct_sun[position]; }
    else if (!strcmp(field, "ambient_temp")) { return data.ambient_temp; }
    else if (!strcmp(field, "spot_price")) { return data.spot_price; }
    fprintf(stderr, "Wrong field\n");
    exit(-1);
}

double rate_or_fraction(double current_time, const char *field, int month, int day, int position,
                        const char *rate_or_fraction) {
    _check_init();
    double fractional, indexed;
    fractional = modf(current_time, &indexed);
    int index = int(indexed);
    index = data_reading_point(index, month, day);
    auto data1 = weather[index];
    auto data2 = weather[index + 1];
    if (!strcmp(field, "direct_sun")) {
        if (!strcmp(rate_or_fraction, "rate"))
            return data2.direct_sun[position] - data1.direct_sun[position];
        else if (!strcmp(rate_or_fraction, "fraction"))
            return (data2.direct_sun[position] - data1.direct_sun[position]) * fractional;
    } else if (!strcmp(field, "ambient_temp")) {
        if (!strcmp(rate_or_fraction, "rate"))
            return data2.ambient_temp - data1.ambient_temp;
        else if (!strcmp(rate_or_fraction, "fraction"))
            return (data2.ambient_temp - data1.ambient_temp) * fractional;
    }
    fprintf(stderr, "Wrong field\n");
    exit(-1);
}







    
