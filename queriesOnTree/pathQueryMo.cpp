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

const int blk = 700;

// initialization
vector<int> arr[maxN];
int col[maxN], level[maxN], parent[maxN][18];

// flattening tree
int FT[2 * maxN], intime[maxN], outime[maxN], timer;

// processing queries
int fre[maxN], colFre[maxN];

// storing result
bool ans[200001];

struct query
{
    int l, r, col, lca, index;
} Q[200001];

bool cmp(query a, query b)
{
    int x = a.l / blk, y = b.l / blk;
    return (x < y) || (x == y && a.r < b.r);
}

void dfs(int node = 1, int par = -1, int l = 0)
{
    intime[node] = ++timer;
    FT[timer] = node;
    parent[node][0] = par;
    level[node] = l;

    for (int child : arr[node])
    {
        if (child != par)
        {
            dfs(child, node, l + 1);
        }
    }

    outime[node] = ++timer;
    FT[timer] = node;
}

void init(int n)
{
    dfs();

    for (int j = 1; j < 18; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (parent[i][j - 1] == -1)
            {
                parent[i][j] = -1;
            }
            else
            {
                parent[i][j] = parent[parent[i][j - 1]][j - 1];
            }
        }
    }
}

int lca(int a, int b)
{
    if (level[a] < level[b])
        swap(a, b);

    int d = level[a] - level[b];

    while (d)
    {
        int i = log2(d);
        a = parent[a][i];
        d -= 1 << i;
    }

    if (a == b)
        return a;

    for (int i = 17; i >= 0; i--)
    {
        if (parent[a][i] != -1 && parent[a][i] != parent[b][i])
        {
            a = parent[a][i];
            b = parent[b][i];
        }
    }
    return parent[a][0];
}

void add(int index)
{
    int node = FT[index];
    int c = col[node];

    fre[node]++;

    if (fre[node] == 1)
    {
        colFre[c]++;
    }
    else if (fre[node] == 2)
    {
        colFre[c]--;
    }
}

void remove(int index)
{
    int node = FT[index];
    int c = col[node];

    fre[node]--;

    if (fre[node] == 1)
    {
        colFre[c]++;
    }
    else if (fre[node] == 0)
    {
        colFre[c]--;
    }
}

int main(int argc, char const *argv[])
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    int t = 0, n, m, a, b, c;

    while (scanf("%d", &n) != EOF)
    {
        if (t)
        {
            printf("\n");
        }
        t++;

        scanf("%d", &m);

        timer = 0;
        colFre[0] = 0;

        REP(i, 1, n + 1)
        {
            scanf("%d", col + i);
            arr[i].clear(), fre[i] = 0, colFre[i] = 0;
        }

        REP(i, 0, n - 1)
        {
            scanf("%d %d", &a, &b);
            arr[a].push_back(b), arr[b].push_back(a);
        }

        init(n);

        REP(i, 1, m + 1)
        {
            scanf("%d %d %d", &a, &b, &c);

            if (intime[a] > intime[b])
                swap(a, b);

            int LCA = lca(a, b);

            if (LCA == a)
            {
                Q[i].l = intime[a];
                Q[i].lca = -1;
            }
            else
            {
                Q[i].l = outime[a];
                Q[i].lca = LCA;
            }

            Q[i].r = intime[b];
            Q[i].index = i;
            Q[i].col = c;

            ans[i] = false;
        }

        sort(Q + 1, Q + 1 + m, cmp);

        for (int i = 1, L = 1, R = 0; i <= m; i++)
        {
            while (L < Q[i].l)
                remove(L++);
            while (L > Q[i].l)
                add(--L);
            while (R < Q[i].r)
                add(++R);
            while (R > Q[i].r)
                remove(R--);

            ans[Q[i].index] = (colFre[Q[i].col] > 0) || (Q[i].lca > 0 && col[Q[i].lca] == Q[i].col);
        }

        REP(i, 1, m + 1)
        {
            if (ans[i])
                printf("Find\n");
            else
                printf("NotFind\n");
        }
    }

    return 0;
}