#ifndef GEN_H
#define GEN_H

#include <iostream>
#include <vector>
#include <cmath>
#include <random>
#include <functional>
#include <matrix.h>

using namespace std;

class GenAlg
{
public:
    GenAlg(int**a, int b, int c);
    ~GenAlg();
    bool** algorythm();

    void test();

    void generator();

private:



    //генерація вихідної популяції

    void generatorRep();
    void generatorDel();

    //мутація
    bool** mutation();
    bool** mutationRep();

    //рекомбінація
    bool** crossover();
    bool** crossoverRep();

    //оцінка
    int rate();

    //змінні
    vector<Matrix*> population;

    vector<vector<bool> > population1;

    int size, v_size=0, p_size, degree, *subgraphs, **matrix;
    bool **result_matrix;

    bool randomBool();
    int randomInt(int);

    vector<bool> MatrixToVector(Matrix);
    Matrix VectorToMatrix(vector<bool>);

};

#endif // GEN_H
