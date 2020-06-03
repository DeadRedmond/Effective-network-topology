#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "essauwilliams.h"
#include "great_circles.h"

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
                else dist_matrix[i][j]=dist_matrix[j][i]=get_distance(nodes[i].llng, nodes[i].llt, nodes[j].llng, nodes[j].llt);
            }
        }
    EssauWilliams effective_topology(dist_matrix, Size);
    bool **result=effective_topology.algorythm();

    //друк результатів в файл
    ofstream output("out.txt", ofstream::trunc);
    if (!output.is_open()){
        cerr<<"Can not write to \"out.txt\""<<endl;
        return 3;
      }
    else {
        //output.width(5);
        for (int i=0; i<Size; i++){
            for (int j=0; j<Size; j++)
                output<<result[i][j]<<"\t";
            output<<endl;
        }
        output.close();
      }
      return 0;
}
