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

int n;
vector<int> shirts[101];

void input(int index)
{
    string s;
    getline(cin, s);

    stringstream in(s);
    int a;

    while (in >> a)
    {
        shirts[a].push_back(index);
    }
}

ll dp[101][1 << 10];

ll fun(int shirt = 1, int mask = 0)
{
    if (mask == ((1 << n) - 1))
        return 1;
    else if (shirt == 101)
        return 0;
    else if (dp[shirt][mask] != -1)
        return dp[shirt][mask];
    else
    {
        ll ways = 0;

        for (int people : shirts[shirt])
        {
            if ((mask & (1 << people)) == 0)
                ways = (ways + fun(shirt + 1, mask | (1 << people))) % mod;
        }

        return dp[shirt][mask] = (fun(shirt + 1, mask) + ways) % mod;
    }
}

void solve()
{
    cin >> n;
    cin.ignore();

    REP(i, 1, 100)
    shirts[i].clear();

    REP(i, 0, n - 1)
    {
        input(i);
    }

    memset(dp, -1, sizeof(dp));

    cout << fun() << endl;
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