#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define REP(i, a, b) for (int i = a; i < b; i++)

int gcdRec(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return gcdRec(b, a % b);
    }
}

int gcdIter(int a, int b)
{
    int temp;
    while (b)
    {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // cout<<gcdRec(44, 12);
    cout<<gcdIter(44, 12);

    return 0;
}