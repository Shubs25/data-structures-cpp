#include <iostream>
#include <string>

using namespace std;

class Node
{
    private:
        string data;
        Node *next;
        friend class SinglyLinkedList;
};

class SinglyLinkedList
{
    private:
        Node *head;
    public:
        SinglyLinkedList(): head(NULL) {}
        bool is_empty() const;
        const string& show_front() const;
        void insert_front(const string&);
        void remove_front();
        void show_all();
        ~SinglyLinkedList();
};

bool SinglyLinkedList :: is_empty() const { return head == NULL; }

const string& SinglyLinkedList :: show_front() const { return head->data; }

void SinglyLinkedList :: insert_front(const string& nm) 
{
    Node *temp = head, *newNode = new Node;
    newNode->data = nm;
    head = newNode;
    newNode->next = temp;
}

void SinglyLinkedList :: remove_front()
{
    Node *temp = head;
    head = temp->next;
    delete temp;
}

void SinglyLinkedList :: show_all()
{
    Node *temp = head;
    while(temp != NULL)
    {
        cout << temp->data << " --> ";
        temp = temp->next;
    }
    cout << endl;
}

SinglyLinkedList :: ~SinglyLinkedList()
{
    while(!is_empty())
        remove_front();
}

// Driver code
int main(void)
{
    SinglyLinkedList sll1;
    sll1.insert_front("ABC");
    sll1.insert_front("DEF");
    sll1.insert_front("GHI");
    sll1.show_all();
    sll1.remove_front();
    sll1.show_all();
    return 0;
}