#ifndef MATRIX_H
#define MATRIX_H

using namespace std;

class Matrix
{
private:
    int size;
    bool** M;

public:
    //конструктор за замовчуванням
    Matrix(){
        size=0;
        M=nullptr;
    };

    //конструктор з параметром
    Matrix(int _size){
        size=_size;
        M=new bool *[size];
        for (int i = 0; i < size; i++)
                M[i] = new bool [size];

        for (int i = 0; i < size; i++)
              for (int j = 0; j < size; j++)
                M[i][j] = false;
    };

    //конструктор копіювання
    Matrix(const Matrix& _M){
        size=_M.size;

        M=new bool *[size];
        for (int i = 0; i < size; i++)
                M[i] = new bool [size];

        for (int i = 0; i < size; i++)
              for (int j = 0; j < size; j++)
                M[i][j] = _M.M[i][j];
    };

    //деструктор
    ~Matrix(){
        if (size>0){
            for (int i=0;i<size;i++)
                delete[] M[i];
            delete[] M;
        }

    };

    //методи доступу
    bool getIJ(int i,int j){
        if ((size>0) && (i<size) &&(j<size))
            return M[i][j];
        else
            return false;
    };
    bool setIJ(int i,int j,bool value){
        if ((i<0) || (i>=size))
            return false;
        if ((j<0) || (j>=size))
            return false;
        M[i][j] = value;
        return true;
    };

    //оператор копіювання
    Matrix operator=(const Matrix& _M){
        if (size>0){
            //звільняємо раніше використану пам'ять
            for (int i=0; i<size; i++)
                delete[] M[i];
            delete[] M;
        }
        size=_M.size;

        //виділяємо нову пам'ять
        M=(bool**) new bool*[size];
        for (int i=0; i<size; i++)
            M[i] = (bool*) new bool[size];

        //заповнюємо значеннями
        for (int i=0; i<size; i++)
            for (int j=0; j<size; j++)
                M[i][j] = _M.M[i][j];
        return *this;
    };



};
#endif // MATRIX_H
