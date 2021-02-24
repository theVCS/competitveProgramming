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
int downPath[maxN];
int dia[maxN];

void dfs(int node, int par = -1)
{
    int ans = 0, leaf = 1;

    for (int child : arr[node])
    {
        if (child != par)
        {
            dfs(child, node);
            ans = max(ans, downPath[child]);
            leaf = 0;
        }
    }
    if (leaf)
    {
        downPath[node] = 0;
    }
    else
    {
        downPath[node] = 1 + ans;
    }
}

void solve(int node, int par = 1)
{
    vector<int> childPath;
    int ans = 0;

    for (int child : arr[node])
    {
        if (child != par)
        {
            solve(child, node);
            childPath.push_back(downPath[child]);
            ans = max(ans, dia[child]);
        }
    }

    sort(all(childPath), greater<int>());

    if (childPath.size() == 0)
    {
        dia[node] = 0;
    }
    else if (childPath.size() == 1)
    {
        dia[node] = 1 + childPath[0];
    }
    else
    {
        dia[node] = 2 + childPath[0] + childPath[1];
    }
    dia[node] = max(ans, dia[node]);
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

    dfs(1);
    solve(1);

    cout << dia[1];

    return 0;
}