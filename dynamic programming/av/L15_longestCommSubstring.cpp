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

int subString(string a, string b)
{
    int n = a.size();
    int m = b.size();
    int res = 0;

    int t[n + 1][m + 1];

    for (int i = 0; i < n + 1; i++)
    {
        t[i][0] = 0;
    }
    for (int i = 0; i < m + 1; i++)
    {
        t[0][i] = 0;
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                t[i][j] = 1 + t[i - 1][j - 1];
                res = max(res, t[i][j]);
            }
            else
            {
                t[i][j] = 0;
            }
        }
    }
    return res;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n, m;
    string a, b;

    cin >> t;

    while (t--)
    {
        cin >> n >> m;
        cin >> a >> b;
        cout << subString(a, b) << endl;
    }

    return 0;
}