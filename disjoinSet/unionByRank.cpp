// it is also a improvement approach with improve the runtime of Union function by making set with more elements as parent
#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 100001
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

vector<int> arr(maxN, -1);

int find(int a)
{
    if (arr[a] < 0)
    {
        return a;
    }
    return arr[a] = find(arr[a]);
}

void Union(int a, int b)
{
    arr[a] += arr[b];
    arr[b] = a;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, a, b, q;

    cin >> n >> m;

    while (m--)
    {
        cin >> a >> b;

        a = find(a);
        b = find(b);

        if (a != b)
        {
            if (a < b)
            {
                swap(a, b);
            }
            Union(a, b);
        }
    }

    cin >> q;

    while (q--)
    {
        cin >> a >> b;
        int pa = find(a);
        int pb = find(b);

        if (pa == pb)
        {
            cout << "TIE" << endl;
        }
        else if (pa < pb)
        {
            cout << b << endl;
        }
        else
        {
            cout << a << endl;
        }
    }

    return 0;
}