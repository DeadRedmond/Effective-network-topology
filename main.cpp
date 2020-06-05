#include <string>
#include <vector>

#include "essauwilliams.h"
#include "func.h"

int main(int argc, char *argv[]) {
    vector <coord> nodes=read(argc);
    int Size = nodes.size();//кількість вузлів
    if (Size==0) return 2;

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
    if (write(result, Size)!=0) return 3;
    return 0;
}
