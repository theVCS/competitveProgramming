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
int subTree[maxN];

int dfs(int node = 1, int par = -1)
{
    int cnt = 1;

    for (int child: arr[node]){
        if (child != par)
        {
            cnt += dfs(child, node);
        }        
    }
    subTree[node] = cnt - 1;
    return cnt;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, a;

    cin >> n;

    REP(i, 2, n + 1)
    {
        cin >> a;
        arr[i].push_back(a);
        arr[a].push_back(i);
    }

    dfs();

    REP(i, 1, n + 1)cout << subTree[i] << " ";

    return 0;
}