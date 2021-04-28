#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define RREP(i, a, b) for (int i = a; i >= b; i--)
#define maxN 1000001
#define endl "\n"
#define INF 1000000000
#define all(x) (x).begin(), (x).end()
#define pi 3.141592653589793238
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

ll binExp(ll a, ll power, ll m = mod)
{
    ll res = 1;

    while (power)
    {
        if (power & 1)
            res = (res * a) % m;
        a = (a * a) % m;
        power >>= 1;
    }
    return res;
}

int n, k;

ll dp[1001][1001][2];

ll fun(int index, int k, int left = 1)
{
    if (k == 0)
        return -1;
    else if (index < 1 && left)
        return 0;
    else if (index > n && left == 0)
    {
        return 0;
    }
    else if (dp[index][k][left] != -1)
    {
        return dp[index][k][left];
    }
    
    if (left)
    {
        ll ans = fun(index + 1, k - 1, 0) % mod;

        if (ans == -1)
        {
            ans = fun(index - 1, k, 1) % mod;
        }
        else
        {
            ans = (ans + 1 + fun(index - 1, k, 1)) % mod;
        }

        return dp[index][k][left] = ans;
    }
    else
    {
        ll ans = fun(index - 1, k - 1, 1) % mod;

        if (ans == -1)
        {
            ans = fun(index + 1, k, 0) % mod;
        }
        else
        {
            ans = (ans + 1 + fun(index + 1, k, 0)) % mod;
        }

        return dp[index][k][left] = ans;
    }
}

void solve()
{
    cin >> n >> k;
    memset(dp,-1,sizeof(dp));
    cout << fun(n, k) + 1 << endl;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // ifstream filptr("input.txt");
    // ofstream outpter("output.txt");

    // filptr >> input;
    // outpter << output;

    int t = 1;

    cin >> t;

    while (t--)
    {
        solve();
    }

    //filptr.close();
    //outpter.close();

    return 0;
}