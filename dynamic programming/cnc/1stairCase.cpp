#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (ll i = a; i < b; i++)
#define maxN 1000001
ll dp[maxN];

ll init(int n)
{
    if (n == 1 || n == 2)
    {
        return n;
    }
    else if (dp[n] != -1)
    {
        return dp[n];
    }
    else
    {
        dp[n] = (init(n - 1) + init(n - 2)) % mod;
    }

    return dp[n];
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(dp, -1, maxN);

    int n;

    cin >> n;

    cout << init(n);

    return 0;
}