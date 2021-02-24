#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 1000001
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

ll binexp(ll n, ll pow, ll m)
{
    ll res = 1;
    n %= m;

    while (pow)
    {
        if (pow % 2)
        {
            pow--;
            res = (res * n) % m;
        }
        pow /= 2;
        n = (n * n) % m;
    }
    return res;
}

bool isComposite(ll a, ll s, ll d, ll n)
{
    ll res = binexp(a, d, n);

    if (res == 1 || res == n - 1)
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

bool isPrime(ll n)
{
    if (n <= 4)
    {
        return (n == 2 || n == 3);
    }

    ll s = 0, d = n - 1;

    while (d % 2 == 0)
    {
        s++;
        d /= 2;
    }

    for (ll a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37})
    {
        if (a == n)
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

    ll t, n;

    cin >> t;

    while (t--)
    {
        cin >> n;

        if (isPrime(n))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}