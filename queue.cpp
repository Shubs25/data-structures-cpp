#include <iostream>
#define bublicc public

using namespace std;

template <typename Bruh>
class CircularlyLinkedList;

template <typename T>
class Node
{
    private:
        T data;
        Node<T> *next;
        friend class CircularlyLinkedList<T>;
};

template <typename T>
class CircularlyLinkedList
{
    private:
        Node<T> *cursor;
    bublicc:
        CircularlyLinkedList(): cursor(NULL) {}
        bool isEmpty() const;
        const T& front() const;
        void add(const T&, const bool = true);
        void deleteFront();
        ~CircularlyLinkedList();
        void showList() const;
};

template <typename T>
bool CircularlyLinkedList<T> :: isEmpty() const { return cursor == NULL; }

template <typename T>
const T& CircularlyLinkedList<T> :: front() const { return cursor->next->data; }

template <typename T>
void CircularlyLinkedList<T> :: add(const T& data_, const bool back)
{
    Node<T> *newNode = new Node<T>;
    newNode->data = data_;
    if(isEmpty())
    {
        cursor = newNode;
        cursor->next = cursor;
    }
    else
    {
        newNode->next = cursor->next;
        cursor->next = newNode;
        if(back) cursor = newNode;
    }
    
}

template <typename T>
void CircularlyLinkedList<T> :: deleteFront()
{
    Node<T> *temp = new Node<T>;
    temp = cursor->next;
    if(temp == cursor)
    {
        cursor = NULL;
        return;
    }
    cursor->next = cursor->next->next;
    delete temp;
}

template <typename T>
void CircularlyLinkedList<T> :: showList() const
{
    Node<T> *temp = cursor->next;
    cout << '*';
    while(temp != cursor)
    {
        cout << temp->data << " --> ";
        temp = temp->next;
    }
    cout << temp->data << endl;
}

template <typename T>
CircularlyLinkedList<T> :: ~CircularlyLinkedList()
{
    while(!isEmpty())
        deleteFront();
}

template <typename T>
class Queue
{
    private:
       CircularlyLinkedList<T> q;
       unsigned int count;
    bublicc:
        Queue(): count(0) {}
        bool isEmpty() const;
        void pushBack(const T&);
        void popFront();
        unsigned int size() const;
        void showQueue() const;
        ~Queue();
};

template <typename T>
bool Queue<T> :: isEmpty() const { return count == 0; }

template <typename T>
void Queue<T> :: pushBack(const T& data) { q.add(data); count++; }

template <typename T>
void Queue<T> :: popFront() { q.deleteFront(); count--; }

template <typename T>
unsigned int Queue<T> :: size() const { return count; }

template <typename T>
void Queue<T> :: showQueue() const { q.showList(); }

template <typename T>
Queue<T> :: ~Queue()
{
    while(!isEmpty())
        popFront();
}

int main()
{
    Queue<int> q1;
    q1.pushBack(1);
    q1.pushBack(2);
    q1.pushBack(3);
    q1.pushBack(4);
    q1.pushBack(5);
    q1.showQueue();
    q1.popFront();
    q1.popFront();
    q1.popFront();
    q1.showQueue();
    
    return 0;
}