#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define l 10000000000
#define u 10001000000
bool primes[u - l + 1];
vector<ll> prePrimes;

void init()
{
    ll b = 10001000000;
    for (ll i = 2; i * i <= b; i++)
    {
        if (b % i == 0)
        {
            prePrimes.push_back(i);

            while (b % i == 0)
            {
                b /= i;
            }
        }
    }

    for (ll P : prePrimes)
    {
        for (ll i = l; i <= u; i++)
        {
            if (i % P == 0)
            {
                primes[i - l] = true;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    init();

    for (ll i = l; i <= u; i++)
    {
        if (!primes[i - l])
        {
            cout<<i<<" ";
        }
    }
    

    return 0;
}