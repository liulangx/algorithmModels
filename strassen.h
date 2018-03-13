#ifndef STRASSEN_H
#define STRASSEN_H

#include <iostream>
#include <ctime>

using namespace std;
namespace algorithmLL {
template<typename T>
class Strassen_class{
public:
    void ADD(T** MatrixA, T** MatrixB, T** MatrixResult, int MatrixSize );
    void SUB(T** MatrixA, T** MatrixB, T** MatrixResult, int MatrixSize );
    void MUL( T** MatrixA, T** MatrixB, T** MatrixResult, int MatrixSize );//朴素算法实现
    void FillMatrix( T** MatrixA, T** MatrixB, int length);//A,B矩阵赋值
    void PrintMatrix(T **MatrixA,int MatrixSize);//打印矩阵
    void Strassen(int N, T **MatrixA, T **MatrixB, T **MatrixC);//Strassen算法实现
};

}



#endif // STRASSEN_H
