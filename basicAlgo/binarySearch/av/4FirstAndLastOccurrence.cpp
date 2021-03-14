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

int bs1(int arr[], int n, int ele)
{
    int start = 0, end = n - 1;
    int mid;

    while (start <= end)
    {
        mid = start + (end - start) / 2;

        if (arr[mid] == ele && (mid == 0 || arr[mid - 1] < ele))
        {
            return mid;
        }
        else if (arr[mid] < ele)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    return -1;
}

int bs2(int arr[], int n, int ele)
{
    int start = 0, end = n - 1;
    int mid;

    while (start <= end)
    {
        mid = start + (end - start) / 2;

        if (arr[mid] == ele && (mid == n - 1 || arr[mid + 1] > ele))
        {
            return mid;
        }
        else if (arr[mid] > ele)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    return -1;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n, ele;

    cin >> t;

    while (t--)
    {
        cin >> n >> ele;

        int arr[n];

        REP(i, 0, n)
        cin >> arr[i];

        int rs1 = bs1(arr, n, ele);

        if (rs1 == -1)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << rs1 << " " << bs2(arr, n, ele) << endl;
        }
    }

    return 0;
}