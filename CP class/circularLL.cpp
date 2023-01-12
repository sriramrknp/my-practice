#include<bits/stdc++.h>

using namespace std;

class node{
    public:
    int val;
    node *next;
};

int i = 1;

node* insert(node *temp1)
{
    if(i==5)
        return 0;
    if (temp1 == NULL)
    {
        node *temp = new node;
        temp->val = i;
        temp->next = NULL;
        temp1 = temp;
    }
    else {
        node *temp = new node;
        temp->val = i;
        temp->next = NULL;
        temp1->next = temp;
        temp1 = temp;
    }
    i++;
    insert(temp1);
    return temp1;
}

void circularL(node *head){
    node *temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }

    node *temp1 = head;
    // which node to be pointed
    // here node 2
    int j = 1;
    while(j--){
        temp1 = temp1->next;
    }
    temp->next = temp1;
}

void display(node *head)
{
    node *temp = head;
    while(temp->next!=NULL)
    {
        cout << temp->val << '\n';
        temp = temp->next;
    }
}

int main()
{
    node *head=NULL;
    head = insert(head);

    // creating circular linked list
    circularL(head);

    // lets try to display
    // display(head);

    // since display gets error, circular linked list created
    

    return 0;
}