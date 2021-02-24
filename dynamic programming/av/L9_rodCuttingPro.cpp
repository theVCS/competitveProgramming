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
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int uk(int len, int price[], int n)
{
    int t[n + 1][len + 1];

    for (int i = 0; i < len + 1; i++)
    {
        t[0][i] = 0;
    }
    for (int j = 0; j < n + 1; j++)
    {
        t[j][0] = 0;
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < len + 1; j++)
        {
            if (i <= j)
            {
                t[i][j] = max(t[i][j - i] + price[i - 1], t[i - 1][j]);
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }

    return t[n][len];
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    int n;

    cin >> t;

    while (t--)
    {
        cin >> n;

        int arr[n];

        REP(i, 0, n)
        cin >> arr[i];

        cout << uk(n, arr, n);
    }

    return 0;
}

int maximizeTheCuts(int n, int x, int y, int z)
{
    int arr[3];
    arr[0] = x;
    arr[1] = y;
    arr[2] = z;
    int dp[n + 1];

    memset(dp, 0, sizeof(dp));

    for (int j = 0; j < 3; j++)
    {
        // updating the point where we can reach from x,y,z
        for (int i = 1; i <= n; i++)
        {
            // we will update on if the point is x,y,z or if the
            // points are visited by some combination of x,y,z.
            if (i == arr[j] or (i > arr[j] and dp[i - arr[j]] > 0))
                dp[i] = max(dp[i - arr[j]] + 1, dp[i]);
        }
    }
    // cout<<dp[n]<<"\n";
    return dp[n];
}