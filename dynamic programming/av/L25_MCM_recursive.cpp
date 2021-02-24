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

int n;

int solve(int arr[], int i = 1, int j = n - 1)
{
    if (i >= j)
    {
        return 0;
    }
    int mn = INT_MAX;

    for (int k = i; k < j; k++)
    {
        int tmp = solve(arr, i, k) + solve(arr, k + 1, j);
        mn = min(mn, tmp + arr[i - 1] * arr[k] * arr[j]);
    }
    return mn;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;

    cin >> t;

    while (t--)
    {
        cin >> n;

        int arr[n];

        REP(i, 0, n)
        cin >> arr[i];

        cout << solve(arr);
    }

    return 0;
}