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
#define INF 0x3f3f3f3f
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

const int blk = 900;
int arr[maxN], fre[maxN], last[maxN], nq, nu, res;
int ans[maxN];
bool use[maxN];

struct Query
{
    int l, r, lblk, rblk, t, index;
} q[maxN];

struct Update
{
    int index, new_y, prev_y;
} u[maxN];

bool cmp(Query a, Query b)
{
    return (a.lblk < b.lblk) || (a.lblk == b.lblk && a.rblk < b.rblk) || (a.lblk == b.lblk && a.rblk == b.rblk && a.t < b.t);
}

void add(int index)
{
    int ele = arr[index];
    use[index] = true;

    if (++fre[ele] == 1)
        res++;
}

void remove(int index)
{
    int ele = arr[index];
    use[index] = false;

    if (--fre[ele] == 0)
        res--;
}

void reflect_update(int index, int ele)
{
    if (use[index] == false)
    {
        arr[index] = ele;
        return;
    }
    remove(index);
    arr[index] = ele;
    add(index);
}

void do_update(int index)
{
    reflect_update(u[index].index, u[index].new_y);
}

void undo(int index)
{
    reflect_update(u[index].index, u[index].prev_y);
}

void solve()
{
    int n, m, code, a, b;

    cin >> n >> m;

    REP(i, 1, n + 1)
    {
        cin >> arr[i];
        last[i] = arr[i];
    }

    REP(i, 0, m)
    {
        cin >> code;

        if (code == 1)
        {
            cin >> a >> b;
            u[nu].index = a;
            u[nu].new_y = b;
            u[nu].prev_y = last[a];
            last[a] = b;
            nu++
        }
        else
        {
            cin >> a >> b;
            q[nq].l = a;
            q[nq].r = b;
            q[nq].lblk = a / blk;
            q[nq].rblk = b / blk;
            q[nq].index = i;
            q[nq].t = nu;
            nq++;
        }
    }

    sort(q, q + nq, cmp);

    for (int i = 0, L = 1, R = 0, T = 0; i < nq; i++)
    {
        while (T < q[i].t)
            do_update(++T);
        while (T > q[i].t)
            undo(T--);
        while (R < q[i].r)
            add(++R);
        while (L > q[i].l)
            add(--L);
        while (R > q[i].r)
            remove(R--);
        while (L < q[i].l)
            remove(L++);
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