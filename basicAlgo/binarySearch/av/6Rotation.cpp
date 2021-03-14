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
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int bs(int arr[], int n)
{
    int start = 0, end = n - 1;
    int mid;

    while (start <= end)
    {
        mid = start + (end - start) / 2;

        int prev = (mid + n - 1) % n;
        int next = (mid + 1) % n;

        if (arr[mid] < arr[prev] && arr[mid] < arr[next])
        {
            return mid;
        }
        else if (arr[mid] >= arr[start])
        {
            start = prev;
        }
        else if (arr[mid] <= arr[end])
        {
            end = next;
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;

    cin >> n;

    int arr[n];

    REP(i, 0, n)
    cin >> arr[i];

    cout << bs(arr, n) % n;

    return 0;
}