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

    int n;
    cin >> n;
    int arr[n];
    int sum = 0, counto = 0, countz = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < 31; i++)
    {
        counto = 0;
        countz = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[j] & (1 << i))
            {
                counto++;
            }
            else
            {
                countz++;
            }
        }
        sum += (counto * countz) * (1 << i);
    }
    cout<<sum;

    return 0;
}