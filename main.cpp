#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "essauwilliams.h"
#include "great_circles.h"

using namespace std;

class coord {
public:
  double llt, llng;
};


int main() {
    cout.setf(ios_base::fixed);
    cout.precision(6);
    vector <coord> nodes;
    remove ("out.txt");

    //відкриваємо файл
      ifstream input("input.txt");
      if (!input.is_open()){
          cerr<<"Can not read \"input.txt\""<<endl;
          return 2;
        }

      //зчитуємо вміст по рядку
      else {
          string line;
          while (getline(input, line)){
              coord tmp;
              istringstream iss(line);
              iss>>tmp.llng>>tmp.llt;
              nodes.push_back(tmp);
            }
        }

      int Size = nodes.size();//кількість вузлів
      int **dist_matrix=new int *[Size];
      bool **result_array=new bool *[Size];
      for (int i=0;i<Size;i++){
        dist_matrix[i]=new int[Size];
        result_array[i]=new bool[Size];
      }

      //матриця відстаней між вузлами
      for (int i=0; i<Size; i++){
        for (int j=i; j<Size; j++){
            if (i==j) dist_matrix[i][j]=0;
                //знаходимо відстані
                else
                dist_matrix[i][j]=dist_matrix[j][i]=get_distance(nodes[i].llng, nodes[i].llt, nodes[j].llng, nodes[j].llt);
              }
          }



    return 0;
}
