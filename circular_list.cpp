#include <iostream>
#include <string>

using namespace std;

class Node
{
    private:
        string data;
        Node *next;
        friend class CircularlyLinkedList;
};

class CircularlyLinkedList
{
    private:
        Node *cursor;
    public:
        CircularlyLinkedList(): cursor(NULL) {}
        bool is_empty() const;
        const string& get_front() const;
        const string& get_end() const;
        void insert(const string&);
        void remove();
        void show_all(unsigned int) const;
        ~CircularlyLinkedList();
};

bool CircularlyLinkedList :: is_empty() const { return cursor == NULL; }

const string& CircularlyLinkedList :: get_front() const { return cursor->next->data; }

const string& CircularlyLinkedList :: get_end() const { return cursor->data; }

void CircularlyLinkedList :: insert(const string& dat)
{
    Node *newNode = new Node, *temp = cursor;
    newNode->data = dat;
    cursor = newNode;
    if(temp == NULL)
        cursor->next = cursor;
    else
    {
        cursor->next = temp->next;
        temp->next = cursor;
    }
}

void CircularlyLinkedList :: remove()
{
    Node *temp = cursor->next;
    cursor->next = cursor->next->next;
    delete temp;
}

void CircularlyLinkedList :: show_all(unsigned int times) const
{
    Node *temp = cursor;
    while(times != 0)
    {
        cout << temp->data << " --> ";
        temp = temp->next;
        times--;
    }
    cout << endl;
}

CircularlyLinkedList :: ~CircularlyLinkedList()
{
    Node *temp = cursor->next;
    while(cursor->next != cursor)
        remove();
    delete cursor;
}

int main()
{
    CircularlyLinkedList cll1;
    cll1.insert("AAA");
    cll1.insert("BBB");
    cll1.insert("CCC");
    cll1.insert("DDD");
    cll1.insert("EEE");
    cll1.show_all(10);
    cll1.remove();
    cll1.show_all(15);
    cll1.remove();
    cll1.show_all(20);
    cll1.insert("FFF");
    cll1.insert("GGG");
    cll1.insert("HHH");
    cll1.insert("III");
    cll1.show_all(10);

    return 0;
}