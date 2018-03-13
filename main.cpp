#include <iostream>
#include "algorithmmodels.h"
#include "strassen.h"

using namespace std;


int main()
{
    //整数划分问题
    int result = algorithmLL::integerDivisionProblem(6, 6);
    cout << result << endl;
    //fibonacci数列问题
    result = algorithmLL::fibonacci(4);
    cout << result << endl;
    //阶乘问题
    result = algorithmLL::factorial(4);
    cout << result << endl;
    //ackerman问题
    result = algorithmLL::ackerman(3, 3);
    cout << result << endl;
    //排列组合问题
    string s = "abc";
    vector<string> resultS = algorithmLL::permutation(s);
    for(vector<string>::iterator itr = resultS.begin(); itr != resultS.end(); ++itr)
    {
        cout << *itr << endl;
    }
    //汉诺塔问题
    algorithmLL::hannoi(7);
    //二分搜索问题
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    result = algorithmLL::binarySearch(a, 3, 10);
    cout << result << endl;
    //棋盘覆盖问题
    //int board[4][4] = {{1, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    int k = 8;
    int ** board = new int *[k];
    for(int i = 0; i < k; ++i)
    {
        board[i] = new int[k];
    }
    for(int i(0); i < k; ++ i)
    {
        for(int j(0); j < k; ++j)
            board[i][j] = 0;
    }
    algorithmLL::chessBoard(0, 0, 0, 0, k, board);
    for(int i(0); i < k; ++ i)
    {
        for(int j(0); j < k; ++j)
            cout << board[i][j] << " ";
        cout << endl;
    }
    //插入排序问题
    vector<int> A;
    for(int i(0); i < 10; i++)
        A.push_back(rand());
    algorithmLL::insertionSort(A);
    for(int i(0); i < A.size(); i++)
        std::cout << A[i] << endl;
    cout << endl;
    //shell排序问题
    vector<int> B;
    for(int i(0); i < 10; i++)
        B.push_back(rand());
    algorithmLL::shellSort(B);
    for(int i(0); i < B.size(); i++)
        std::cout << B[i] << endl;
    cout << endl;
    //归并排序问题
    vector<int> C;
    for(int i(0); i < 10; i++)
        C.push_back(rand());
    algorithmLL::mergeSort(C);
    for(int i(0); i < C.size(); i++)
        std::cout << C[i] << endl;
    cout << endl;
    //快速排序问题
    vector<int> D;
    for(int i(0); i < 10; i++)
        D.push_back(rand());
    algorithmLL::quickSort(D);
    for(int i(0); i < D.size(); i++)
        std::cout << D[i] << endl;
    cout << endl;
    //大对象排序问题
    vector<int> E;
    for(int i(0); i < 10; i++)
        E.push_back(rand());
    algorithmLL::largeObjectSort(E);
    for(int i(0); i < E.size(); i++)
        std::cout << E[i] << endl;
    cout << endl;

    //大数乘法
    string a1 = "-1231231231212121212112";
    string b1 = "-123343121212122121212121212121212";
    string result1 = algorithmLL::multiply(a1, b1);
    cout << result1 << endl;

    //strassen矩阵乘法
    algorithmLL::Strassen_class<int> stra;//定义Strassen_class类对象
    int MatrixSize = 0;

    int** MatrixA;    //存放矩阵A
    int** MatrixB;    //存放矩阵B
    int** MatrixC;    //存放结果矩阵

    clock_t startTime_For_Normal_Multipilication ;
    clock_t endTime_For_Normal_Multipilication ;

    clock_t startTime_For_Strassen ;
    clock_t endTime_For_Strassen ;
    srand(time(0));

    cout<<"\n请输入矩阵大小(必须是2的幂指数值(例如:32,64,512,..): ";
    cin>>MatrixSize;

    int N = MatrixSize;//for readiblity.

    //申请内存
    MatrixA = new int *[MatrixSize];
    MatrixB = new int *[MatrixSize];
    MatrixC = new int *[MatrixSize];

    for (int i = 0; i < MatrixSize; i++)
    {
        MatrixA[i] = new int [MatrixSize];
        MatrixB[i] = new int [MatrixSize];
        MatrixC[i] = new int [MatrixSize];
    }


    stra.FillMatrix(MatrixA,MatrixB,MatrixSize);  //矩阵赋值

    stra.PrintMatrix(MatrixA, MatrixSize);
    stra.PrintMatrix(MatrixB, MatrixSize);

    //*******************conventional multiplication test
    cout<<"朴素矩阵算法开始时钟:  "<< (startTime_For_Normal_Multipilication = clock());

    stra.MUL(MatrixA,MatrixB,MatrixC,MatrixSize);//朴素矩阵相乘算法 T(n) = O(n^3)

    cout<<"\n朴素矩阵算法结束时钟: "<< (endTime_For_Normal_Multipilication = clock());

    cout<<"\n矩阵运算结果... \n";
    stra.PrintMatrix(MatrixC,MatrixSize);

    //*******************Strassen multiplication test
    cout<<"\nStrassen算法开始时钟: "<< (startTime_For_Strassen = clock());

    stra.Strassen( N, MatrixA, MatrixB, MatrixC ); //strassen矩阵相乘算法

    cout<<"\nStrassen算法结束时钟: "<<(endTime_For_Strassen = clock());


    cout<<"\n矩阵运算结果... \n";
    stra.PrintMatrix(MatrixC,MatrixSize);

    cout<<"矩阵大小 "<<MatrixSize;
    cout<<"\n朴素矩阵算法: "<<(endTime_For_Normal_Multipilication - startTime_For_Normal_Multipilication)<<" Clocks.."<<(endTime_For_Normal_Multipilication - startTime_For_Normal_Multipilication)/CLOCKS_PER_SEC<<" Sec";
    cout<<"\nStrassen算法:"<<(endTime_For_Strassen - startTime_For_Strassen)<<" Clocks.."<<(endTime_For_Strassen - startTime_For_Strassen)/CLOCKS_PER_SEC<<" Sec\n";

    //closest_pair 最接近点对问题
    int n = 10;
    algorithmLL::Point* p = new algorithmLL::Point[n];
    algorithmLL::Point* px = new algorithmLL::Point[n];
    algorithmLL::Point* py = new algorithmLL::Point[n];
    algorithmLL::Point* pz = new algorithmLL::Point[n];

    algorithmLL::init(p, px, py, n);

    printf("%.3lf\n", algorithmLL::closest_pair(px, py, pz, 0, n - 1));

    k = 3;
    int sizei = pow(2, 3);
    int sizej = pow(2, 3);
    int ** atable = new int *[sizei];
    for (int i = 0; i < sizei; ++i)
    {
        atable[i] = new int[sizej];
    }
    algorithmLL::table(3, atable, sizei, sizej);

    return 0;

}

