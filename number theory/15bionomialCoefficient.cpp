#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)

ll fac[1000001];

ll power(ll a, ll power, ll m)
{
    ll result = 1;
    while (power)
    {
        if (power % 2)
        {
            result = ((result % m)* (a % m)) % m;
            power--;
        }
        a = (a * a) % m;
        power /= 2;
    }
    return result;
}

ll C(ll n, ll k)
{
    ll result = fac[n];
    result = result * power(fac[k], mod - 2, mod) % mod;
    result = result * power(fac[n - k], mod - 2, mod) % mod;

    return result;
}

int main(int argc, char const *argv[]){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t, c, k;
    fac[0] = fac[1] = 1;

    for (int i = 2; i < 1000001; i++)
    {
        fac[i] = ((i % mod) * fac[i - 1]) % mod;
    }
    
    cin>>t;

    while (t--)
    {
        cin>>c>>k;
        cout<<C(c, k)<<endl;
    }
    

    return 0;
}