#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 100001
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int FT[2 * maxN], intime[maxN], outime[maxN], timer;
vector<int> arr[maxN];

void dfs(int node, int par = -1)
{
    intime[node] = ++timer;
    FT[timer] = node;

    for (int child : arr[node])
    {
        if (child != par)
        {
            dfs(child, node);
        }
    }

    outime[node] = ++timer;
    FT[timer] = node;
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

    REP(i, 1, 2 * n + 1)
    cout << FT[i] << " ";

    return 0;
}