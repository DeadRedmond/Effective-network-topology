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
    int step=0;
    while (!terminate){
    //for (int k=0;k<1;k++){
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
        //додаємо новий зв'язок
        result_matrix[from][to]=result_matrix[to][from]=true;
        //тепер вершини в одному підграфі
        int tmp=from;
        for (int i=0;i<size;i++){
            if (subgraphs[i]==subgraphs[tmp])
                subgraphs[i]=subgraphs[to];
            cout<<subgraphs[i]<<"|";
        }
        cout<<endl;
        //вказуємо, що вершина оброблена
        flag[from]=true;


        //друк в файл
        ofstream output("out.txt", ofstream::app);
        if (!output.is_open()){
            cerr<<"Can not write to \"out.txt\""<<endl;
          }
        else {
            //output.width(5);
            output<<"STEP #"<<(step+1)<<endl<<"FROM: "<<(from+1)<<"\tTO: "<<(to+1)<<"\tTRADEOFF: "<<(tradeoff)<<endl;
            /*
            for (int i=0; i<size; i++){
                for (int j=0; j<size; j++)
                    output<<result_matrix[i][j]<<"\t";
                output<<endl;

            }
            output<<"----------------------------------------------------------"<<endl<<endl;
            output.close();
            */
          }
        step++;


        //умова виходу
        if ((from==0)&&(to==0)) terminate=true;
       }
    return result_matrix;

}
