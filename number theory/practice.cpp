#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 1000001
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

ll binExp(ll a, ll pow, ll m)
{
    ll res = 1;

    while (pow)
    {
        if (pow & 1)
            res = (res * a) % m;

        a = (a * a) % m;
        pow >>= 1;
    }

    return res;
}

bool isComposite(ll a, ll s, ll d, ll n)
{
    ll res = binExp(a, d, n);

    if (res == n - 1 || res == 1)
    {
        return false;
    }

    for (ll i = 1; i < s; i++)
    {
        res = (res * res) % n;

        if (res == n - 1)
        {
            return false;
        }
    }
    return true;
}

bool millerRabin(ll n)
{
    if (n <= 4 || n % 2 == 0)
        return (n == 2) || (n == 3);

    ll d = n - 1, s = 0;

    while (d % 2 == 0)
    {
        s++;
        d /= 2;
    }

    for (ll a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37})
    {
        if (n == a)
        {
            return true;
        }

        if (isComposite(a, s, d, n))
        {
            return false;
        }
    }
    return true;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    ll n;

    cin >> t;

    while (t--)
    {
        cin >> n;

        if (millerRabin(n))
        {
            cout << "Prime" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }

    return 0;
}