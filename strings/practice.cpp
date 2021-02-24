#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 100001
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

ll binExp(ll a, ll power)
{
    ll res = 1;

    while (power)
    {
        if (power & 1)
            res = (res * a) % mod;

        a = (a * a) % mod;
        power >>= 1;
    }
    return res;
}

ll dp[maxN], inv[maxN];

void init(string s)
{
    ll power = 103, p = 103;
    dp[0] = s[0] - 'a' + 1;
    inv[0] = 1;

    for (int i = 1; i < s.size(); i++)
    {
        dp[i] = (dp[i - 1] + (s[i] - 'a' + 1) * power) % mod;
        inv[i] = binExp(power, mod - 2);
        power = (power * p) % mod;
    }
}

ll subHash(int l, int r)
{
    ll res = dp[r];

    if (l > 0)
        res = (res - dp[l - 1] + mod) % mod;

    return (res * inv[l]) % mod;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;

    cin >> s;
    init(s);

    int l, r;

    while (true)
    {
        cin >> l >> r;
        cout << subHash(l, r) << endl;
    }

    return 0;
}