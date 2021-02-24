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

int t[501][501];

bool isPallindrome(string s, int i, int j)
{
    while (i < j)
    {
        if (s[i] != s[j])
        {
            return false;
        }
        i++, j--;
    }
    return true;
}

int solve(string s, int i, int j)
{
    if (t[i][j] != -1)
    {
        return t[i][j];
    }
    if (i >= j || isPallindrome(s, i, j))
    {
        return 0;
    }
    else
    {
        int ans = INT_MAX;
        for (int k = i; k < j; k++)
        {
            int temp = 1;

            if (t[i][k] != -1)
            {
                temp += t[i][k];
            }
            else
            {
                temp += solve(s, i, k);
            }

            if (t[k + 1][j] != -1)
            {
                temp += t[k + 1][j];
            }
            else
            {
                temp += solve(s, k + 1, j);
            }

            ans = min(ans, temp);
        }
        return t[i][j] = ans;
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(t, -1, sizeof(t));

    string s;

    cin >> s;

    cout << solve(s, 0, s.size() - 1);

    return 0;
}