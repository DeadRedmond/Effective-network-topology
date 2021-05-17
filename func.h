#ifndef FUNC_H
#define FUNC_H
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "matrix.h"

#define RAD     6372795//радіус Землі в метрах
#define M_PI	3.14159265358979323846//Pi

using namespace std;

struct coord {
  double llt, llng;
};

vector<coord> read(const char*);
int write(bool**,int, const char*);
int write(Matrix,int, const char*);
int get_distance(double,double,double,double);
#endif // FUNC_H
