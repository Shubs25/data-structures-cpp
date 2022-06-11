#include <iostream>
#include <vector>

using namespace std;

class Node
{
    private:
        int data;
        Node *parent;
        vector<Node *> children;
    public:
        Node(int val): data(val) { parent = NULL; }
        bool isLeaf() const;
        bool isRoot() const;
        int& operator*() { return data; }
        void addChildren(const int);        // Try to avoid this one
        void addChildren(Node&);
        Node& myParent() const;
        vector<Node *>& myChildren();
        void display() const;
        friend unsigned int height(Node&);
};

bool Node :: isLeaf() const { return children.empty(); }

bool Node :: isRoot() const { return parent == NULL; }

void Node :: addChildren(const int cVal)
{
    Node *child = new Node(cVal);
    // child->data = cVal;
    child->parent = this;
    children.push_back(child);
}

void Node :: addChildren(Node& child)
{
    child.parent = this;
    children.push_back(&child);
}

Node& Node :: myParent() const { return *parent; }

vector<Node *>& Node :: myChildren() { return children; } 

unsigned int depth(const Node& p)
{
    if(p.isRoot()) return 0;
    return 1 + depth(p.myParent());
}

unsigned int height(Node& rt)
{
    if(rt.isLeaf()) return 0;
    unsigned int h = 0;
    vector<Node *> :: iterator i;
    i = rt.myChildren().begin();
    for(; i != rt.myChildren().end(); ++i)
        h = max(h, height(**i));
    return 1 + h;

}


int main(void)
{   
    Node root(0);
    Node n1(1), n2(2), n3(3), n4(4), n5(5);
    root.addChildren(n1);
    root.addChildren(n2);
    root.addChildren(n3);
    n3.addChildren(n4);
    n3.addChildren(n5);
    n5.addChildren(6);

    cout << depth(n5) << endl;
    cout << root.isRoot() << ":" << root.isLeaf() << endl;
    cout << n1.isRoot() << ":" << n1.isLeaf() << endl;
    cout << n2.isRoot() << ":" << n2.isLeaf() << endl;
    cout << n3.isRoot() << ":" << n3.isLeaf() << endl;
    cout << n4.isRoot() << ":" << n4.isLeaf() << endl;
    cout << n5.isRoot() << ":" << n5.isLeaf() << endl;

    cout << height(root) << endl;




    return 0;
}
