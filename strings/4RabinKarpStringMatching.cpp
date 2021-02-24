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

ll dp[maxN], po[maxN];

ll getHash(string s)
{
    ll res = 0;
    ll p = 1, power = 103;

    for (int i = 0; i < s.size(); i++)
    {
        res = (res + (s[i] - 'a' + 1) * p) % mod;
        p = (p * power) % mod;
    }

    return res;
}

void init(string s)
{
    ll power = 103, p = 103;
    dp[0] = s[0] - 'a' + 1;
    po[0] = 1;

    for (int i = 1; i < s.size(); i++)
    {
        dp[i] = (dp[i - 1] + (s[i] - 'a' + 1) * power) % mod;
        po[i] = p;
        p = (p * power) % mod;
    }
}

ll getSubHash(int l, int r)
{
    ll res = dp[r];

    if (l)
        res = (res - dp[l - 1] + mod) % mod;

    return res;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s, p;
    int l, r;

    cin >> s >> p;

    ll phash = getHash(p);

    while (true)
    {
        cin >> l >> r;

        if ((phash * po[l]) % mod == getSubHash(l, r))
            cout << l << endl;
    }

    return 0;
}