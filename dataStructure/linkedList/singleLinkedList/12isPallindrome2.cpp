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

    Node *reverse(Node *curr)
    {
        Node *next = NULL, *prev = NULL;

        while (curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    bool isPallindrome()
    {
        int pointer = (length + 1) / 2;

        Node *temp = head;

        pointer -= 1;

        while (pointer--)
        {
            temp = temp->next;
        }

        Node *head2 = reverse(temp->next);

        temp->next = NULL;

        temp = head;

        while (temp && head2)
        {
            if (temp->data != head2->data)
            {
                return false;
            }
            temp = temp->next;
            head2 = head2->next;
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    List lst;

    lst.push(1);
    lst.push(2);
    lst.push(11);

    cout << lst.isPallindrome();

    return 0;
}