#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 100001
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

bool win[maxN];

void init()
{
    win[1] = 1;
    win[2] = 0;
    win[3] = 1;
    win[4] = 1;

    for (int i = 5; i < maxN; i++)
    {
        if (!win[i - 1] || !win[i - 3] || !win[i - 4])
            win[i] = 1;
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // given n sticks and we can remove sticks like {1,3,4} and for given number we need to tell whelther the player can win the game or not

    init();

    int t, n;
    cin >> t;

    while (t--)
    {
        cin >> n;

        if (win[n])
            cout << "Player 1" << endl;
        else
            cout << "Player 2" << endl;
    }

    return 0;
}