#ifndef ESSAUWILLIAMS_H
#define ESSAUWILLIAMS_H

//#define limit  5
#include <iostream>
#include <fstream>

using namespace std;

class EssauWilliams
{
public:
    EssauWilliams(int**,int,int);
    ~EssauWilliams();
    bool** algorythm();
private:
    int size, limit, *subgraphs, **matrix;
    bool terminate, **result_matrix, *flag;
};

#endif // ESSAUWILLIAMS_H
