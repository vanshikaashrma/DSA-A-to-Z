#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class Queue {
private:
    Node* front; // Points to the front of the queue
    Node* rear;  // Points to the rear of the queue
    int size;    // Size of the queue

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
        size = 0;
    }

    ~Queue() {
        while (front != nullptr) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }

    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (rear == nullptr) { // If the queue is empty
            front = rear = newNode;
        } else {
            rear->next = newNode; // Link the new node
            rear = newNode;       // Update the rear pointer
        }
        size++;
    }

    int dequeue() {
        if (front == nullptr) {
            cout << "Queue underflow" << endl;
            return -1; // Indicate error
        }
        int data = front->data;
        Node* temp = front;
        front = front->next; // Move front pointer to the next node
        delete temp;
        size--;
        return data;
    }

    int peek() const {
        if (front == nullptr) {
            cout << "Queue is empty" << endl;
            return -1; // Indicate error
        }
        return front->data;
    }

    bool isEmpty() const {
        return size == 0; // Returns true if size is 0
    }

    int getSize() const {
        return size; // Returns the current size of the queue
    }

    void print() const {
        Node* temp = front;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    
    cout << "Queue contents: ";
    q.print(); // Output: 10 20 30
    
    cout << "Dequeue element: " << q.dequeue() << endl; // Output: 10
    cout << "Front element: " << q.peek() << endl; // Output: 20
    cout << "Is queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl; // Output: No
    cout << "Size of queue: " << q.getSize() << endl; // Output: 2
    
    return 0;
}
