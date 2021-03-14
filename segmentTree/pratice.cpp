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

struct segment
{
    segment *left, *right;
    int val;

    segment(segment *l, segment *r, int v)
    {
        left = l, right = r, val = v;
    }
};

int arr[maxN];

void build(segment *node, int ss, int se)
{
    if (ss == se)
    {
        node->val = arr[ss];
    }
    else
    {
        int mid = (ss + se) / 2;
        node->left = new segment(NULL, NULL, 0);
        node->right = new segment(NULL, NULL, 0);
        build(node->left, ss, mid);
        build(node->right, mid + 1, se);
        node->val = max(node->left->val, node->right->val);
    }
}

int query(segment *node, int ss, int se, int qs, int qe)
{
    if (ss > qe || se < qs)
        return INT_MIN;

    if (qs <= ss && qe >= se)
    {
        return node->val;
    }

    int mid = (ss + se) / 2;

    return max(query(node->left, ss, mid, qs, qe), query(node->right, mid + 1, se, qs, qe));
}

void update(segment *curr, segment *prev, int ss, int se, int qi)
{
    if (ss == se)
    {
        curr->val = arr[ss];
        return;
    }

    int mid = (ss + se) / 2;

    if (qi <= mid)
    {
        curr->right = prev->right;
        curr->left = new segment(NULL, NULL, 0);
        update(curr->left, prev->left, ss, mid, qi);
    }
    else
    {
        curr->left = prev->left;
        curr->right = new segment(NULL, NULL, 0);
        update(curr->right, prev->right, mid + 1, se, qi);
    }

    curr->val = max(curr->left->val, curr->right->val);
}

segment *root[maxN];
int rootIndex;

void solve()
{
    int n, m, index, val;
    cin >> n >> m;

    REP(i, 1, n + 1)
    cin >> arr[i];

    segment *r = new segment(NULL, NULL, 0);
    root[rootIndex++] = r;
    build(r, 1, n);

    REP(i, 1, m + 1)
    {
        cin >> index >> val;
        r = new segment(NULL, NULL, 0);
        root[rootIndex++] = r;
        arr[index] = val;
        update(root[rootIndex], root[rootIndex - 1], 1, n, index);
        cout << query(root[rootIndex], 1, n, 1, n);
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