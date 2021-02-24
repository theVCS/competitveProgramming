#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, cnt;
    while (true)
    {
        cin >> n;
        cnt = 0;

        while (n)
        {
            cnt++;
            n = n & (n - 1);
        }
        cout << cnt << endl;
    }

    return 0;
}