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

int n;
int arr[20][20];
int dp[20][1<<20];

int fun(int index, int bitmask)
{
    if (index == n)
        return 0;

    if(dp[index][bitmask] != -1)return dp[index][bitmask];

    int ans = INF;

    REP(i, 0, n - 1)
    {
        if (bitmask & (1 << i))
        {
            ans = min(ans, arr[i][index] + fun(index + 1, bitmask ^ (1 << i)));
        }
    }

    return dp[index][bitmask] = ans;
}

void solve()
{
    cin >> n;

    REP(i, 0, n - 1)
    {
        REP(j, 0, n - 1)
        {
            cin >> arr[i][j];
        }
    }

    memset(dp,-1,sizeof(dp));
    cout << fun(0, (1 << n) - 1);
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

    //cin >> t;

    while (t--)
    {
        solve();
    }

    //filptr.close();
    //outpter.close();

    return 0;
}