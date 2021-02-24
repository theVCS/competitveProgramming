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
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

vector<int> arr[maxN];
int dp[maxN][2];

void solve(int node, int par = -1)
{
    vector<int> suffix, prefix;
    int leaf = 1;

    for (int child : arr[node])
    {
        if (child != par)
        {
            solve(child, node);
            suffix.push_back(max(dp[child][0], dp[child][1]));
            prefix.push_back(max(dp[child][0], dp[child][1]));
            leaf = 0;
        }
    }

    if (leaf)
        return;

    REP(i, 1, prefix.size())
    prefix[i] += prefix[i - 1];

    for (int i = suffix.size() - 2; i >= 0; i--)
    {
        suffix[i] += suffix[i + 1];
    }

    dp[node][0] = suffix[0];
    int c_no = 0;

    for (int child : arr[node])
    {
        if (child == par)
            continue;

        int leftChild = c_no == 0 ? 0 : prefix[c_no - 1];
        int rightChild = c_no == suffix.size() - 1 ? 0 : suffix[c_no + 1];

        dp[node][1] = max(dp[node][1], leftChild + rightChild + dp[child][0] + 1);
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, a, b;

    cin >> n;

    REP(i, 0, n - 1)
    {
        cin >> a >> b;
        arr[a].push_back(b), arr[b].push_back(a);
    }

    solve(1);

    cout << max(dp[1][0], dp[1][1]);

    return 0;
}