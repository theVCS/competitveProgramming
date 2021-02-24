#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 1000001
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int knapsack(int val[], int wt[], int W, int n)
{
    int dp[n + 1][W + 1];

    REP(i, 0, W + 1)
    {
        dp[0][i] = 0;
    }

    REP(i, 1, n + 1)
    {
        dp[i][0] = 0;
    }

    REP(i, 1, n + 1)
    {
        REP(j, 1, W + 1)
        {
            if (wt[i - 1] <= j)
            {
                dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][W];
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n, w;

    cin >> t;

    while (t--)
    {
        cin >> n >> w;

        int val[n], wt[n];

        REP(i, 0, n)
        {
            cin >> val[i];
        }

        REP(i, 0, n)
        {
            cin >> wt[i];
        }

        cout << knapsack(val, wt, w, n) << endl;
    }

    return 0;
}