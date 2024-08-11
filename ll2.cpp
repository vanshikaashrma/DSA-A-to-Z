void insertatposition(Node* &head,int position,int d)
{
  Node* temp= head;
  int c=1;
  while(c<position-1)
    {
      temp=temp->next;
      c++;
    }
  Node* nodetoinsert= new Node(d);
  nodetoinsert->next=temp->next;
  temp->next=nodetoinsert;
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
  print(head);
  insertatposition(head,3,22);
  print(head);                                                                 //output: 10 12 22 15
  return 0;
}

CASE 2: if position== 1 then code will be....

  void insertatposition(Node* &head,int position,int d)
{
  if (position==1)
  { insert(head,d); //insert at head call kia hai
     return;
  }
  Node* temp= head;
  int c=1;
  while(c<position-1)
    {
      temp=temp->next;
      c++;
    }
  Node* nodetoinsert= new Node(d);
  nodetoinsert->next=temp->next;
  temp->next=nodetoinsert;
}

//CASE3>:  GENERIC CASE -if we hv to insert at end then we have to update tail

#include <iostream>
using namespace std;
class Node{
public:
int data;
Node* next;
Node(int data)//constructor
{
  this->data = data;
this->next = nullptr;
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
  print(head);
  insertatposition(head,tail,4,22);  //10 12 15 22
  print(head);
  cout<<"head "<<head->data<<endl;   // head 10
  cout<<"tail "<<tail->data<<endl;  // tail 22
  return 0;
}
