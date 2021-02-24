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
    int length;
    Node *head;

public:
    List()
    {
        length = 0;
        head = NULL;
    }

    void push(int data)
    {
        Node *n = new Node(data);
        n->next = head;

        head = n;
        length++;
    }

    void swap(int data1, int data2)
    {
        Node *curr1 = NULL, *prev1 = NULL, *curr2 = NULL, *prev2 = NULL;

        Node *temp = head;

        if (temp->data == data1)
        {
            curr1 = temp;
        }

        if (temp->data == data2)
        {
            curr2 = temp;
        }

        while ((curr1 == NULL || curr2 == NULL) && temp->next)
        {
            if ((temp->next)->data == data1)
            {
                curr1 = temp->next;
                prev1 = temp;
            }

            if ((temp->next)->data == data2)
            {
                curr2 = temp->next;
                prev2 = temp;
            }

            temp = temp->next;
        }

        if (curr1 && curr2)
        {
            Node *temp;
            if (prev1 == NULL)
            {
                temp = curr1->next;
                prev2->next = curr1;
                curr1->next = curr2->next;
                curr2->next = temp;

                head = curr2;
            }
            else if (prev2 == NULL)
            {
                temp = curr2->next;
                prev1->next = curr2;
                curr2->next = curr1->next;
                curr1->next = temp;

                head = curr1;
            }
            else
            {
                temp = prev1->next;
                prev1->next = prev2->next;
                prev2->next = temp;

                temp = curr1->next;
                curr1->next = curr2->next;
                curr2->next = temp;
            }
        }
    }

    void pairWiseSwap()
    {
        Node *curr = head->next, *prev = head, *prev2, *temp;

        if (curr == NULL)
            return;

        prev->next = curr->next;
        curr->next = prev;
        head = curr;

        prev2 = prev;
        prev = prev->next;
        if (prev)
            curr = prev->next;
        else
            curr = NULL;

        while (curr)
        {
            temp = curr->next;
            prev2->next = prev->next;
            curr->next = prev;
            prev->next = temp;

            prev2 = prev;
            prev = prev->next;

            if (prev)
                curr = prev->next;
            else
                curr = NULL;
        }
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
    lst.push(150);
    lst.push(105);
    lst.push(1515);
    lst.push(125);
    lst.push(156);

    lst.printList();

    lst.pairWiseSwap();

    lst.printList();

    return 0;
}