#ifndef FUNC_H
#define FUNC_H
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#define RAD     6372795//радіус Землі в метрах
#define M_PI	3.14159265358979323846//Pi

using namespace std;

class coord {
public:
  double llt, llng;
};

vector<coord> read();
int write(bool**,int);
int write_int(int**,int);
int get_distance(double,double,double,double);
#endif // FUNC_H
