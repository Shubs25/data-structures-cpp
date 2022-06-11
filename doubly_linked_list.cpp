#include <iostream>
#include <string>

using namespace std;

class Node
{
    private:
        string data;
        Node *prev;
        Node *next;
        friend class DoublyLinkedList;
};

class DoublyLinkedList
{
    private:
        Node *head, *tail;
    protected:
        void insert(const string&, Node*);      // Inserts before the given node
        void remove(Node*);     // Removes the given node
    public:
        DoublyLinkedList();     // To set up the DLL
        bool is_empty() const;      // true if list is empty else false
        const string& get_front() const;        // Return the first item of the list
        const string& get_end() const;      // Return the last item of the list
        void insert_front(const string&);       // Inserts at the beginning
        void insert_end(const string&);     // Inserts at the end
        void remove_front();        // Removes the front most element
        void remove_end();      // Removes the last element
        void show_all();        // Prints all the items in the list
        void reverse();
        ~DoublyLinkedList();        // Deletes all the mess created
};

DoublyLinkedList :: DoublyLinkedList()
{
    /* Inititally the list is empty.
    Making the head and tail to point to each other.
    Note that head is present BEFORE the first node whereas
    tail is present AFTER the last node */

    head = new Node, tail = new Node;       // This time head and tail are actual nodes
    head->next = tail;
    head->prev = NULL;      // Not necessary
    tail->prev = head;
    tail->next = NULL;      // Not necessary
}

bool DoublyLinkedList :: is_empty() const { return head->next == tail; }        // Checks if head is pointing to tail

const string& DoublyLinkedList :: get_front() const { return head->next->data; }        // Returns the data of the node next to the head

const string& DoublyLinkedList :: get_end() const { return tail->prev->data; }      // Returns the data of the node preceding the tail

void DoublyLinkedList :: insert(const string& nm, Node* beforeMe)
{
    /* Creating and attaching a new node at its proper place.
    All while taking care of the next and prev pointers. */

    Node *newNode = new Node;
    newNode->data = nm;
    newNode->prev = beforeMe->prev;
    newNode->next = beforeMe;
    beforeMe->prev->next = newNode;
    beforeMe->prev = newNode;
}

void DoublyLinkedList :: insert_front(const string& nm){ insert(nm, head->next); }      // Insert a node before the first node (after head)

void DoublyLinkedList :: insert_end(const string& nm) { insert(nm, tail); }     // Insert a node before the tail

void DoublyLinkedList :: remove(Node* deleteMe)
{
    /* Deleting a node all while taking care of the pointers. */

    if(deleteMe == tail)        // If the list is empty
        return;
    deleteMe->next->prev = deleteMe->prev;      // Making the next pointer to point to the previous pointer
    deleteMe->prev->next = deleteMe->next;      // Vice-versa of above
    delete deleteMe;        // Actually deleting the pointer
}

void DoublyLinkedList :: remove_front() { remove(head->next); }     // Removing the first node (next to the head)

void DoublyLinkedList :: remove_end() { remove(tail->prev); }       // Removing the last node (preceding the tail)

void DoublyLinkedList :: show_all()
{
    /* Displaying all the nodes in the DLL */

    Node* temp;
    temp = head->next;      // Starting at the first node (next to the head)
    while(temp != tail)       // Till we not reach tail
    {
        cout << temp->data << " <--> ";     // Printing
        temp = temp->next;      // Moving on to the next node
    }
    cout << endl;
}

void DoublyLinkedList :: reverse()
{
    DoublyLinkedList temp;
    string stemp;
    while(!this->is_empty())
    {
        stemp = this->get_front();
        temp.insert_end(stemp);
        this->remove_front();
    }
    while (!temp.is_empty())
    {
        stemp = temp.get_front();
        this->insert_front(stemp);
        temp.remove_front();
    }
    
}

DoublyLinkedList :: ~DoublyLinkedList()
{
    /* Deleting all the contents associated with the DLL */

    while(!is_empty())
        remove_front();     // Delete all the elements enclosed within head and tail
    delete head;
    delete tail;        // Deleting the head and the tail
}

// Driver code
int main()
{
    DoublyLinkedList dll1;
    dll1.insert_end("AAA");
    dll1.insert_end("BBB");
    dll1.insert_end("CCC");
    dll1.insert_end("DDD");
    dll1.insert_end("EEE");
    dll1.show_all();
    dll1.insert_front("FFF");
    dll1.show_all();
    dll1.remove_front();
    dll1.show_all();
    dll1.remove_end();
    dll1.show_all();
    dll1.reverse();
    dll1.show_all();
    dll1.reverse();
    dll1.show_all();
    return 0;
}

/*
                OUTPUT
AAA <--> BBB <--> CCC <--> DDD <--> EEE <-->
FFF <--> AAA <--> BBB <--> CCC <--> DDD <--> EEE <-->
AAA <--> BBB <--> CCC <--> DDD <--> EEE <-->
AAA <--> BBB <--> CCC <--> DDD <-->

*/