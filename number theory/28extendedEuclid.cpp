#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)

int extendedEuclid(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = extendedEuclid(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

int extEuclid(int a, int b, int &x, int &y)
{
    int temp;

    while (b)
    {
        a = b;
        b = temp % b;
    }
    return b;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int x, y;
    int d = extendedEuclid(81, 57, x, y);
    cout << 81 << "*" << x << " + " << 57 << "*" << y << " = " << d;

    return 0;
}