#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 1001
#define INF 0x3f3f3f3f
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

int arr[maxN];
bool dp[maxN + 1][maxN + 1];

void solve()
{
    int n, m;

    cin >> n >> m;

    REP(i, 0, n)
    cin >> arr[i];

    REP(i, 0, n + 1)
    dp[i][0] = true;

    REP(i, 1, n + 1)
    {
        REP(j, 1, m + 1)
        {
            if (j >= arr[i - 1])
            {
                dp[i][j] = dp[i - 1][j - arr[i]] || dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
}

bool fun(int arr[], int n, int sum)
{
    if (sum == 0)
        return 1;
    else if (n == 0)
        return false;
    else if (arr[n - 1] <= sum)
    {
        return fun(arr, n - 1, sum - arr[n - 1]) || fun(arr, n - 1, sum);
    }
    else
    {
        return fun(arr, n - 1, sum);
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

    cin >> t;

    while (t--)
    {
        solve();
    }

    //fi.close();
    //fo.close();

    return 0;
}