#include <iostream>
#include <list>

using namespace std;

class PriorityQueue
{
    private:
        list<int> l;
    public:
        bool isEmpty() const { return l.empty(); }
        int size() const { return l.size(); }
        void insert(const int);
        int min() { return l.front(); }
        void removeMin() { l.pop_front(); }
        void display() const;
};

void PriorityQueue :: insert(const int e)
{
    list<int> :: iterator i;
    i = l.begin();
    while(i != l.end() && e >= *i) ++i;
    l.insert(i, e);
}

void PriorityQueue :: display() const
{
    list<int> :: const_iterator i;
    i = l.begin();
    for(; i != l.end(); ++i) cout << *i << " ";
    cout  << endl;
}

int main(void)
{
    PriorityQueue pq1;
    pq1.insert(20);
    pq1.insert(21);
    pq1.insert(22);
    pq1.insert(23);
    pq1.insert(24);
    pq1.insert(1);
    pq1.insert(2);
    pq1.insert(25);
    pq1.display();
    cout << pq1.min() << endl;
    pq1.removeMin();
    pq1.display();
    cout << pq1.min() << endl;

    return EXIT_SUCCESS;
}