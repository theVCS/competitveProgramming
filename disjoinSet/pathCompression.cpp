// this is a algo which improves the run time of the find function

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
int pathCompFindIter(int a)
{
    vector<int> v;

    while (arr[a] > 0)
    {
        v.push_back(a);
        a = arr[a];
    }

    for (int i = 0; i < v.size(); i++)
    {
        arr[v[i]] = a;
    }
    return a;
}

int pathCompFindRecur(int a)
{
    if (arr[a] < 0)
    {
        return a;
    }
    else
    {
        return arr[a] = pathCompFindRecur(arr[a]);
    }
}

void myunion(int a, int b)
{
    arr[a] += arr[b];
    arr[b] = a;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, e, a, b;

    cin >> n >> e;

    REP(i, 1, n + 1)
    {
        arr[i] = -1;
    }

    REP(i, 0, e)
    {
        cin >> a >> b;
        a = pathCompFindRecur(a), b = pathCompFindRecur(b);

        if (a != b)
            myunion(a, b);
    }

    cout << pathCompFindIter(n);

    return 0;
}