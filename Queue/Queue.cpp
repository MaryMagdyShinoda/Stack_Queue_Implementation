#include <iostream>
using namespace std;


class Queue
{
private:
    struct Node
    {
        int info;
        Node* next;
    };
    Node* head;
    Node* tail;
public:
    Queue() {
        head = tail = NULL;
    }
    Queue(int value)
    {
        Node* newnode;
        newnode = new Node;
        newnode->info = value;
        newnode->next = NULL;
        tail = head = newnode;
    }
    void enqueue(int value)
    {
        Node* newnode;
        newnode = new Node;
        newnode->info = value;
        tail->next = newnode;
        newnode->next = NULL;
        tail = newnode;
    }
    void dequeue()
    {
        if (Empty())
            cout << "queue empty" << endl;
        else {
            int value;
            value = head->info;
            Node* ptr = head;
            head = head->next;
            delete ptr;
            cout << value << "  is deleted" << endl;
        }
    }
    void first()
    {
        if (Empty())
            cout << "queue empty" << endl;
        else {
            int value;
            value = head->info;
            cout << "first : " << value << endl;
        }
    }
    bool Empty()
    {
        if (head == NULL)
            return true;
        else
            return false;
    }
    friend ostream& operator << (ostream& print, Queue& q)
    {
        Node* current = new Node;
        current = q.head;
        while (current != NULL)
        {
            print << current->info << " ";
            current = current->next;
        }
        return print;
    }
};

int main()
{
    Queue q(20);
    q.enqueue(15);
    q.enqueue(10);
    q.enqueue(5);
    cout << q << endl << endl;
    q.first();
    q.dequeue();
    cout << endl;
    q.first();
    q.dequeue();
    cout << endl;
    q.first();
    q.dequeue();
    cout << endl;
    q.first();
    q.dequeue();
    cout << endl;
    q.first();
    q.dequeue();
    cout << endl;
    return 0;
}
