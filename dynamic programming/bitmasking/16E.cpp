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
#define maxN 19
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

int n;
double prob[maxN][maxN];
double dp[1 << 19];

double nc2(int n)
{
    double pro = (n * (n - 1)) / 2;
    return pro;
}

double fun(int mask)
{
    if (dp[mask] > -0.9)
    {
        return dp[mask];
    }

    vector<int> present;
    vector<int> absent;

    REP(i, 0, n - 1)
    {
        if (mask & (1 << i))
            present.push_back(i);
        else
            absent.push_back(i);
    }

    int total_fishes = present.size();

    if (total_fishes == n)
        return 1;

    double p = 0;
    double nc = nc2(total_fishes + 1);

    for (int absEle : absent)
    {
        double pro = 0;
        for (int preEle : present)
        {
            pro += prob[preEle][absEle];
        }

        pro /= nc;
        p += pro * fun(mask | (1LL << absEle));
    }

    return dp[mask] = p;
}

void solve()
{
    cin >> n;

    REP(i, 0, n - 1)
    {
        REP(j, 0, n - 1)
        {
            cin >> prob[i][j];
        }
    }

    memset(dp, -1, sizeof(dp));

    REP(i, 0, n - 1)
    {
        cout << fixed << setprecision(6) << fun(1 << i) << " ";
    }
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