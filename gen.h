#ifndef GEN_H
#define GEN_H

#include <iostream>
#include <vector>
#include <cmath>
#include <random>
#include <functional>
#include <ctime>
#include <matrix.h>

using namespace std;

class GenAlg
{
public:
    GenAlg(int**a, int b, int c);
    ~GenAlg();
    Matrix algorythm();

private:
    mt19937 mt;

    //шанс оператору у відсотках
    int mutation_rate=5;
    int crossover_rate=20;

    //генерація вихідної популяції
    void generator();
    //мутація
    void mutation();
    //рекомбінація
    void crossover();
    //оцінка
    void rate();

    void dfs(int, vector<bool>*, Matrix*);
    //змінні
    vector<vector<bool> > population;
    int size, v_size=0, p_size, degree, cut_limit, **matrix;

    bool randomBool();
    int randomInt(int);

    vector<bool> MatrixToVector(Matrix);
    Matrix VectorToMatrix(vector<bool>);
};

#endif // GEN_H
