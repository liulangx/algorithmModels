#ifndef ALGORITHMMODELS_H
#define ALGORITHMMODELS_H
#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>
#include <math.h>
#include <algorithm>

namespace algorithmLL {
using namespace std;
/* 递 归 问 题 */
/*整数划分问题*/
/*begin*/
int intDivPro_q(int n, int m);
//main
int integerDivisionProblem(int n, int m);
/*end*/
/*Fibonacci数列问题*/
/*begin*/
//main
int fibonacci(int n);
/*end*/
/*阶乘函数问题*/
/*begin*/
//main
int factorial(int n);
/*end*/
/*Ackerman函数问题*/
/*begin*/
//main
int ackerman(int n, int m);
/*end*/
/******************************排列组合问题******************************/
/********************************begin*********************************/
/*描述：输入一个字符串,按字典序打印出该字符串中字符的所有排列。
例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
*/
//来源：http://blog.csdn.net/su_sai/article/details/58608981
//main
vector<string> permutation(string str);
//实现组合排列
void combine(vector<char> s_unused, vector<char> s_used, map<string, int> &m);
/*********************************end**********************************/
/****************************汉诺塔问题****************************/
//来源：https://www.cnblogs.com/xkfz007/articles/2546275.html
/*begin*/
//main
void move(int n, char x,char y, ofstream& fout);
void hannoiRecursive(int n,char a,char b,char c, ofstream& fout);
int hannoi(int n);
/*********************************end**********************************/

/* 分 治 问 题 */
/****************************二分搜索问题****************************/
/*begin*/
//main
//返回在x中的位置
int binarySearch(int* a, int x, int n);
/*********************************end**********************************/

/****************************棋盘覆盖问题****************************/
/*begin*/
//main

void chessBoard(int tr, int tc, int dr, int dc, int size, int ** board, int tile = 1);
/*********************************end**********************************/

/****************************插入排序****************************/
/*begin*/
//main
template <typename Comparable>
void insertionSort(vector<Comparable> & A)
{
    int j, P;
    Comparable Tmp;
    for(P = 1; P < A.size(); P++)
    {
        Tmp = A[P];
        for(j = P; j > 0 && A[j - 1] > Tmp; j--)
            A[j] = A[j-1];
        A[j] = Tmp;
    }
}

/*********************************end**********************************/

/****************************谢尔排序****************************/
/*begin*/
//main
template <typename Comparable>
void shellSort(vector<Comparable> & A)
{
    for(int gap = A.size() / 2; gap > 0; gap /= 2)
    {
        for(int i = gap; i < A.size(); i++)
        {
            Comparable tmp = A[i];
            int j = i;
            for(; j >= gap && tmp < A[j - gap]; j -= gap)
            {
                A[j] = A[j- gap];
            }
            A[j] = tmp;
        }
    }
}

/*********************************end**********************************/

/****************************归并排序****************************/
/*begin*/
template <typename Comparable>
void merge(vector<Comparable> &a, vector<Comparable> & tmpArray, int leftPos, int rightPos, int rightEnd)
{
    int leftEnd = rightPos - 1;
    int tmpPos = leftPos;
    int numElements = rightEnd - leftPos + 1;
     while(leftPos <= leftEnd && rightPos <= rightEnd)
     {
         if(a[leftPos] <= a[rightPos])
             tmpArray[tmpPos ++] = a[leftPos++];
         else
             tmpArray[tmpPos ++] = a[rightPos++];
     }

     while(leftPos <= leftEnd)
         tmpArray[tmpPos++] = a[leftPos++];
     while(rightPos <= rightEnd)
         tmpArray[tmpPos++] = a[rightPos++];

     for(int i = 0; i < numElements; i++, rightEnd--)
         a[rightEnd] = tmpArray[rightEnd];
}

template <typename Comparable>
void mergeSort( vector<Comparable> &a, vector<Comparable> & tmpArray, int left, int right)
{
    if(left < right)
    {
        int center = ( left + right ) / 2;
        mergeSort( a, tmpArray, left, center);
        mergeSort(a, tmpArray, center+1, right);
        merge(a, tmpArray, left, center+1, right);
    }
}
//main
template <typename Comparable>
void mergeSort(vector<Comparable> & a)
{
    vector<Comparable> tmpArray(a.size());
    mergeSort(a, tmpArray, 0, a.size() - 1);
}

/*********************************end**********************************/

/****************************快速排序****************************/
/*begin*/
template <typename Comparable>
void insertionSort(vector<Comparable> & A, int left, int right)
{
    int j, P;
    Comparable Tmp;
    for(P = left; P <= right; P++)
    {
        Tmp = A[P];
        for(j = P; j > 0 && A[j - 1] > Tmp; j--)
            A[j] = A[j-1];
        A[j] = Tmp;
    }
}
template <typename Comparable>
const Comparable & median3(vector<Comparable> & a, int left, int right)
{
    int center = (left + right ) / 2;
    if(a[center] < a[left])
        swap(a[left], a[center]);
    if(a[right] < a[left])
        swap(a[left], a[right]);
    if(a[right] < a[center])
        swap(a[center], a[right]);

    swap(a[center] , a[right - 1]);
    return a[right - 1];
}
template <typename Comparable>
void quickSort(vector<Comparable> & a, int left, int right)
{
    if(left + 10 <= right)
    {
        Comparable pivot = median3(a, left, right);

        int i = left, j = right - 1;
        for(; ;)
        {
            while(a[++i] < pivot) {}
            while(pivot < a[--j]) {}
            if(i < j)
                swap(a[i], a[j]);
            else
                break;
        }
        swap(a[i], a[right - 1]);
        quickSort(a, left, i - 1);
        quickSort(a, i+1, right);
    }
    else
    {
        insertionSort(a, left, right);
    }
}
//main
template <typename Comparable>
void quickSort(vector<Comparable> & a)
{
    quickSort(a, 0, a.size() - 1);
}
/*********************************end**********************************/
/************************大对象排序，利用智能指针****************************/
template <typename Comparable>
class Pointer
{
public:
    Pointer(Comparable * rhs = NULL) : pointee(rhs){}
    bool operator < (const Pointer & rhs) const
    {
        return *pointee < *rhs.pointee;
    }

    bool operator > (const Pointer & rhs) const
    {
        return *pointee > *rhs.pointee;
    }

    operator Comparable * () const
    {
        return pointee;
    }
private:
    Comparable *pointee;
};
//main call quickSort;
template <typename Comparable>
void largeObjectSort(vector<Comparable> & a)
{
    vector<Pointer<Comparable> > p(a.size());
    int i, j, nextj;

    for(i = 0; i < a.size(); i++ )
        p[i] = &a[i];

    quickSort(p);

    for(i = 0; i < a.size(); i ++)
        if(p[i] != &a[i])
        {
            Comparable tmp = a[i];
            for(j = i; p[j] != &a[i]; j = nextj)
            {
                nextj = p[j] - &a[0];
                a[j] = *p[j];
                p[j] = &a[j];
            }
            a[j] = tmp;
            p[j] = &a[j];
        }
}

/*********************************end**********************************/

/************************×××××××大整数乘法××****************************/
//来源：https://github.com/Harlan1994/Algorithms/blob/master/big_num_multiply.cpp
int str2Int(string k); //字符串转整型
string int2Str(int intValue); //整型转字符串
void removePreZero(string & str); //移除字符串前端0字符
void reverse(string::iterator begin, string::iterator end);//反转字符串
string add(string x, string y);//大数加法
string subtract(string &x, string &y);//大数减法
void addPreZero(string &str, int zero_num);//添加字符串前端0字符
string addLastZero(string str, int zero_num);//添加字符串后端0字符
//main
string multiply(string &x, string &y); //大数乘法
string multiply(string x, int y);       //其他形式
string multiply(int x, string y);
string multiply(int x, int y);

/*********************************end**********************************/

/************************×××××××最接近点对问题××****************************/
//来源：csdn
//main

#define DIST(a, b) sqrt(0.0 + (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y))
//int n;
struct Point
{
    __int64_t x, y;
    int id;
};
//Point p[MAXN], px[MAXN], py[MAXN], pz[MAXN];
bool xcmp(const Point a, const Point b);

bool ycmp(const Point a, const Point b);

void init(Point* p, Point* px, Point* py, int & n);

void merge( Point *_pz, Point *_py, int l, int m, int r);

double closest_pair( Point *_px, Point *_py, Point *_pz, int l, int r );


/*********************************end**********************************/

/************************×××××××循环赛日程表××****************************/
//main
void table(int k, int** a, int sizei, int sizej);


/*********************************end**********************************/

}

#endif // ALGORITHMMODELS_H
