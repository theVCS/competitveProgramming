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

class Solution
{
public:
    int bs1(int arr[], int n, int x)
    {
        int start = 0, end = n - 1;
        int mid;

        while (start <= end)
        {
            mid = start + (end - start) / 2;

            if ((mid == 0 || arr[mid - 1] < x) && arr[mid] == x)
            {
                return mid;
            }
            else if (arr[mid] < x)
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

    int bs2(int arr[], int n, int x)
    {
        int start = 0, end = n - 1;
        int mid;

        while (start <= end)
        {
            mid = start + (end - start) / 2;

            if ((mid == n - 1 || arr[mid + 1] < x) && arr[mid] == x)
            {
                return mid;
            }
            else if (arr[mid] > x)
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

    int count(int arr[], int n, int x)
    {
        int res = bs1(arr, n, x);

        if (res == -1)
            return 0;

        return (bs2(arr, n, x) - res + 1);
    }
};

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    return 0;
}