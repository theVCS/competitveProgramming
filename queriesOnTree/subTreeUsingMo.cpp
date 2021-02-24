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

int blk;

//intializarion purpose
vector<int> arr[maxN];
int col[maxN];

int FT[2 * maxN], intime[maxN], outime[maxN], timer; //flattening the tree

int nodeFre[maxN]; // keeping track of frequency of the node when traversed through intime[u] to outime[u]

int colFre[maxN]; // keeping track of the frequency of the colours appeared

int ff[maxN];  // counting frequency of frequency
int f[500];    // making segment tree (on ff[maxN] query will be applied)
int ans[maxN]; // ans to the i-th query

void init(int node, int par = -1)
{
    intime[node] = ++timer;
    FT[timer] = node;

    for (int child : arr[node])
    {
        if (child != par)
        {
            init(child, node);
        }
    }

    outime[node] = ++timer;
    FT[timer] = node;
}

struct query
{
    int node;  // node given
    int fre;   // fre provided
    int index; // index of the query
} q[maxN];

bool cmp(query a, query b)
{
    int x = intime[a.node] / blk;
    int y = intime[b.node] / blk;

    return (x < y) || (x == y && (x & 1 ? outime[a.node] < outime[b.node] : outime[a.node] > outime[b.node]));
}

void add(int index)
{
    int node = FT[index];
    int c = col[node];

    if (++nodeFre[node] == 2)
    {
        colFre[c]++;
        ff[colFre[c]]++;
        f[colFre[c] / blk]++;
        ff[colFre[c] - 1]--;
        f[(colFre[c] - 1) / blk]--;
    }
}

void remove(int index)
{
    int node = FT[index];
    int c = col[node];

    if (--nodeFre[node] == 1)
    {
        colFre[c]--;
        ff[colFre[c]]++;
        f[colFre[c] / blk]++;
        ff[colFre[c] + 1]--;
        f[(colFre[c] + 1) / blk]--;
    }
}

int getAns(int l, int r)
{
    int blk1 = l / blk;
    int blk2 = r / blk;

    int res = 0;

    if (blk1 == blk2)
    {
        REP(i, l, r + 1)
        res += ff[i];
    }
    else
    {
        for (int i = l; i < (blk1 + 1) * blk; i++)
        {
            res += ff[i];
        }

        for (int i = blk1 + 1; i < blk2; i++)
        {
            res += f[i];
        }

        for (int i = blk2 * blk; i < r + 1; i++)
        {
            res += ff[i];
        }
    }
    return res;
}

int main(int argc, char const *argv[])
{
    int n, m, a, b;

    scanf("%d %d", &n, &m);

    blk = pow(n, 0.5);

    REP(i, 1, n + 1)
    scanf("%d", col + i);

    REP(i, 0, n - 1)
    {
        scanf("%d %d", &a, &b);
        arr[a].push_back(b), arr[b].push_back(a);
    }

    init(1);

    REP(i, 1, m + 1)
    {
        scanf("%d %d", &q[i].node, &q[i].fre);
        q[i].index = i;
    }

    // sorting the queries
    sort(q + 1, q + 1 + m, cmp);

    for (int i = 1, L = 1, R = 0; i < m + 1; i++)
    {
        while (L < intime[q[i].node])
            remove(L++);
        while (L > intime[q[i].node])
            add(--L);
        while (R < outime[q[i].node])
            add(++R);
        while (R > outime[q[i].node])
            remove(R--);

        //now calculating answer using sqrt decomposition
        ans[q[i].index] = getAns(q[i].fre, n);
    }

    REP(i, 1, m + 1)
    printf("%d\n", ans[i]);

    return 0;
}