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

    int size()
    {
        return length;
    }

    void push(int data)
    {
        Node *n = new Node();

        n->data = data;
        n->next = head;

        head = n;

        length++;
    }

    int sizeIter()
    {
        Node *temp = head;
        int res = 0;

        while (temp)
        {
            res++;
            temp = temp->next;
        }
        return res;
    }

    int _sizeRecur_(Node *node)
    {
        if (node == NULL)
        {
            return 0;
        }
        else
        {
            return 1 + _sizeRecur_(node->next);
        }
    }

    int sizeRecur()
    {
        return _sizeRecur_(head);
    }

    void printList()
    {
        Node *temp = head;

        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    List lst;

    lst.push(15);
    lst.push(1516);
    lst.push(150);

    lst.printList();

    cout << lst.size() << endl;

    cout << lst.sizeIter() << endl;

    cout << lst.sizeRecur() << endl;

    return 0;
}