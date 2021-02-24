#include <bits/stdc++.h>
#include <limits>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int arr[] = {51, 2, -16, 2984, 26};
    int len = sizeof(arr) / sizeof(int);
    int min = INT_MIN;
    int max = INT_MAX;

    REP(i, 0, len)
    {
        if (min < arr[i])
        {
            min = arr[i];
        }

        if (max > arr[i])
        {
            max = arr[i];
        }
    }

    cout<<"MAXIMUM: "<<max<<endl;
    cout<<"MINIMUM: "<<min<<endl;

    return 0;
}