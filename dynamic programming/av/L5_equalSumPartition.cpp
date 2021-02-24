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

bool equalSumPart(int arr[], int sum, int n)
{
    bool dp[n + 1][sum + 1];

    REP(i, 0, n + 1)
    {
        REP(j, 0, sum + 1)
        {
            if (j == 0)
            {
                dp[i][j] = true;
            }
            else if (i == 0)
            {
                dp[i][j] = false;
            }
        }
    }

    REP(i, 1, n + 1)
    {
        REP(j, 1, sum + 1)
        {
            if (arr[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][sum];
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n = 5, sum = 0;
    int arr[] = {1, 2, 3, 4, 6};

    REP(i, 0, 5)
    {
        sum += arr[i];
    }

    if (sum % 2)
    {
        cout << "NO";
        return 0;
    }
    else
    {
        sum /= 2;
        if (equalSumPart(arr, sum, n))
        {
            cout << "YES";
        }
        else
        {
            cout << "NO";
        }
        
    }

    return 0;
}