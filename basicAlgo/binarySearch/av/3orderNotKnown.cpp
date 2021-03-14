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
    int mid = (start + end) / 2;

    while (start <= end)
    {
        if (arr[mid] == ele)
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
    int mid = (start + end) / 2;

    while (start <= end)
    {
        if (arr[mid] == ele)
        {
            return mid;
        }
        else if (arr[mid] > ele)
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

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, ele;
    bool asc = true;

    cin >> n;

    int arr[n];

    REP(i, 0, n)
    cin >> arr[i];

    cin >> ele;

    if (n == 1)
    {
        if (ele == arr[0])
        {
            cout << 0;
        }
    }
    else
    {
        if (arr[1] < arr[0])
            asc = false;
    }

    if (asc)
    {
        cout << bs1(arr, n, ele);
    }
    else
    {
        cout << bs2(arr, n, ele);
    }

    return 0;
}