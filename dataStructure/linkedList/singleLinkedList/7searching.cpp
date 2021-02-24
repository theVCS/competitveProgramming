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

class Node
{
public:
    int data;
    Node *next;

    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

class List
{
private:
    Node *head;
    int length;

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

    bool searchIter(int key)
    {
        Node *temp = head;

        if (temp == NULL)
        {
            return false;
        }

        while (temp)
        {
            if (temp->data == key)
            {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    bool _searchRecur_(Node *head, int key)
    {
        if (head == NULL)
        {
            return false;
        }
        else if (head->data == key)
        {
            return true;
        }
        else
        {
            return _searchRecur_(head->next, key);
        }
    }

    bool searchRecursive(int key)
    {
        return _searchRecur_(head, key);
    }
};

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    List lst;

    lst.push(15);
    lst.push(150);
    lst.push(105);
    lst.push(1125);

    cout << lst.searchRecursive(1005) << endl;

    cout << lst.searchIter(1005) << endl;

    return 0;
}