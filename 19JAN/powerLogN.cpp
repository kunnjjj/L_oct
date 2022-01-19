#include <iostream>
using namespace std;
int powerIt(int a, int b)
{
    int res = 1;
    int mul = a;
    while (b > 0)
    {
        if (b & 1)
        {
            res *= mul;
        }
        mul *= mul;
        b >>= 1;
    }
    return res;
}
int power(int a, int b)
{
    if (b == 0)
    {
        return 1;
    }

    int halfKaAns = power(a, b / 2);

    if (b % 2 == 0)
    {
        return halfKaAns * halfKaAns;
    }
    else
    {
        return halfKaAns * halfKaAns * a;
    }
}
int main()
{
    int n, p;
    cin >> n >> p;

    cout << power(n, p) << endl;
    cout << powerIt(n, p) << endl;
    return 0;
}
