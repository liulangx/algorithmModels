#include <iostream>
#include "algorithmmodels.h"

using namespace std;

int main()
{
    int result = algorithmLL::integerDivisionProblem(6, 6);
    cout << result << endl;
    result = algorithmLL::fibonacci(4);
    cout << result << endl;
    result = algorithmLL::factorial(4);
    cout << result << endl;
    result = algorithmLL::ackerman(3, 3);
    cout << result << endl;
    string s = "abc";
    vector<string> resultS = algorithmLL::permutation(s);
    for(vector<string>::iterator itr = resultS.begin(); itr != resultS.end(); ++itr)
    {
        cout << *itr << endl;
    }
    algorithmLL::hannoi(7);
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    result = algorithmLL::binarySearch(a, 3, 10);
    cout << result << endl;
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
    vector<int> A;
    for(int i(0); i < 10; i++)
        A.push_back(rand());
    algorithmLL::insertionSort(A);
    for(int i(0); i < A.size(); i++)
        std::cout << A[i] << endl;
    cout << endl;

    vector<int> B;
    for(int i(0); i < 10; i++)
        B.push_back(rand());
    algorithmLL::shellSort(B);
    for(int i(0); i < B.size(); i++)
        std::cout << B[i] << endl;
    cout << endl;

    vector<int> C;
    for(int i(0); i < 10; i++)
        C.push_back(rand());
    algorithmLL::mergeSort(C);
    for(int i(0); i < C.size(); i++)
        std::cout << C[i] << endl;
    cout << endl;

    vector<int> D;
    for(int i(0); i < 10; i++)
        D.push_back(rand());
    algorithmLL::quickSort(D);
    for(int i(0); i < D.size(); i++)
        std::cout << D[i] << endl;
    cout << endl;

    vector<int> E;
    for(int i(0); i < 10; i++)
        E.push_back(rand());
    algorithmLL::largeObjectSort(E);
    for(int i(0); i < E.size(); i++)
        std::cout << E[i] << endl;
    cout << endl;

    return 0;

}
