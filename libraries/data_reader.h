#ifndef CSV2_LIBRARY_H  /*the CSV2_LIBRARY_H is not defined before the #ifndef directive is encountered, it will be defined.
                            When there definitions in a header file that can not be made twice, the code below should be used. 
                            A header file may be included twice other include files include it, or an included file includes it  
                            and the source file includes it again.To prevent bad effects from a double include, it is common to  
                            surround the body in the include file with the following (where MYHEADER_H is replaced by a name that 
                            is appropriate for your program).
                                    #ifndef MYHEADER_H
                                    #define MYHEADER_H
                                        . . .	// This will be seen by the compiler only once 
                                        #endif  MYHEADER_H */
#define CSV2_LIBRARY_H

#include <vector>

struct WeatherData {
    unsigned long time;
    double ambient_temp;
    double wind_speed;
    double direct_sun[4];
    double diffuse_sun;
    double direct_sun_vertical;
    double spot_price;
};

extern std::vector <WeatherData> weather;

extern "C" {           /* extern: When applied to function declarations, the additional "C" or "C++" string literal will change name mangling when 
                          compiling under the   opposite language. That is, extern "C" int plain_c_func(int param); 
                          allows C++ code to execute a C library function plain_c_func.*/
int initialize_data(const char *historical_data_path);
double historical_data(double current_time, const char *field, int month, int day, int position);
double rate_or_fraction(double current_time, const char *field, int month, int day, int position,
                        const char *rate_or_fraction);
}
#endif
