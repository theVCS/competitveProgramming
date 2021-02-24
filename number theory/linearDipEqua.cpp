#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 1000001
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

ll gcd(ll a, ll b, ll &x, ll &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    ll d, x1, y1;
    d = gcd(b, a % b, x1, y1);

    x = y1;
    y = x1 - (a / b) * y1;

    return d;
}

bool findAnySol(ll a, ll b, ll c, ll &x, ll &y)
{
    // a and b can also be negative values
    ll d = gcd(abs(a), abs(b), x, y);

    if (c % d)
    {
        return false;
    }

    x *= (c / d) * (a / abs(a));
    y *= (c / d) * (b / abs(b));
    return true;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll a = 2, b = 4, c = 8, x, y;

    if (findAnySol(a, b, c, x, y))
    {
        cout << "x = " << x << endl;
        cout << "y = " << y << endl;
    }

    return 0;
}