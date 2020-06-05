#include "essauwilliams.h"

EssauWilliams::EssauWilliams(int **a, int b){
    matrix=a;
    size=b;

    result_matrix=new bool *[size];
    flag=new bool [size];
    subgraphs=new int [size];//кількість зв'язків

    for (int i=0; i<size; i++){
        subgraphs[i]=i;
        flag[i]=false;
        result_matrix[i] = new bool [size];
        for (int j=0; j<size; j++)
            result_matrix[i][j]=false;
      }
  }

EssauWilliams::~EssauWilliams(){
    delete[] flag;
    delete[] subgraphs;
    ///result_matrix не видаляємо, оскільки він використовується далі
}

bool** EssauWilliams::algorythm(){
    terminate=false;
    while (true){
        int from=0,to=0,tradeoff=0;
        for (int i=0;i<size;i++){
            if (flag[i]==true) continue;
            for (int j=0;j<size;j++){
                if (subgraphs[i]==subgraphs[j]) continue;
                ///
                int tmp_t=matrix[i][0]-matrix[i][j];
                int tmp_w=0;
                for (int k=0;k<size;k++){
                    if ((subgraphs[k]==subgraphs[i])||(subgraphs[k]==subgraphs[j]))
                      tmp_w++;
                  }
                if ((tmp_t>=tradeoff)&&((tmp_w<limit)||(j==0))){
                    tradeoff=tmp_t;
                    from=i;
                    to=j;
                  }
              }
          }
        //умова виходу
        if ((from==0)&&(to==0)) break;
        //додаємо новий зв'язок
        result_matrix[from][to]=result_matrix[to][from]=true;
        //вказуємо, що вершина оброблена
        flag[from]=true;
        //тепер вершини в одному підграфі
        int tmp_from=subgraphs[from], tmp_to=subgraphs[to];
        for (int i=0;i<size;i++){
            if (subgraphs[i]==tmp_from)
                subgraphs[i]=tmp_to;
        }
    }
    return result_matrix;
}
