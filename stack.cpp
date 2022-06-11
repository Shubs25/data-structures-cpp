#include <iostream>
#include <string>

using namespace std;

template <typename someThing>
class SinglyLinkedList;

template <typename dataType>
class Node
{
    private:
        dataType data;
        Node<dataType> *next;
        friend class SinglyLinkedList<dataType>;
};

template <typename T>
class SinglyLinkedList
{
    private:
        Node<T> *head;
    public:
        SinglyLinkedList(): head(NULL) {}
        bool empty() const;
        const T& front() const;
        void addFront(const T&);
        void removeFront();
        void showList() const;
        ~SinglyLinkedList();
};

template <typename T>
bool SinglyLinkedList<T> :: empty() const { return head == NULL; }

template <typename T>
const T& SinglyLinkedList<T> :: front() const { return head->data; }

template <typename T>
void SinglyLinkedList<T> :: addFront(const T& d)
{
    Node<T> *newNode = new Node<T>;
    newNode->data = d;
    newNode->next = head;
    head = newNode;
}

template <typename T>
void SinglyLinkedList<T> :: removeFront()
{
    Node<T> *temp = head;
    head = head->next;
    delete temp;
}

template <typename T>
void SinglyLinkedList<T> :: showList() const
{
    Node<T>  *temp = head;
    while(temp != NULL)
    {
        cout << temp->data << " --> ";
        temp = temp->next;  
    }
    cout << endl;
}

template <typename T>
SinglyLinkedList<T> :: ~SinglyLinkedList()
{
    while(!empty())
        removeFront();
}

template <typename Type>
class Stack
{
    private:
        unsigned int size_;
        SinglyLinkedList<Type> s;
    public:
        Stack(): size_(0) {}
        void push(const Type&);
        void pop();
        unsigned int size() const;
        bool empty() const;
        void showStack() const;
        ~Stack();
};

template <typename Type>
void Stack<Type> :: push(const Type& elem) { s.addFront(elem); size_++; }

template <typename Type>
void Stack<Type> :: pop() { s.removeFront(); size_--; }

template <typename Type>
unsigned int Stack<Type> :: size() const { return size_; }

template <typename Type>
bool Stack<Type> :: empty() const { return s.empty(); }

template <typename Type>
void Stack<Type> :: showStack() const { s.showList(); }

template <typename Type>
Stack<Type> :: ~Stack()
{
    while(!this->empty())
        this->pop();
}


int main()
{
    Stack<int> s1;
    Stack<char> s2;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.showStack();
    s1.pop();
    s1.pop();
    s1.showStack();

    s2.push('a');
    s2.push('b');
    s2.push('c');
    s2.push('d');
    s2.showStack();
    s2.pop();
    s2.showStack();
    return 0;
}


/*
bool parenCheck(const string& sequence)
{
    Stack<char> parenStack;
    for(int i = 0; i < sequence.length(); ++i)
    {
        if(sequence[i] == '[' || sequence[i] == '{' || sequence[i] == '<' || sequence[i] == '(')    // if opening then push onto the stack
            parenStack.push(sequence[i]);

        else if(sequence[i] == ']' || sequence[i] == '}' || sequence[i] == '>' || sequence[i] == ')')   // if closing then pop out of the stack
        {
            if(parenStack.size() == 0) return false;
            parenStack.pop();
        }  

        // else do nothing. Continue onto the next iteration
    }
    if(parenStack.size() != 0)
        return false;
    return true;
}

int main(void)
{
    cout << parenCheck("(25 + pow(26, (pow(3 + (81 -2), (x - 56 * (254 / (1 + y))))))) / (98 - pow(x, 245))") << endl;
    return 0;
}
*/
