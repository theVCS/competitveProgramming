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

int parent[maxN];

int find(int n)
{
    if (parent[n] < 0)
    {
        return n;
    }
    else
    {
        return parent[n] = find(parent[n]);
    }
}

void merge(int a, int b)
{
    a = find(a), b = find(b);

    if (a != b)
    {
        if (parent[b] > parent[a])
        {
            swap(a, b);

            parent[a] += parent[b];
            parent[b] = a;
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(parent, -1, maxN);

    return 0;
}