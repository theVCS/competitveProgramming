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
int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

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
int arr[10][10];
bool vis[10][10];
bool hasQueen[10][10];

bool isVaild(int x, int y)
{
    if (x < 1 || y < 1 || x > n || y > n || vis[x][y])
        return false;
    return true;
}

void queen(int x, int y, int q)
{
    if (q == 0)
    {
        REP(i, 1, n)
        {
            REP(j, 1, n)
            {
                if (hasQueen[i][j])
                {
                    cout << "q";
                }
                else
                {
                    cout << "-";
                }
            }
            cout << endl;
        }
        cout << endl;
    }

    vis[x][y] = true;

    REP(i, 0, 3)
    {
        int X = x + dx[i];
        int Y = y + dy[i];

        if (isVaild(X, Y))
        {
            hasQueen[x][y] = false;
            queen(X, Y, q);

            hasQueen[x][y] = true;
            queen(X, Y, q - 1);
            hasQueen[x][y] = false;
        }
    }

    vis[x][y] = false;
}

void solve()
{
    cin >> n;

    queen(1, 1, n);
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