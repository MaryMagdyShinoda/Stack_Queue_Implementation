#include <iostream>
using namespace std;

class Stack
{
private:
    struct Node
    {
        int info;
        Node* next;
    };
    Node* head;
public:
    Stack() {
        head = NULL;
    }
    Stack(int value)
    {
        Node* newnode;
        newnode = new Node;
        newnode->info = value;
        newnode->next = NULL;
        head = newnode;
    }
    void push(int value)
    {
        Node* newnode;
        newnode = new Node;
        newnode->info = value;
        newnode->next = head;
        head = newnode;
    }
    void pop()
    {
        if (Empty())
            cout << "stack empty" << endl;
        else {
            int value;
            value = head->info;
            Node* ptr = head;
            head = head->next;
            delete ptr;
            cout << value << "  is deleted" << endl;
        }
    }
    void top()
    {
        if (Empty())
            cout << "stack empty" << endl;
        else {
            int value;
            value = head->info;
            cout << "top : " << value << endl;
        }
    }
    bool Empty()
    {
        if (head == NULL)
            return true;
        else
            return false;
    }
    friend ostream& operator << (ostream& print, Stack& s)
    {
        Node* current = new Node;
        current = s.head;
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
    Stack s(20);
    s.push(15);
    s.push(10);
    s.push(5);
    cout << s << endl << endl;
    s.top();
    s.pop();
    cout << endl;
    s.top();
    s.pop();
    cout << endl;
    s.top();
    s.pop();
    cout << endl;
    s.top();
    s.pop();
    cout << endl;
    s.top();
    s.pop();
    cout << endl;
}