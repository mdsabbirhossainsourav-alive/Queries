#include <bits/stdc++.h>
using namespace std;
class Node
{
    public:
    long long val;
    Node* next;
    Node(long long val) 
    {
        this->val = val;
        this->next = NULL;
    }
};

void insert_head(Node* &head, long long val) 
{
    Node* newnode = new Node(val);
    newnode->next = head;
    head = newnode;
}

void insert_tail(Node* &head, long long val) 
{
    Node* newnode = new Node(val);
    if(head == NULL) 
    {
        head = newnode;
        return;
    }
    Node* tmp = head;
    while(tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = newnode;
}

void delete_index(Node* &head, long long idx)
{
    if(head == NULL)
    {
        return;
    }
    if(idx == 0) 
    {
        Node* del = head;
        head = head->next;
        delete del;
        return;
    }

    Node* tmp = head;
    for(int i=0; i<idx-1 && tmp != NULL;)
    {
        tmp = tmp->next;
        i++;
    }
    if(tmp == NULL || tmp->next == NULL)
    {
        return;
    }
    Node* del = tmp->next;
    tmp->next = del->next;
    delete del;
}

void print_list(Node* head)
{
    Node* tmp = head;
    while(tmp != NULL) 
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
}
int main() 
{
    Node* head = NULL;
    int q;
    cin >> q;
    for(int i=0; i<q; i++)
    {
        int x;
        long long v;
        cin >> x >> v;
        if(x == 0)
        {
            insert_head(head,v);
        }  
        else if(x == 1)
        {
            insert_tail(head,v);
        } 
        else if(x == 2)
        {
            delete_index(head,v);
        }
        print_list(head);
    }
    return 0;
}
