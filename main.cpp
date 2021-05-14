#include "essauwilliams.h"
#include "gen.h"
#include "func.h"
#include "args.h"

int main(int argc, char* argv[]) {

    //отримуємо аргументи командного рядка
    args_t args(argc, argv);
    //зчитуємо вміст вхідного файлу
    vector <coord> nodes=read(args.input_file);
    int Size = nodes.size();//кількість вузлів
    if (Size==0) return 2;  //зчитування з помилкою

    //виділяємо пам'ять
    int **dist_matrix=new int *[Size];
    for (int i=0;i<Size;i++){
        dist_matrix[i]=new int[Size];
    }
    //матриця відстаней між вузлами
    for (int i=0; i<Size; i++){
        for (int j=i; j<Size; j++){
            if (i==j) dist_matrix[i][j]=0;
                //знаходимо відстані
                else dist_matrix[i][j]=dist_matrix[j][i]=get_distance(nodes[i].llng, nodes[i].llt, nodes[j].llng, nodes[j].llt);
            }
        }
    //використовуємо алгоитм
    GenAlg test(dist_matrix,Size,4);
    test.generator();
    test.test();


//    EssauWilliams effective_topology(dist_matrix, Size, args.limit);
//    bool **result=effective_topology.algorythm();
//    if (write(result, Size, args.output_file)!=0) return 3;
//    //в кінці необхідно вивільнити виділену пам'ять
//    for (int i=0;i<Size;i++){
//        delete[] dist_matrix[i];
//        delete[] result[i];
//      }
//    delete[] dist_matrix;
//    delete[] result;
//    return 0;
}
