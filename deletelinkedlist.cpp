#include <iostream>
using namespace std;
class Node{
public:
int data;
Node* next;
//constructor
Node(int data)
{
  this->data = data;
this->next = nullptr;
}
//destructor
~Node()
{  //to free memory
  int value= this->data;
  if(this->next != nullptr)
  {
    delete next;
    this->next= nullptr;
  }
  cout<<"memory is free for node with data "<<value<<endl;
}
};
void insert(Node* &head, int d)
{
  Node* temp= new Node(d);
  temp->next = head;
  head= temp;
}
void inserttail(Node* &tail, int d)
{
  Node* temp= new Node(d);
  tail->next = temp;
  tail=tail->next;
}
void insertatposition(Node* &head,Node* &tail,int position,int d)
{
  if (position==1)
  { insert(head,d); //insert at head call kia hai
     return;
  }
  //INSERTING AT LAST POSITION THEREFORE WE NEED TO UPDATE TAIL
  
  Node* temp= head;
  int c=1;
  while(c<position-1)
    {
      temp=temp->next;
      c++;
    }
  if(temp->next==nullptr)
    {
      inserttail(tail,d);
      return;
    }
  Node* nodetoinsert= new Node(d);
  nodetoinsert->next=temp->next;
  temp->next=nodetoinsert;
}

MAIN FUNCTION
void deletenode(int position,Node* &head)
{
  //deleting first or start node
  if(position==1)
  {
    Node* temp= head;
    head=head->next;
    temp->next=nullptr;
    delete temp;
  }
  else
  {
    Node* curr=head;
    Node* prev=nullptr;
    int c=1;
    while(c<position)
      {
        prev=curr;
        curr=curr->next;
        c++;
      }
    prev->next=curr->next;
    curr->next=nullptr;
    delete curr;
  }
}
void print(Node* &head)
{
  Node* temp=head;
  while(temp != nullptr)
    {
      cout<<temp->data<<" ";
      temp= temp->next;
    }
  cout<<endl;
}
int main()
{
  Node* node1 = new Node(10);
  cout<<node1->data <<endl;
  cout<<node1->next <<endl;
  Node* head= node1;
  Node* tail= node1;
 /* print(head);
  insert(head,12);
  print(head);
  insert(head,15);*/
  
  inserttail(tail,12);
  //print(head);
  inserttail(tail,15);
 // print(head);
  insertatposition(head,tail,4,22);
 // print(head);
  //cout<<"head "<<head->data<<endl;
  //cout<<"tail "<<tail->data<<endl;
  
  deletenode(1,head);
  print(head);
  return 0;
}
