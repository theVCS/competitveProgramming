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

// string matching algorithm
int pi[maxN];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;

    cin >> s;

    REP(i, 1, s.size())
    {
        int j = pi[i - 1];

        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            j++;

        pi[i] = j;
    }

    REP(i, 0, s.size())
    {
        cout << pi[i] << " ";
    }

    return 0;
}

// prefix function:You are given a string s of length n. The prefix function for this string is defined as an array π of length n, where π[i] is the length of the longest proper prefix of the substring s[0…i] which is also a suffix of this substring. A proper prefix of a string is a prefix that is not equal to the string itself. By definition, π[0]=0.

// Mathematically the definition of the prefix function can be written as follows :

//     π[i] = maxk = 0…i {k: s[0…k−1] = s[i−(k−1)…i]}
// string       : a a b a a a b
// prefix fun   : 0 1 0 1 2 2 3

// properties:
// π(i + 1) <= π(i) + 1
// if(s[π(i)] == s[i + 1])
//      π(i + 1) = π(i)
