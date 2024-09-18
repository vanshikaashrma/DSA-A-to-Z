#include <iostream>
using namespace std;
class Node
{
public:
int data;
Node *next;
Node(int data)
{
  this->data=data;
  this->next=NULL;
}
};
class Stack
{
public:
Node* top;
int size;
Stack()
{
  top=NULL;
  size=0;
}
~Stack()
{
  
  while(top!=NULL)
    { Node* temp=top;
      top=top->next;
      delete temp;
      
    }
}
void push(int value)
{
  Node* temp= new Node(value);
  temp->next=top;
  top=temp;
  size++;
}

int pop()
{
  if(top==NULL)
    cout<<"stack underflow"<<endl;
  int d= top->data;
  Node* temp= top;
  top=top->next;
  delete temp;
  size--;
  return d;
}
void print()
{
  Node* temp=top;
  while(temp!=NULL)
    {
      cout<<temp->data<<" ";
      temp=temp->next;
    }
  cout<<endl;
}
int peek()
{
  if(top==NULL)
    cout<<"stack underflow"<<endl;
  return top->data;
}
bool isEmpty()
{
  if(size==0)
    return true;
  else
    return false;
}
int sizeOfStack()
{
  return size;
}
};
int main()
{
  Stack s;
  s.push(10);
  s.push(20);
  s.push(30);
  s.print();
  s.pop();
  cout<<(s.isEmpty()?"true":"false")<<endl;
  cout<<s.peek()<<endl;
  cout<<s.sizeOfStack()<<endl;
}
