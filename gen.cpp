#include "gen.h"
//int g_counter=0;

GenAlg::GenAlg(int** a, int b, int c){
    mt19937 mt(time(NULL));


    matrix=a;
    size=b;
    degree=c;

    p_size=size*size;//розмір популяції
    for (int i=1;i<size;i++)
        v_size+=size-i;//розмір вектору трикутника
    cut_limit = p_size;
}

GenAlg::~GenAlg(){
    //необхідно вивільнити пам'ять зайняту динамічними масивами
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
        population.push_back(MatrixToVector(tmpM));

    }
}

void GenAlg::mutation(){
    p_size=population.size();
    for (int g=0; g<p_size; g++){
        if (randomInt(100)<mutation_rate){
            int bit=randomInt(v_size);
            vector<bool> tmp(population[g]);
            if (tmp[bit]==true)
                 tmp[bit]=false;
            else tmp[bit]=true;
            population.push_back(tmp);
        }
    }
}

void GenAlg::crossover(){
    p_size=population.size();
    vector<int> pos;
    for (int g=0; g<p_size; g++){
        if (randomInt(100)<crossover_rate){
            pos.push_back(g);
        }
    }


    int amount=pos.size();

    if(!(amount%2==0)){
        pos.erase(pos.begin()+ randomInt(amount)-1);
        amount--;
    }

    while (amount>0){
        int a=randomInt(amount-1);
        int b=randomInt(amount-1);

        if (a!=b){
            if (b>a) continue;
            else swap(a,b);

            vector<bool> vector_a(population[pos[a]]);
            vector<bool> vector_b(population[pos[b]]);

            int split=randomInt(v_size);
            for (int j=split; j<v_size; j++){
                int tmp=vector_a[j];
                vector_a[j]=vector_b[j];
                vector_b[j]=tmp;
            }

            population.push_back(vector_a);
            population.push_back(vector_b);

            pos.erase(pos.begin()+b);
            pos.erase(pos.begin()+a);

            amount-=2;
        }
    }
}

void GenAlg::rate(){
    p_size=population.size();
    vector<int> grade(p_size,0);

    for (int g=0; g<p_size; g++){
        //оцінимо отримані хромосоми
        Matrix tmpM=VectorToMatrix(population[g]);



        vector<bool> visited(size, false);
        //int start=randomInt(size-1);
        dfs(randomInt(size-1), &visited, &tmpM);


        bool check=visited[0];
        for (int i=1;i<size;i++)
            check=check&&visited[i];
        if (!check){
            int m=0;
            m=~m;
            m=(unsigned int)m>> 1;
            grade[g]=m;
        }

        else{

            for (int i=0; i<size; i++){
                for (int j=i+1; j<size; j++){
                    if(tmpM.getIJ(i,j)==true) grade[g]+=matrix[i][j];
                }
            }
        }
    }
    //далі потрібно відсіяти найгірші хромосоми
    //сортуємо за зростанням
    int key=grade[0];
    vector<bool> keyV(population[0]);
    int i=0;

    for(int j=0; j<p_size; j++){
        key=grade[j];
        keyV=population[j];

        i=j-1;
        while(i>=0 && grade[i]>key){
            population[i+1]=population[i];
            grade[i+1] = grade[i];

            i=i-1;

            population[i+1]=keyV;
            grade[i+1]=key;
        }
    }

    //відсікаємо найгірші
    population.erase(population.begin()+cut_limit, population.end());
}


void GenAlg::dfs(int v, vector<bool> *visited, Matrix *M) {

    visited->at(v)=true;
    for (int i = 0; i<size; ++i) {
        if ((M->getIJ(i,v)) && (visited->at(i)==false) )
            dfs(i, visited, M);
    }
}

Matrix GenAlg::algorythm(){
    generator();
    for(int i=0;i<100*size; i++){

        mutation();

        crossover();

        rate();

    }
    return VectorToMatrix(population[0]);
}



bool GenAlg::randomBool() {

    uniform_int_distribution<int> gen(0,1);
    return gen(mt);
}

int GenAlg::randomInt(int bound){

    uniform_int_distribution<int> gen(0,bound);
    return gen(mt);
}

vector<bool> GenAlg::MatrixToVector(Matrix M){
    vector<bool> V(v_size, false);
    for(int v=0; v<v_size;){
        for (int i=0; i<size; i++){
            for (int j=i+1; j<size; j++){
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
            for (int j=i+1; j<size; j++){
                M.setIJ(i,j,V[v]);
                M.setIJ(j,i,V[v]);
                v++;
            }
        }
    }
    return M;
}
