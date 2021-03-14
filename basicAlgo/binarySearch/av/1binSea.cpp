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

int bs(int arr[], int n, int ele)
{
    int l = 0, r = n - 1;
    int mid = l + (r - l) / 2;

    while (l <= r)
    {
        if (arr[mid] == ele)
        {
            break;
        }
        else if (arr[mid] < ele)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }

        mid = l + (r - l) / 2;
    }

    return mid;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, ele;

    cin >> n;

    int arr[n];

    REP(i, 0, n)
    {
        cin >> arr[i];
    }

    cin >> ele;

    cout << bs(arr, n, ele);

    return 0;
}

// 10
// 1 2 3 4 5 6 7 8 9 10
// 9