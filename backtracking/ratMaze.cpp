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
#define maxN 10
#define endl "\n"
#define INF 1000000000
#define all(x) (x).begin(), (x).end()
#define pi 3.141592653589793238
#define printd(x) cout << fixed << setprecision(10) << x
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};
char p[] = {'U', 'L', 'D', 'R'};

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
int arr[maxN][maxN];
bool vis[maxN][maxN];

bool isValid(int x, int y)
{
    if (x < 1 || x > n || y < 1 || y > n || vis[x][y] || arr[x][y] == 0)
        return false;

    return true;
}

void dfs(int x = 1, int y = 1, string path = "")
{
    if (x == n && y == n)
    {
        cout << path << " ";
        return;
    }

    vis[x][y] = true;

    REP(i, 0, 3)
    {
        int X = x + dx[i];
        int Y = y + dy[i];

        if (isValid(X, Y))
        {
            path.push_back(p[i]);
            dfs(X, Y, path);
            path.pop_back();
        }
    }

    vis[x][y] = false;
}

void solve()
{
    cin >> n;

    REP(i, 1, n)
    {
        REP(j, 1, n)
        {
            cin >> arr[i][j];
        }
    }

    dfs();
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