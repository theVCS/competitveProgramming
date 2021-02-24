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

int arr[1001][1001];

int knapsack(int val[], int wt[], int W, int n)
{
    if (W == 0 || n == 0)
    {
        return 0;
    }

    if (arr[n][W] != -1)
    {
        return arr[n][W];
    }

    else if (wt[n - 1] <= W)
    {
        return arr[n][W] = max(val[n - 1] + knapsack(val, wt, W - wt[n - 1], n - 1), knapsack(val, wt, W, n - 1));
    }
    else
    {
        return arr[n][W] = knapsack(val, wt, W, n - 1);
    }
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

        REP(i, 0, n + 1)
        {
            REP(j, 0, w + 1)
            {
                arr[i][j] = -1;
            }
        }

        cout << knapsack(val, wt, w, n) << endl;
    }

    return 0;
}