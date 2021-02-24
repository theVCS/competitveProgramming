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

struct Node
{
    int data;
    Node *next;

    Node(int _d)
    {
        data = _d;
        next = NULL;
    }
};

class List
{
private:
    int length;
    Node *head;

public:
    List()
    {
        head = NULL;
        length = 0;
    }

    void push(int data)
    {
        Node *n = new Node(data);
        n->next = head;

        head = n;
        length++;
    }

    int _GetNth_(Node *head, int index)
    {
        if (index == 1)
        {
            return head->data;
        }
        else if (head == NULL)
        {
            return INT_MIN;
        }
        else
        {
            return _GetNth_(head->next, index - 1);
        }
    }

    int GetNth(int index)
    {
        return _GetNth_(head, index);
    }
};

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    return 0;
}