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

void push(Node **head, int data)
{
    Node *n = new Node();
    n->data = data;
    n->next = *head;

    *head = n;
}

void insertAfter(Node *pre_node, int data)
{
    if (pre_node)
    {
        Node *n = new Node();

        n->data = data;
        n->next = pre_node->next;

        pre_node->next = n;
    }
}

void append(Node **head, int data)
{
    Node *n  = new Node();

    n->data = data;
    n->next = NULL;

    if (*head == NULL)
    {
        *head = n;
        return;
    }
    
    Node *last = *head;

    while (last->next)
    {
        last = last->next;
    }
    
    last->next = n;
}

void printList(Node *node)  
{  
    while (node != NULL)  
    {  
        cout<<" "<<node->data;  
        node = node->next;  
    }  
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Node *head = NULL;

    push(&head, 15);
    append(&head, 21);
    insertAfter(head, 23);

    printList(head);

    return 0;
}