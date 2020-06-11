#ifndef ESSAUWILLIAMS_H
#define ESSAUWILLIAMS_H

#include <iostream>
#include <fstream>

using namespace std;

class EssauWilliams
{
public:
    EssauWilliams(int**,int,int); //конструктор
    ~EssauWilliams();             //деструктор
    bool** algorythm();           //власне алгоритм
private:
    int size, limit, *subgraphs, **matrix;
    bool terminate, **result_matrix, *flag;
};

#endif // ESSAUWILLIAMS_H
