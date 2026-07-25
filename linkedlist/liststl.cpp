#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

int main()
{

    // Create a list
    list<int> l = {10, 20, 30};

    // push_back()
    l.push_back(40);

    // push_front()
    l.push_front(5);

    cout << "After push_front & push_back: ";
    for (int x : l)
        cout << x << " ";
    cout << endl;

    // front() and back()
    cout << "Front = " << l.front() << endl;
    cout << "Back = " << l.back() << endl;

    // insert()
    auto it = l.begin();
    advance(it, 2); // Move iterator to 3rd position
    l.insert(it, 15);

    cout << "After insert: ";
    for (int x : l)
        cout << x << " ";
    cout << endl;

    // erase()
    it = l.begin();
    advance(it, 3);
    l.erase(it);

    cout << "After erase: ";
    for (int x : l)
        cout << x << " ";
    cout << endl;

    // pop_front()
    l.pop_front();

    // pop_back()
    l.pop_back();

    cout << "After pop_front & pop_back: ";
    for (int x : l)
        cout << x << " ";
    cout << endl;

    // size()
    cout << "Size = " << l.size() << endl;

    // empty()
    if (l.empty())
        cout << "List is Empty\n";
    else
        cout << "List is Not Empty\n";

    // reverse()
    l.reverse();

    cout << "After reverse: ";
    for (int x : l)
        cout << x << " ";
    cout << endl;

    // sort()
    l.push_back(50);
    l.push_back(25);
    l.push_back(35);

    l.sort();

    cout << "After sort: ";
    for (int x : l)
        cout << x << " ";
    cout << endl;

    // remove()
    l.push_back(25);
    l.remove(25);

    cout << "After remove(25): ";
    for (int x : l)
        cout << x << " ";
    cout << endl;

    // unique()
    l = {1, 1, 2, 2, 2, 3, 3, 4, 4};
    l.unique();

    cout << "After unique(): ";
    for (int x : l)
        cout << x << " ";
    cout << endl;

    // merge()
    list<int> a = {1, 3, 5};
    list<int> b = {2, 4, 6};

    a.merge(b);

    cout << "After merge: ";
    for (int x : a)
        cout << x << " ";
    cout << endl;

    // splice()
    list<int> c = {100, 200};
    list<int> d = {300, 400};

    c.splice(c.end(), d);

    cout << "After splice(): ";
    for (int x : c)
        cout << x << " ";
    cout << endl;

    // clear()
    c.clear();

    cout << "After clear(), Size = " << c.size() << endl;

    return 0;
}