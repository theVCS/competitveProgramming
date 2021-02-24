#include <bits/stdc++.h>
#include <string>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
int arr[1000];

void totalDivisors(int n)
{
    int res = 1;
    memset(arr, 0, 1000);

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            int cnt = 0;

            while (n % i == 0)
            {
                cnt++;
                n /= i;
            }
            arr[i] = cnt;
        }
    }

    if (n > 1)
    {
        arr[n] += 1;
    }

    REP(i, 0, 100)
    {
        res *= arr[i] + 1;
    }
    cout<<res<<endl;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n;
    cin >> t;

    while (t--)
    {
        // n less than 1000
        cin >> n;
        totalDivisors(n);
    }

    return 0;
}