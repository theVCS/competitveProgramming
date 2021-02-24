#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n, k;

    cin >> t;

    while (t--)
    {
        cin >> n;
        int arr[n];

        REP(i, 0, n)
        {
            cin >> arr[i];
        }
        sort(arr, arr + n);
        cin >> k;
        cout << arr[k - 1] << endl;
    }

    return 0;
}