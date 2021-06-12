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
#define printd(x) cout << fixed << setprecision(10) << x
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

int n, m;

void generate_next_masks(int i, int curr_mask, int nexmask, vector<int> &next_masks)
{
    if (i == n + 1)
    {
        next_masks.push_back(nexmask);
    }
    else if (curr_mask & (1 << i))
    {
        generate_next_masks(i + 1, curr_mask, nexmask, next_masks);
    }
    else if (i == n)
    {
        generate_next_masks(i + 1, curr_mask, (nexmask | (1 << i)), next_masks);
    }
    else
    {
        generate_next_masks(i + 1, curr_mask, (nexmask | (1 << i)), next_masks);

        if ((curr_mask & (1 << (i + 1))) == 0)
            generate_next_masks(i + 2, curr_mask, nexmask, next_masks);
    }
}

ll dp[1001][(1 << 11) + 1];

ll fun(int col = 1, int mask = 0)
{

    if (col == m + 1)
    {
        return mask == 0;
    }
    else if (dp[col][mask] != -1)
        return dp[col][mask];
    else
    {
        ll ans = 0;
        vector<int> next_masks;
        generate_next_masks(1, mask, 0, next_masks);

        for (int nexmask : next_masks)
        {
            ans = (ans + fun(col + 1, nexmask)) % mod;
        }

        return dp[col][mask] = ans;
    }
}

void solve()
{
    cin >> n >> m;

    memset(dp, -1, sizeof(dp));

    cout << fun();
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