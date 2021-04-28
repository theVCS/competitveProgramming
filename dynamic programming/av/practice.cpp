#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 1000001
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

void scs(string s, string t, int n, int m)
{
    int dp[n + 1][m + 1];
    memset(dp, 0, sizeof(dp));

    REP(i, 1, n + 1)
    {
        REP(j, 1, m + 1)
        {
            if (s[i - 1] == t[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    int i = n, j = m;
    string res;

    while (i && j)
    {
        if (s[i - 1] == t[j - 1])
        {
            res = s[i - 1] + res;
            i--, j--;
        }
        else
        {
            if (dp[i - 1][j] > dp[i][j - 1])
            {
                res = s[i - 1] + res;
                i--;
            }
            else
            {
                res = t[j - 1] + res;
                j--;
            }
        }
    }

    while (i)
    {
        res = s[i - 1] + res;
        i--;
    }

    while (j)
    {
        res = t[j - 1] + res;
        j--;
    }
    cout << res;
}

void solve()
{
    string s, t;
    cin >> s >> t;
    scs(s, t, s.size(), t.size());
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