#ifndef ESSAUWILLIAMS_H
#define ESSAUWILLIAMS_H

#include <iostream>
#include <fstream>

using namespace std;

class EssauWilliams
{
public:
    EssauWilliams(int**,int);
    ~EssauWilliams();
    bool** algorythm();
private:
    int size, *subgraphs, **matrix;
    bool terminate, **result_matrix, *flag;
    const int limit = 4;
};

#endif // ESSAUWILLIAMS_H
