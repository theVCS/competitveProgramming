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
#define INF 1e17
#define endl "\n"
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};
// while (T < q[i].t)
//     do_update(++T);
// while (T > q[i].t)
//     undo(T--);
// while (R < q[i].r)
//     add(++R);
// while (L > q[i].l)
//     add(--L);
// while (R > q[i].r)
//     remove(R--);
// while (L < q[i].l)
//     remove(L++);

struct edge
{
    int u, v;
    ll w;
};

vector<edge> arr;
vector<ll> dis(maxN, INF);
int parent[maxN];

void bellmanFord(int m)
{
    while (true)
    {
        bool flag = true;

        REP(i, 0, m)
        {
            if (dis[arr[i].u] < INF && dis[arr[i].v] > dis[arr[i].u] + arr[i].w)
            {
                dis[arr[i].v] = dis[arr[i].u] + arr[i].w;
                parent[arr[i].v] = arr[i].u;
                flag = false;
            }
        }

        if (flag)
            break;
    }
}

void solve()
{
    int n, m;
    edge e;

    cin >> n >> m;

    REP(i, 0, m)
    {
        cin >> e.u >> e.v >> e.w;
        arr.push_back(e);
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // ifstream fi("input.txt");
    // ofstream fo("output.txt");

    // fi >> input;
    // fo << output;

    int t = 1;

    //cin >> t;

    while (t--)
    {
        solve();
    }

    //fi.close();
    //fo.close();

    return 0;
}