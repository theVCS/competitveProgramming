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
    if (W == 0 || n == 0)
    {
        return 0;
    }
    else if (wt[n - 1] <= W)
    {
        return max(val[n - 1] + knapsack(val, wt, W - wt[n - 1], n - 1), knapsack(val, wt, W, n - 1));
    }
    else
    {
        return knapsack(val, wt, W, n - 1);
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int val[] = {50, 30, 2, 26, 50};
    int wt[] = {2, 3, 5, 1, 4};
    int w = 5;

    cout << knapsack(val, wt, w, 5);

    return 0;
}