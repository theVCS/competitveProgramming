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
int arr[maxN], f[120];

int query(int l, int r)
{
    int lblk = l / blk;
    int rblk = r / blk;

    int res = INT_MAX;

    if (lblk == rblk)
    {
        REP(i, l, r + 1)
        {
            res = min(res, arr[i]);
        }
    }
    else
    {
        REP(i, 1, blk * (lblk + 1))
        {
            res = min(res, arr[i]);
        }

        REP(i, lblk + 1, rblk)
        {
            res = min(res, f[i]);
        }

        REP(i, rblk * blk, r + 1)
        {
            res = min(res, arr[i]);
        }
    }

    return res;
}

void solve()
{
    int n, q, a, b;

    cin >> n >> q;

    memset(f, INT_MAX, sizeof(f));

    REP(i, 0, n)
    {
        cin >> arr[i];
        f[i / blk] = min(arr[i], f[i / blk]);
    }

    while (q--)
    {
        cin >> a >> b;
        a--, b--;
        cout << query(a, b) << endl;
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