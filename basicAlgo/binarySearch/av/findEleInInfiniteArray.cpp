#include <bits/stdc++.h>
using namespace std;
#define maxN 100001

int arr[maxN];

int findPos(int ele)
{
    int start = 0, end = 1;
    int val = arr[end];

    while (val < ele)
    {
        start = end;
        end <<= 1;
        val = arr[end];
    }

    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (arr[mid] == ele)
            return mid;
        else if (arr[mid] < ele)
            start = mid + 1;
        else
            end = mid - 1;
    }

    return -1;
}

int main()
{

    int n, ele;

    cin >> n >> ele;

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << findPos(ele);

    return 0;
}