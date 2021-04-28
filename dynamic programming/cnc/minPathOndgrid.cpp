#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 1009
#define INF 1000000000
#define endl "\n"
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};
// while (T < q[i].t)
//     do_update(++T);
// while (T > q[i].t)
//     undo(T--);
// while (R < q[i].r)
//     add(++R);
// while (L > q[i].l)
//     add(--L);
// while (R > q[i].r)
//     remove(R--);
// while (L < q[i].l)
//     remove(L++);

int cost[maxN][maxN];

void solve()
{
    int n, m;

    cin >> n >> m;

    REP(i, 1, n + 1)
    REP(j, 1, m + 1)
    cin >> cost[i][j];

    REP(i, 0, n + 1)
    cost[i][0] = cost[i][m + 1] = INF;

    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = 1; j <= m; j++)
        {
            cost[i][j] += min({cost[i + 1][j - 1], cost[i + 1][j], cost[i + 1][j + 1]});
        }
    }

    REP(i, 1, n + 1)
    {
        REP(j, 1, m + 1)
            cout << cost[i][j] << " ";
        cout << endl;
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // ifstream fi("input.txt");
    // ofstream fo("output.txt");

    // fi >> input;
    // fo << output;

    int t = 1;

    //cin >> t;

    while (t--)
    {
        solve();
    }

    //fi.close();
    //fo.close();

    return 0;
}