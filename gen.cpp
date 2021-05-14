#include "gen.h"
//int g_counter=0;

bool GenAlg::randomBool() {

    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> gen(0,1);
    return gen(mt);
}

int GenAlg::randomInt(int bound){
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> gen(0,bound);
    return gen(mt);
}

vector<bool> GenAlg::MatrixToVector(Matrix M){
    vector<bool> V(size, false);
    for(int v=0; v<v_size;){
        for (int i=0; i<size; i++){
            for (int j=1; j<size; j++){
                V[v]=M.getIJ(i,j);
                v++;
            }
        }
    }
    return V;
}

Matrix GenAlg::VectorToMatrix(vector<bool> V){
    Matrix M(size);
    for(int v=0; v<v_size;){
        for (int i=0; i<size; i++){
            for (int j=0; j<size; j++){
                ///
            }
        }
    }
    return M;
}




GenAlg::GenAlg(int** a, int b, int c){

    matrix=a;
    size=b;
    degree=c;

    p_size=size*size;//розмір популяції
    for (int i=1;i<size;i++)
        v_size+=size-i;//розмір вектору трикутника


    result_matrix=new bool *[size];
    subgraphs=new int [size];//кількість зв'язків

    for (int i=0; i<size; i++){
        subgraphs[i]=i;
        result_matrix[i] = new bool [size];
        for (int j=0; j<size; j++)
            result_matrix[i][j]=false;
      }
}

GenAlg::~GenAlg(){
    //необхідно вивільнити пам'ять зайняту динамічними масивами
    delete[] subgraphs;
    //result_matrix не видаляємо, оскільки він використовується далі
}
void GenAlg::generator(){

        for (int g=0; g<p_size; g++){

            Matrix tmpM(size);
            for (int i=0; i<size; i++){
                int num = randomInt(degree);
                for (int j=0; j<num; j++){
                    int idx = randomInt(size);
                    tmpM.setIJ(i,idx, true);
                    tmpM.setIJ(idx,i, true);
                }
            }


            for (int i=0; i<size; i++){
                for (int j=0; j<size; j++){
                    cout<<tmpM.getIJ(i,j)<<"  ";
                }
                cout<<endl;
            }
            cout<<":::::::::::::::::::::::::::::::::::::::"<<endl;



            tmpM.setIJ(size,size-1,true);
            tmpM.setIJ(size-1,size,true);
            vector<bool> tmpV(MatrixToVector(tmpM));

            population1.push_back(tmpV);
        }

}

void GenAlg::test(){
    cout<<":::::::::::::::::::::::::::::::::::::::"<<endl;
    for (int i=0;i<p_size;i++){
        for (int j=0;j<v_size;j++){
            cout<<population1[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool** GenAlg::algorythm(){




    return result_matrix;
}
