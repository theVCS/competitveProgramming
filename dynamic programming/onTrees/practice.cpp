#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 200001
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

vector<int> arr[maxN];
int depth[maxN], ans[maxN];

void dfs(int node = 1, int par = -1)
{
    int ans = 0;
    for (int child : arr[node])
    {
        if (child != par)
        {
            dfs(child, node);
            ans = max(depth[child] + 1, ans);
        }
    }

    depth[node] = ans;
}

void solve(int node = 1, int par = -1, int par_ans = -1)
{
    vector<int> prefix, suffix;

    for (int child : arr[node])
    {
        if (child != par)
        {
            prefix.push_back(depth[child]);
            suffix.push_back(depth[child]);
        }
    }

    REP(i, 1, prefix.size())
    prefix[i] = max(prefix[i - 1], prefix[i]);

    for (int i = suffix.size() - 2; i >= 0; i--)
    {
        suffix[i] = max(suffix[i + 1], suffix[i]);
    }

    int c_no = 0;

    for (int child : arr[node])
    {
        if (child != par)
        {
            int leftChild = c_no == 0 ? INT_MIN : prefix[c_no - 1];
            int rightChild = c_no == suffix.size() - 1 ? INT_MIN : suffix[c_no + 1];

            int partial_ans = 1 + max(par_ans, max(leftChild, rightChild));

            solve(child, node, partial_ans);

            c_no++;
        }
    }

    ans[node] = max(par_ans, suffix.size() == 0 ? -1 : suffix[0]) + 1;
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

    dfs();
    solve();

    REP(i, 1, n + 1)
    {
        cout << ans[i] << " ";
    }

    return 0;
}