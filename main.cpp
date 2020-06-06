#include "essauwilliams.h"
#include "func.h"

int main() {
    vector <coord> nodes=read();
    int Size = nodes.size();//кількість вузлів
    if (Size==0)//не вдалось прочитати або файл порожній
      return 2;

    int **dist_matrix=new int *[Size];
    for (int i=0; i<Size; i++){
        dist_matrix[i]=new int[Size];
        for (int j=i; j<Size; j++){
            if (i==j) dist_matrix[i][j]=0;
                //знаходимо відстані
                else dist_matrix[i][j]=dist_matrix[j][i]=get_distance(nodes[i].llng, nodes[i].llt, nodes[j].llng, nodes[j].llt);
            }
        }
    EssauWilliams effective_topology(dist_matrix, Size);
    bool **result=effective_topology.algorythm();
    if (write(result, Size)!=0)//не вдалось записати в файл
      return 3;
    //вивільнення пам'яті
    for (int i=0;i<Size;i++){
        delete[] dist_matrix[i];
        delete[] result[i];
      }
    delete[] dist_matrix;
    delete[] result;
    return 0;
}
