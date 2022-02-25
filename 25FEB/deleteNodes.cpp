#include<iostream>
#include<climits>
using namespace std;
class node
{
    public:
    int data;
    node* next;
    node(int d)
    {   
        data=d;
        next=NULL;
    }
};

void insert_at_tail(node* &head,node* &tail,int d)
{
    if(head==NULL)
    {
        head=new node(d);
        tail=head;
        return ;
    }
    tail->next=new node(d);
    tail=tail->next;
}

void print(node* head)
{
    if(head==NULL)
    {
        cout<<endl;
        return ;
    }
    cout<<head->data<<" ";
    print(head->next);
}

node* delete_node(node* head,int &maxRight)
{
    // maxRight should by called by reference, because the changes
    // made during calling futher, should be reflected at this step
    if(head==NULL)
    {
        return head;
    }
    node * aage=delete_node(head->next,maxRight); // maxRight update ho chuka hoga
    if(head->data < maxRight)
    {
        // ye node delete karni hai
        // head ko mat chedho, directy aage wali list return kara do 
        return aage;
    }
    else
    {
        head->next=aage;
        maxRight=max(maxRight,head->data);
        return head;
    }
}
int main()
{

    node *head=NULL,*tail=NULL;

    int n; cin>>n;
    for(int i=0;i<n;i++)
    {
        int x; cin>>x;
        insert_at_tail(head,tail,x);
    }

    // print(head);
    int maxRight=INT_MIN;
    node* ans=delete_node(head,maxRight);

    print(ans);



    

    




    return 0;
}