#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll modExp(ll a, ll n, ll p)
{
    ll res = 1;

    while (n)
    {
        if (n % 2)
        {
            res = (res * a) % p;
            n--;
        }
        a = (a * a) % p;
        n /= 2;
    }
    return res;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout<<modExp(15, 2, 81);

    return 0;
}