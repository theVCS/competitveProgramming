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

struct edge
{
    int a, b, c;
};
edge e[maxN];
vector<int> dist(maxN, INT_MAX);

int n, m;

void solve()
{
    bool flag;

    while (true)
    {
        flag = true;

        for (int i = 0; i < m; i++)
        {
            if (dist[e[i].a] < INT_MAX)
            {
                if (dist[e[i].b] > dist[e[i].a] + e[i].c)
                {
                    flag = false;
                    dist[e[i].b] = dist[e[i].a] + e[i].c;
                }
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    REP(i, 0, m)
    {
        cin >> e[i].a >> e[i].b >> e[i].c;

        if (e[i].b == 1)
        {
            swap(e[i].a, e[i].b);
        }
    }

    return 0;
}