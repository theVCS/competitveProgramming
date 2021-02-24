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
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int arr[maxN], segTree[4 * maxN];
int n, m;

void buildTree(int si, int ss, int se)
{
    if (ss == se)
    {
        segTree[si] = arr[ss];
    }
    else
    {
        int mid = (ss + se) / 2;
        buildTree(2 * si, ss, mid);
        buildTree(2 * si + 1, mid + 1, se);
        segTree[si] = min(segTree[2 * si], segTree[2 * si + 1]);
    }
}

int query(int si, int ss, int se, int qs, int qe)
{   
    if (ss > qe || se < qs)
    {
        return INT_MAX;
    }

    if (ss >= qs && se <= qe)
    {
        return segTree[si];
    }

    int mid = (ss + se) / 2;
    int l = query(2 * si, ss, mid, qs, qe);
    int r = query(2 * si + 1, mid + 1, se, qs, qe);
    return min(l, r);
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int r, l;

    cin >> n;

    REP(i, 1, n + 1)
    cin >> arr[i];

    buildTree(1, 1, n);

    cin >> m;

    while (m--)
    {
        cin >> l >> r;
        l++, r++;
        cout << query(1, 1, n, l, r) << endl;
    }

    return 0;
}