#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 1000001
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};
int arr[maxN];

int finditer(int a)
{
    while (1)
    {
        if (a == arr[a])
        {
            return a;
        }
        else
        {
            a = arr[a];
        }
    }
}

int findrecur(int a)
{
    if (a == arr[a])
    {
        return a;
    }
    else
    {
        return findrecur(arr[a]);
    }
}

void myunion(int a, int b)
{
    int par1 = finditer(a);
    int par2 = finditer(b);

    if (a != b)
    {
        arr[par2] = par1;
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, n, child1, child2;

    cin >> n;

    REP(i, 1, n + 1)
    {
        cin >> a;
        arr[i] = a;
    }

    // cout << findrecur(n);

    cin >> child1 >> child2;

    myunion(child1, child2);

    cout << finditer(n);

    return 0;
}