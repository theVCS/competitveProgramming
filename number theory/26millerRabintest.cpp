#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)

ll binexp(ll n, ll power, ll m)
{
    ll res = 1;

    while (power)
    {
        if (power % 2)
        {
            power--;
            res = (res * n) % m;
        }
        power /= 2;
        n = (n * n) % m;
    }
    return res;
}

bool checkComp(ll a, ll d, ll s, ll n)
{
    ll rem = binexp(a, d, n);
    
    if (rem == 1 || rem == n - 1)
    {
        return false;
    }

    for (ll i = 1; i < s; i++)
    {
        rem = (rem * rem) % n;

        if (rem == n - 1)
        {
            return false;
        }
    }
    return true;
}

bool millerRabin(ll n)
{
    if (n < 4)
        return n == 2 || n == 3;

    ll s = 0, d = n - 1;
    ll arr[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
    int count = sizeof(arr) / sizeof(ll);

    while (d % 2 == 0)
    {
        d /= 2;
        s++;
    }

    for (int i = 0; i < count; i++)
    {
        if (n == arr[i])
        {
            return true;
        }

        if (checkComp(arr[i], d, s, n))
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

        if (millerRabin(n))
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