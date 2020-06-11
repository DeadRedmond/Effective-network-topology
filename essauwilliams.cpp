#include "essauwilliams.h"
int g_counter=0;

EssauWilliams::EssauWilliams(int **a, int b, int c){
    matrix=a;
    size=b;
    limit=c;

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
    //необхідно вивільнити пам'ять зайняту динамічними масивами
    delete[] flag;
    delete[] subgraphs;
    //result_matrix не видаляємо, оскільки він використовується далі
}

/// Функція розраховує ефективну топологію для отриманих вузлів
/// з урахування обмеження на кількість вузлів в сегменті.
/// На кожному кроці виводить в термінал отриманий зв'язок,
/// і повертає вказівник на двомірну матрицю суміжності для отриманої топології
bool** EssauWilliams::algorythm(){
    terminate=false;
    while (true){
        g_counter++;
        int from=0,to=0,tradeoff=0;
        for (int i=0;i<size;i++){
            g_counter++;
            //якщо вузол вже оброблений - пропускаємо
            if (flag[i]==true) continue;
            for (int j=0;j<size;j++){
                g_counter++;
                //якщо вузли в одному підграфі - пропускаємо
                if (subgraphs[i]==subgraphs[j]) continue;
                //знаходимо виграш
                int tmp_t=matrix[i][0]-matrix[i][j];
                int tmp_w=0;
                for (int k=0;k<size;k++){
                    g_counter++;
                    //знаходимо кількість вузлів в такому підграфі
                    if ((subgraphs[k]==subgraphs[i])||(subgraphs[k]==subgraphs[j]))
                      tmp_w++;
                  }
                //перевіряємо обмеження і максимальний виграш
                if ((tmp_t>=tradeoff)&&((tmp_w<limit)||(j==0))){
                    tradeoff=tmp_t;
                    from=i;
                    to=j;
                  }
              }
          }
        //умова виходу - якщо вузли не були знайдені
        if ((from==0)&&(to==0)) break;
        //додаємо новий зв'язок
        result_matrix[from][to]=result_matrix[to][from]=true;
        //вказуємо, що вершина оброблена
        flag[from]=true;
        //тепер вершини в одному підграфі
        int tmp_from=subgraphs[from], tmp_to=subgraphs[to];
        for (int i=0;i<size;i++){
            g_counter++;
            if (subgraphs[i]==tmp_from)
                subgraphs[i]=tmp_to;
        }
        //виводимо зв'язок, отриманий в ітерації
        cout<<"FROM:"<<(from+1)<<"\tTO:"<<(to+1)<<endl;
    }
    return result_matrix;
}
