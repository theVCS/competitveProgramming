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

int t[1001][1001];

string SCS(string a, string b)
{
    int n = a.size();
    int m = b.size();

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                t[i][j] = 1 + t[i - 1][j - 1];
            }
            else
            {
                t[i][j] = max(t[i - 1][j], t[i][j - 1]);
            }
        }
    }

    string res;
    int i = n, j = m;

    while (i && j)
    {
        if (a[i - 1] == b[j - 1])
        {
            res.push_back(a[i - 1]);
            i--, j--;
        }
        else
        {
            if (t[i - 1][j] > t[i][j - 1])
            {
                res.push_back(a[i - 1]);
                i--;
            }
            else
            {
                res.push_back(b[j - 1]);
                j--;
            }
        }
    }

    while (i)
    {
        res.push_back(a[i - 1]);
        i--;
    }

    while (j)
    {
        res.push_back(b[j - 1]);
        j--;
    }

    reverse(res.begin(), res.end());

    return res;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    string a, b;

    cin >> t;

    while (t--)
    {
        cin >> a >> b;
        cout << SCS(a, b) << endl;
    }

    return 0;
}