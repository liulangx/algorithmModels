#include "algorithmmodels.h"
using namespace std;

int algorithmLL::intDivPro_q(int n, int m)
{
    if((n < 1) || (m < 1)) return 0;
    if((n == 1) || (m == 1)) return 1;
    if(n < m) return intDivPro_q(n, n);
    if(n == m) return intDivPro_q(n, m - 1) + 1;
    return intDivPro_q(n, m - 1) + intDivPro_q(n-m, m);
}

int algorithmLL::integerDivisionProblem(int n, int m)
{
//    int n;
//    int m;
//    cout << "请输入正整数和其划分数：" << endl;
//    cin >> n >> m;
    int result = intDivPro_q(n, m);
//    cout << result << endl;
    return result;
}

int algorithmLL::fibonacci(int n)
{
    if(n<=2) return 1;
    return fibonacci(n-1) + fibonacci(n-2);
}

int algorithmLL::factorial(int n)
{
    if(n==0) return 1;
    return n*factorial(n-1);
}

int algorithmLL::ackerman(int n, int m)
{
    if(n==1 && m==0) return 2;
    if(n==0) return 1;//m>=0
    if(m==0) return n + 2; // n>=2
    int newN = ackerman(n-1, m);

    return ackerman(newN, m-1);
}
//main
vector<string> algorithmLL::permutation(string str)
{
    vector<char> s_unused;
    vector<char> s_used;
    map<string, int> m;

    for(int i = 0; i < str.length(); ++i)
    {
        s_unused.push_back(str[i]);
    }
    combine(s_unused, s_used, m);
    vector<string> rtn;
    for(map<string, int>::iterator it = m.begin(); it != m.end(); it++)
    {
        rtn.push_back(it->first);
    }
    return rtn;
}

void algorithmLL::combine(vector<char> s_unused, vector<char> s_used, map<string, int> &m)
{
    if(s_unused.empty())
    {
        string s;
        for(vector<char>::iterator it = s_used.begin(); it != s_used.end(); it++)
        {
            s += *it;
        }
        m[s] = 1;
        return;
    }
    for(vector<char>::iterator it = s_unused.begin(); it != s_unused.end(); it++)
    {
        //依次将未排列的元素移入已排列的容器中
        char tmp = *it;
        s_used.push_back(tmp);
        s_unused.erase(it);
        combine(s_unused, s_used, m);
        s_unused.insert(it, tmp);
        s_used.pop_back();
    }
}

void algorithmLL::move(int n, char x, char y, ofstream &fout)
{
    fout<< "move " << n << " from " << x << " to " << y << endl;
    cout<< "move " << n << " from " << x << " to " << y <<endl;
}

void algorithmLL::hannoiRecursive(int n, char a, char b, char c, ofstream &fout)
{
    if(n == 1)
        move(1,a,c, fout);
    else
    {
        hannoiRecursive(n-1, a, c, b, fout);
        move(n,a,c, fout);
        hannoiRecursive(n-1, b, a, c, fout);
    }
}

int algorithmLL::hannoi(int n)
{
    ofstream fout("out.txt");
    fout<<"solution for level" << n << " hannoi:"<<endl;
    hannoiRecursive(n,'a','b','c', fout);
    fout.close();
    cout<<"done!"<<endl;
    return 0;
}

int algorithmLL::binarySearch(int *a, int x, int n)
{
    int left = 0;
    int right = n - 1;
    while(left <= right)
    {
        int middle = (left + right) / 2;
        if(x == a[middle]) return middle;
        if(x > a[middle]) left = middle + 1;
        else right = middle - 1;
    }
    return -1;
}

void algorithmLL::chessBoard(int tr, int tc, int dr, int dc, int size, int **board, int tile)
{
    if(size == 1) return;
    int t = tile ++, //L型骨牌号
            s = size / 2;
    if(dr < tr + s && dc < tc + s)
        chessBoard(tr, tc, dr, dc, s, board, tile);
    else //此棋盘无特殊方格
    {
        //用t号L型骨牌覆盖右下角
        board[tr+s-1][tc+s-1] = t;
        //覆盖其余方格
        chessBoard(tr, tc, tr+s-1, tc+s-1, s, board, tile);
    }

    if(dr < tr + s && dc >= tc + s)
        chessBoard(tr, tc+s, dr, dc, s, board, tile);
    else
    {
        board[tr+s-1][tc+s] = t;
        chessBoard(tr, tc+s, tr+s-1, tc+s, s, board, tile);
    }

    if(dr >= tr+s && dc < tc+s)
    {
        chessBoard(tr+s, tc, dr, dc, s, board, tile);
    }
    else
    {
        board[tr+s][tc+s-1]=t;
        chessBoard(tr+s, tc, tr+s, tc+s-1, s, board, tile);
    }

    if(dr>=tr+s && dc>=tc+s)
    {
        chessBoard(tr+s, tc+s, dr, dc, s, board, tile);
    }
    else
    {
        board[tr+s][tc+s]=t;
        chessBoard(tr+s, tc+s, tr+s, tc+s, s, board, tile);
    }
}
