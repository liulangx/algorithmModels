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
//字符串反转
void algorithmLL::reverse(string::iterator begin, string::iterator end)
{
    char tmp;
    end --;
    while(begin < end)
    {
        tmp = *begin;
        *begin = *end;
        *end = tmp;
        begin++;
        end--;
    }
}

string algorithmLL::add(string x, string y)
{
    string result = "";

    //去掉前置0
    removePreZero(x);
    removePreZero(y);

    //反转字符串方便相加
    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());
    for (int i = 0, j = 0; j || i < max(y.length(), x.length()); i++) {
        int t = j;
        if (i < x.length())t += (x.at(i) - '0');
        if (i < y.length())t += (y.at(i) - '0');
        //c.s[c.len++] = t % 10;
        int q = t % 10;
        result.insert(0, int2Str(q));
        j = t / 10;
    }
    return result;
}

void algorithmLL::removePreZero(string &str)
{
    //去掉前置0,需要考虑只有一个0或者全部是0的情况
    if (str.length() == 1)return;
    int k = 0;
    for (int i = 0; i < str.length(); i++) {
        if (str.at(i) == '0') {
            k++;
        } else {
            break;
        }
    }
    if (k == str.length())str = "0";
    else {
        str = str.substr(k);
    }
}

string algorithmLL::int2Str(int intValue)
{
    string result;
    stringstream stream;
    stream << intValue;//将int输入流
    stream >> result;//从stream中抽取前面放入的int值
    return result;
}

int algorithmLL::str2Int(string k)
{
    int back;
    stringstream instr(k);
    instr >> back;
    return back;
}

string algorithmLL::subtract(string &x, string &y)
{
    string result = "";

    //去掉前置0
    removePreZero(x);
    removePreZero(y);

    int len_x = x.length();
    int len_y = y.length();
    int len = len_x > len_y ? len_x : len_y;
    int *tempResult = (int *) malloc(sizeof(int) * len);

    string sign;
    if (len_x > len_y) {// x - y为正数
        sign = "+";
    } else if (len_x < len_y) { //x-y为负数
        sign = "-";
    } else { //长度相同则判断各位的大小
        int i;
        for (i = 0; i < len_x; i++) {
            if (x.at(i) == y.at(i))continue;
            else if (x.at(i) > y.at(i)) {
                sign = "+";
                break;
            } else {
                sign = "-";
                break;
            }
        }

        //说明没有break，说明x == y
        if (i == len_x) {
            return "0";
        }
    }

    //反转字符串方便相减
    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());

    int q = 0;
    //若x大，则直接相减，否则用y-x，并且最终加上负号
    for (int i = 0; i < len; i++) {
        int aint = i < len_x ? x.at(i) - '0' : 0;
        int bint = i < len_y ? y.at(i) - '0' : 0;
        if (sign.at(0) == '+') {
            tempResult[q++] = aint - bint;
        } else {
            tempResult[q++] = bint - aint;
        }
    }

    for (int i = 0; i < q; i++) {
        if (tempResult[i] < 0) {
            tempResult[i + 1] -= 1;
            tempResult[i] += 10;
        }
    }
    q--;
    while (tempResult[q] == 0)q--;
    for (int i = q; i >= 0; i--) {
        result += int2Str(tempResult[i]);
    }

    if (sign.at(0) == '-')return sign + result;
    return result;
}

void algorithmLL::addPreZero(string &str, int zero_num)
{
    for(int i = 0; i < zero_num; ++i) str.insert(0, "0");
}

string algorithmLL::addLastZero(string str, int zero_num)
{
    string s = str;
    for(int i = 0; i < zero_num; ++i) s += "0";
    return s;
}

string algorithmLL::multiply(string &x, string &y)
{
    bool flag_x = false; //正
    bool flag_y = false;
    bool flag; // 最终结果的正负号

    //先处理正负号
    if (x.at(0) == '-') {//负
        flag_x = true;
        x = x.substr(1);
    }

    if (y.at(0) == '-') {
        flag_y = true;
        y = y.substr(1);
    }
    //两个都为负或者两个都为正，则最终为正
    if ((flag_x && flag_y) || (!flag_x && !flag_y)) {
        flag = false;
    } else {
        flag = true;//否则结果为负
    }

    /**
     * 预处理，将x和y处理成相同位数的两个数
     * x和y的长度必须是2的指数倍，这样才能递归分治计算
     * 所以需要将x和y添加前置0，将长度处理为可行的最小的长度
     *
     * 处理过后x和y的长度将统一
     */
    int init_len = 4;
    if (x.length() > 2 || y.length() > 2) { // 长度大于2时，最小长度应该为4，故初始值为4
        if (x.length() >= y.length()) {
            while (init_len < x.length())init_len *= 2; //计算两个数最终的长度
            //添加前置0
            if (x.length() != init_len) {
                addPreZero(x, init_len - x.length());
            }
            addPreZero(y, init_len - y.length());
        } else {
            while (init_len < y.length())init_len *= 2;
            //添加前置0
            addPreZero(x, init_len - x.length());
            if (y.length() != init_len) {
                addPreZero(y, init_len - y.length());
            }
        }
    }

    if (x.length() == 1) {
        addPreZero(x, 1);
    }
    if (y.length() == 1) {
        addPreZero(y, 1);
    }

    int n = x.length();

    string result;

    string a1, a0, b1, b0;
    if (n > 1) {
        a1 = x.substr(0, n / 2);
        a0 = x.substr(n / 2, n);
        b1 = y.substr(0, n / 2);
        b0 = y.substr(n / 2, n);
    }

    if (n == 2) { //长度为2时，结束递归
        int x1 = str2Int(a1);
        int x2 = str2Int(a0);
        int y1 = str2Int(b1);
        int y2 = str2Int(b0);
        int z = (x1 * 10 + x2) * (y1 * 10 + y2);
        result = int2Str(z);
    } else {
        string c2 = multiply(a1, b1);
        string c0 = multiply(a0, b0);
        string temp_c1_1 = add(a0, a1);
        string temp_c1_2 = add(b1, b0);
        string temp_c1_3 = add(c2, c0);
        string temp_c1 = multiply(temp_c1_1, temp_c1_2);
        string c1 = subtract(temp_c1, temp_c1_3);
        string s1 = addLastZero(c1, n / 2);
        string s2 = addLastZero(c2, n);
        result = add(add(s1, s2), c0);
    }

    if (flag) { //结果为负数
        result.insert(0, "-");
    }

    return result;
}


string algorithmLL::multiply(string x, int y)
{
    string temp = int2Str(y);
    return multiply(x, temp);
}

string algorithmLL::multiply(int x, string y)
{
    string temp = int2Str(x);
    return multiply(temp, y);
}

string algorithmLL::multiply(int x, int y)
{
    string temp1 = int2Str(x);
    string temp2 = int2Str(y);
    return multiply(temp1, temp2);
}

bool algorithmLL::xcmp(const algorithmLL::Point a, const algorithmLL::Point b)
{
    return a.x < b.x;
}

bool algorithmLL::ycmp(const algorithmLL::Point a, const algorithmLL::Point b)
{
    return a.y < b.y;
}

void algorithmLL::init(algorithmLL::Point *p, algorithmLL::Point *px, algorithmLL::Point *py, int &n)
{
    int i;
//    scanf("%d",&n);
    for( i = 0; i < n; i++ )
    {
//        scanf("%I64d %I64d", &p[ i ].x, &p[ i ].y);
        p[i].x = i; p[i].y = n-i;
        p[ i ].id = i; //p数组保持读入时的顺序，id记录读入时的顺序
        px[ i ] = p[ i ];
    }
    cout << "p: " << endl;
    for( i = 0; i < n; i++ )
        cout << p[i].x << " " << p[i].y << " " << p[i].id<< endl;

    sort( px, px + n, xcmp ); //px数组保持以x由小到大的顺序，id记录的还是读入时的顺序
    cout << "px: " << endl;
    for( i = 0; i < n; i++ )
        cout << px[i].x << " " << px[i].y << " " << px[i].id << endl;
    for( i = 0; i < n; i++ )
    {
        py[ i ] = px[ i ];
        py[ i ].id = i;
    }
    cout << "py: " << endl;
    for( i = 0; i < n; i++ )
        cout << py[i].x << " " << py[i].y << " " << py[i].id << endl;
    sort( py, py + n, ycmp ); //py数组保持以y由小到大的顺序，id记录的是以x排列的顺序
    cout << "py: " << endl;
    for( i = 0; i < n; i++ )
        cout << py[i].x << " " << py[i].y << " " << py[i].id << endl;
}

void algorithmLL::merge(algorithmLL::Point *_pz, algorithmLL::Point *_py, int l, int m, int r)
{

    int i = l, j = m + 1, k = l;
    while( i <= m && j <= r )
        if( _pz[ i ].y < _pz[ j ].y )
            _py[ k++ ] = _pz[ i++ ];
        else
            _py[ k++ ] = _pz[ j++ ];
    if( i > m )
        for(int p = j; p <= r; p++ )
            _py[ k++ ] = _pz[ p ];
    else
        for(int p = i; p <= m; p++ )
            _py[ k++ ] = _pz[ p ];
}

double algorithmLL::closest_pair(algorithmLL::Point *_px, algorithmLL::Point *_py, algorithmLL::Point *_pz, int l, int r)
{
    if( r - l == 1 )
        return DIST( _px[ l ], _px[ r ] );
    if( r - l == 2 )
    {
        double d1 = DIST( _px[ l ], _px[ l + 1 ] );
        double d2 = DIST( _px[ l + 1 ], _px[ r ] );
        double d3 = DIST( _px[ l ], _px[ r ]);
        if( d1 <= d2 && d1 <= d3)
            return d1;
        else if( d2 <= d3 )
            return d2;
        else
            return d3;
    }
    int m = ( l + r ) / 2;
    int f = l, g = m + 1;
    int i, j, k;
    for( i = l; i <= r; i++ )
        if( _py[ i ].id > m)
            _pz[ g++ ] = _py[ i ];
        else
            _pz[ f++ ] = _py[ i ];
    double best = closest_pair( _px, _pz, _py, l , m );
    double right = closest_pair( _px, _pz, _py, m + 1, r );
    if( best > right )
    {
        best = right;
    }
    merge( _pz, _py , l, m, r );
    k = l;
    for( i = l; i <= r; i++ )
        if( fabs( _px[ m ].x - _py[ i ].x ) < best )
            _pz[ k++ ] = _py[ i ];
    for( i = l; i < k; i++ )
        for( j = i + 1; j < k && _pz[ j ].y - _pz[ i ].y < best; j++ )
        {
            double tmp = DIST( _pz[ i ], _pz[ j ] );
            if( tmp < best )
                best = tmp;
        }
    return best;
}

void algorithmLL::table(int k, int **a, int sizei, int sizej)
{
    int n = 1;
    for (int i = 1; i <= k; i++) n *= 2;
    for (int i = 0; i < sizei; ++i) a[i][0] = i + 1;//将矩阵第一列赋值为1-2^k
    for (int i = 0; i < sizej; ++i) a[0][i] = i + 1;//将矩阵第一行赋值为1-2^k
    int m = 1;
    for(int s = 0; s < k; ++s)
    {
        n /= 2;
        for (int t = 0; t < n; ++t)
        {
            for (int i = m; i < 2 * m; ++i)
            {
                for (int j = m; j < 2 * m; ++j)
                {
                    a[i][j+t*m*2] = a[i-m][j+t*2*m-m];
                    a[i][j+t*m*2-m] = a[i-m][j+t*2*m];
                }
            }
        }
        m*=2;
    }
    for (int i = 0; i < sizei; ++i)
        for (int j = 0; j < sizej; ++j)
        {
            cout << a[i][j] << " ";
            if ((j+1) % sizej == 0) cout << endl;
        }
}
