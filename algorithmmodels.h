#ifndef ALGORITHMMODELS_H
#define ALGORITHMMODELS_H
#include <iostream>
#include <vector>
#include <map>
#include <fstream>
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

}

#endif // ALGORITHMMODELS_H
