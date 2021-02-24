#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define N 101
#define REP(i, a, b) for (int i = a; i < b; i++)
ll matrix[101][101];
ll um[101][101];

void multiply(ll matrix_A[][N], ll matrix_B[][N], int dim)
{
    ll res[dim][dim];
    REP(i, 0, dim)
    {
        REP(j, 0, dim)
        {
            res[i][j] = 0;
            REP(k, 0, dim)
            {
                res[i][j] += (matrix_A[i][k] * matrix_B[k][j]) % 1000000007;
            }
        }
    }
    REP(i, 0, dim)
    {
        REP(j, 0, dim)
        {
            matrix_B[i][j] = res[i][j] % 1000000007;
        }
    }
}

void matrixPower(ll matrix[][N], int dim, int power)
{
    while (power)
    {
        if (power % 2)
        {
            power--;
            multiply(matrix, um, dim);
        }

        multiply(matrix, matrix, dim);
        power /= 2;
    }
}

void display(int dim)
{
    REP(i, 0, dim)
    {
        REP(j, 0, dim)
        {
            cout << um[i][j] << " ";
        }
        cout << "\n";
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, dim, power;
    cin >> t;

    while (t--)
    {
        cin >> dim >> power;
        REP(i, 0, dim)
        {
            REP(j, 0, dim)
            {
                cin >> matrix[i][j];
            }
        }

        REP(i, 0, dim)
        {
            REP(j, 0, dim)
            {
                if (i == j)
                {
                    um[i][j] = 1;
                }
                else
                {
                    um[i][j] = 0;
                }
            }
        }

        matrixPower(matrix, dim, power);
        display(dim);
    }

    return 0;
}