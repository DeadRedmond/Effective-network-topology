#include "essauwilliams.h"
#include "func.h"
#include "args.h"

int main() {
    args_t args;
    vector <coord> nodes=read(args.input_file);
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
    EssauWilliams effective_topology(dist_matrix, Size, args.limit);
    bool **result=effective_topology.algorythm();
    if (write(result, Size, args.output_file)!=0) return 3;
    for (int i=0;i<Size;i++){
        delete[] dist_matrix[i];
        delete[] result[i];
      }
    delete[] dist_matrix;
    delete[] result;
    return 0;
}
