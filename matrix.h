#ifndef MATRIX_H
#define MATRIX_H

using namespace std;

class Matrix
{
private:
    int matrix_size;
    bool** M;

public:
    //конструктор за замовчуванням
    Matrix(){
        matrix_size=0;
        M=nullptr;
    };

    //конструктор з параметром
    Matrix(int _size){
        matrix_size=_size;
        M=new bool *[matrix_size];
        for (int i = 0; i < matrix_size; i++)
                M[i] = new bool [matrix_size];

        for (int i = 0; i < matrix_size; i++)
              for (int j = 0; j < matrix_size; j++)
                M[i][j] = false;
    };

    //конструктор копіювання
    Matrix(const Matrix& _M){
        matrix_size=_M.matrix_size;

        M=new bool *[matrix_size];
        for (int i = 0; i < matrix_size; i++)
                M[i] = new bool [matrix_size];

        for (int i = 0; i < matrix_size; i++)
              for (int j = 0; j < matrix_size; j++)
                M[i][j] = _M.M[i][j];
    };

    //деструктор
    ~Matrix(){
        if (matrix_size>0){
            for (int i=0;i<matrix_size;i++)
                delete[] M[i];
            delete[] M;
        }

    };

    //методи доступу
    bool getIJ(int i,int j){
        if ((matrix_size>0) && (i<matrix_size) &&(j<matrix_size))
            return M[i][j];
        else
            return false;
    };
    bool setIJ(int i,int j,bool value){
        if ((i<0) || (i>=matrix_size))
            return false;
        if ((j<0) || (j>=matrix_size))
            return false;
        M[i][j] = value;
        return true;
    };

    //оператор копіювання
    Matrix operator=(const Matrix& _M){
        if (matrix_size>0){
            //звільняємо раніше використану пам'ять
            for (int i=0; i<matrix_size; i++)
                delete[] M[i];
            delete[] M;
        }
        matrix_size=_M.matrix_size;

        //виділяємо нову пам'ять
        M=(bool**) new bool*[matrix_size];
        for (int i=0; i<matrix_size; i++)
            M[i] = (bool*) new bool[matrix_size];

        //заповнюємо значеннями
        for (int i=0; i<matrix_size; i++)
            for (int j=0; j<matrix_size; j++)
                M[i][j] = _M.M[i][j];
        return *this;
    };



};
#endif // MATRIX_H
