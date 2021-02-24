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

string a, b;
int t[1001][1001];

int LCS(int n, int m)
{
    if (n == 0 || m == 0)
    {
        return 0;
    }
    else if (a[n - 1] == b[m - 1])
    {
        return 1 + LCS(n - 1, m - 1);
    }
    else
    {
        return max(LCS(n, m - 1), LCS(n - 1, m));
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> a >> b;

    cout << LCS(a.size(), b.size()) << endl;

    return 0;
}