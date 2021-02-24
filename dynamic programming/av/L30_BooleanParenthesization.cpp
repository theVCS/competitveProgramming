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

int solve(string s, int i, int j, bool istrue = true)
{
    if (i > j)
    {
        return 0;
    }
    else if (i == j)
    {
        if (istrue)
        {
            return s[i] == 'T';
        }
        else
        {
            return s[i] == 'F';
        }
    }
    else
    {
        int res = 0;
        bool flag = false;

        for (int k = i; k < j; k += 2)
        {
            int lefttrue = solve(s, i, k, true);
            int leftfalse = solve(s, i, k, false);
            int righttrue = solve(s, k + 1, j, true);
            int rightfalse = solve(s, k + 1, j, false);

            if (s[k + 1] == '|')
            {
                if (istrue)
                {
                    res += leftfalse * righttrue + lefttrue * righttrue + lefttrue * rightfalse;
                }
                else
                {
                    res += leftfalse * rightfalse;
                }
            }
            else if (s[k + 1] == '&')
            {
                if (istrue)
                {
                    res += lefttrue * righttrue;
                }
                else
                {
                    res += leftfalse * rightfalse + lefttrue * rightfalse + leftfalse * righttrue;
                }
            }
            else
            {
                if (istrue)
                {
                    res += leftfalse * rightfalse + lefttrue * rightfalse;
                }
                else
                {
                    res += lefttrue * righttrue + leftfalse * rightfalse;
                }
            }
        }

        return res;
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    string s;

    cin >> n;
    cin >> s;

    cout << solve(s, 0, n - 1);

    return 0;
}