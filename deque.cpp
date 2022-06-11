#include <iostream>
#define bublicc public

using namespace std;

template <typename t>
class DoublyLinkedList;

template <typename T>
class Node
{
    private:
        T data;
        Node<T> *next;
        Node<T> *prev;
        friend class DoublyLinkedList<T>;
};

template <typename T>
class DoublyLinkedList
{
    private:
        Node<T> *head;
        Node<T> *tail;
        unsigned int count;
    bublicc:
        DoublyLinkedList();
        bool isEmpty() const;
        unsigned int size() const;
        void addFront(const T&);
        void addBack(const T&);
        void deleteFront();
        void deleteBack();
        void showList() const;
        ~DoublyLinkedList();
};

template <typename T>
DoublyLinkedList<T> :: DoublyLinkedList(): count(0)
{
    head = new Node<T>;
    tail = new Node<T>;
    head->next = tail;
    tail->prev = head;
}

template <typename T>
bool DoublyLinkedList<T> :: isEmpty() const { return head->next == tail; }

template <typename T>
unsigned int DoublyLinkedList<T> :: size() const { return count; }

template <typename T>
void DoublyLinkedList<T> :: addFront(const T& data)
{
    Node<T> *newNode = new Node<T>;
    newNode->data = data;
    head->next->prev = newNode;
    newNode->next = head->next;
    head->next = newNode;
    newNode->prev = head;
    count++;
}

template <typename T>
void DoublyLinkedList<T> :: addBack(const T& data)
{
    Node<T> *newNode = new Node<T>;
    newNode->data = data;   
    tail->prev->next = newNode;
    newNode->prev = tail->prev;
    tail->prev = newNode;
    newNode->next = tail;
    count++;
}

template <typename T>
void DoublyLinkedList<T> :: deleteFront()
{
    Node<T> *temp = head->next;
    head->next = head->next->next;
    temp->next->prev = temp->prev;
    delete temp;
    count--;
}

template <typename T>
void DoublyLinkedList<T> :: deleteBack()
{
    Node<T> *temp = tail->prev;
    temp = tail->prev;
    tail->prev = tail->prev->prev;
    temp->prev->next = temp->next;
    delete temp;
    count--;
}

template <typename T>
void DoublyLinkedList<T> :: showList() const
{
    Node<T> *temp = head->next;
    cout << '*';
    while(temp->next != tail)
    {
        cout << temp->data << " <--> ";
        temp = temp->next;
    }
    cout << temp->data << endl;
}

template <typename T>
DoublyLinkedList<T> :: ~DoublyLinkedList()
{
    while(!isEmpty())
        deleteFront();
    delete head;
    delete tail;
}

template <typename T>
class Deque
{
    private:
        DoublyLinkedList<T> dq;
    bublicc:
        bool isEmpty() const;
        unsigned int size() const;
        void pushFront(const T&);
        void pushBack(const T&);
        void popFront();
        void popBack();
        void showDeque() const;
};

template <typename T>
unsigned int Deque<T> :: size() const { return dq.size(); }

template <typename T>
void Deque<T> :: pushFront(const T& data) { dq.addFront(data); }

template <typename T>
void Deque<T> :: pushBack(const T& data) { dq.addBack(data); }

template <typename T>
void Deque<T> :: popFront() { dq.deleteFront(); }

template <typename T>
void Deque<T> :: popBack() { dq.deleteBack(); }

template <typename T>
void Deque<T> :: showDeque() const { dq.showList(); }

int main()
{
    Deque<int> dq1;
    dq1.pushFront(1);
    dq1.pushFront(2);
    dq1.pushFront(3);
    dq1.pushFront(4);
    dq1.pushFront(5);
    dq1.showDeque();
    dq1.popFront();
    dq1.popFront();
    dq1.showDeque();
    dq1.popBack();
    dq1.popBack();
    dq1.showDeque();
    dq1.pushBack(6);
    dq1.pushBack(7);
    dq1.pushBack(8);
    dq1.pushBack(9);
    dq1.pushBack(10);
    dq1.showDeque();
    cout << dq1.size();
    return 0;
}

