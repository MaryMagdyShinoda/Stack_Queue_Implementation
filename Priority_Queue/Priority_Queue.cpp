#include <iostream>
using namespace std;

struct Node
{
    string info;
    int priority;
    Node* next;
};

class Queue
{
private:
    Node* head = NULL;
public:
    Queue() {}
    void enqueue(string data, int priority)
    {
        Node* newnode = new Node;
        newnode->info = data;
        newnode->priority = priority;
        if (head == NULL || priority < head->priority) {
            newnode->next = head;
            head = newnode;
        }
        else {
            Node* first = new Node;
            first = head;
            while (first->next != NULL && first->next->priority <= priority)
                first = first->next;
            newnode->next = first->next;
            first->next = newnode;
        }
    }
    string dequeue()
    {
        if (head == NULL) {
            cout << "Queue is Empty" << endl;
        }
        else {
            string data;
            data = head->info;
            Node* old = head;
            head = head->next;
            delete old;
            return data;
        }
    }
    ~Queue() {
        delete head;
    }
};
int main()
{
    int count = 0;
    string check;
    Queue q;
    do {
        int choose;
        cout << "enter 1 if you want to add element" << endl;
        cout << "enter 2 if you want to display and delete the element with high priority" << endl;
        cin >> choose;
        if (choose == 1)
        {
            string elem;
            int loc;
            cout << "enter the string" << endl;
            cin >> elem;
            cout << "enter the priority" << endl;
            cin >> loc;
            q.enqueue(elem, loc);
            count++;
            cout << "if you want to continue enter yes" << endl;
            cin >> check;
        }
        else if (choose == 2)
        {
            int i = 0;
            if (count == 0) {
                cout << "Queue is Empty" << endl;
            }
            while (i < count) {
                cout << q.dequeue() << " ";
                i++;
            }
            count = 0;
            cout << endl << "if you want to continue enter yes" << endl;
            cin >> check;
        }
        else {
            cout << "wrong choose" << endl << "please try again" << endl;
            check = "yes";
        }
    } while (check == "yes");
    return 0;
}
