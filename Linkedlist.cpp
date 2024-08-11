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
  print(head);
  inserttail(tail,15);
  print(head);
  return 0;
}
