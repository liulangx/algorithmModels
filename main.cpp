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

    return 0;
}
