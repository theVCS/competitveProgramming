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
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

vector<int> arr[maxN];
ll subSize[maxN];
ll subAns[maxN], ans[maxN];

int dfs(int node = 1, int par = -1)
{
    ll size = 1;
    
    for (int child : arr[node])
    {
        if (child != par)
        {
            size += dfs(child, node);
            subAns[node] += (subAns[child] + subSize[child]) * 1LL;
        }
    }

    subSize[node] = size;
    return size;
}

void solve(int node = 1, int par = -1)
{
    for (int child : arr[node])
    {
        if (child != par)
        {
            ans[child] = ans[node] - (subAns[child] + subSize[child]) + (subSize[1] - subSize[child]) + subAns[child];
            solve(child, node);
        }
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

    dfs();

    ans[1] = subAns[1];

    solve();

    REP(i, 1, n + 1)
    {
        cout << ans[i] << " ";
    }

    return 0;
}