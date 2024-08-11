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
