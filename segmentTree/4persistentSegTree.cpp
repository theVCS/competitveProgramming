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

int arr[maxN];

struct segment
{
    segment *left, *right;
    int val;

    segment(segment *l, segment *r, int v)
    {
        left = l, right = r, val = v;
    }
};
segment *root[maxN];
int rootIndex;

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
        node->val = (node->left)->val + (node->right)->val;
    }
}

void update(segment *curr, segment *prev, int ss, int se, int qi, int val)
{
    if (ss == se)
    {
        curr->val = val;
    }
    else
    {
        int mid = (ss + se) / 2;

        if (qi <= mid)
        {
            curr->right = prev->right;
            curr->left = new segment(NULL, NULL, 0);
            update(curr->left, prev->left, ss, mid, qi, val);
        }
        else
        {
            curr->left = prev->left;
            curr->right = new segment(NULL, NULL, 0);
            update(curr->right, prev->right, mid + 1, se, qi, val);
        }

        curr->val = curr->left->val + curr->right->val;
    }
}

int query(segment *node, int ss, int se)
{
    if (ss == se)
    {
        return node->val;
    }
    else
    {
        int mid = (ss + se) / 2;
        return (query(node->left, ss, mid) + query(node->right, mid + 1, se));
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, index, a;
    scanf("%d", &n);

    REP(i, 1, n + 1)
    scanf("%d", arr + i);

    segment *r;
    r = new segment(NULL, NULL, 0);
    root[rootIndex] = r;
    build(r, 1, n);

    while (true)
    {
        rootIndex++;
        cin >> index >> a;
        r = new segment(NULL, NULL, 0);
        root[rootIndex] = r;
        update(root[rootIndex], root[rootIndex - 1], 1, n, index, a);
        cout << query(root[rootIndex], 1, n) << endl;
    }

    return 0;
}