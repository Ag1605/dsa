#include <bits/stdc++.h>
using namespace std;

class Student
{
public:
    string name;
    int marks;

    Student(string n, int m)
    {
        name = n;
        marks = m;
    }
};

class Compare
{
public:
    bool operator()(Student a, Student b)
    {
        return a.marks > b.marks;
    }
};

int main()
{

    priority_queue<Student, vector<Student>, Compare> pq;

    pq.push(Student("Akshat", 85));
    pq.push(Student("Rahul", 95));
    pq.push(Student("Aman", 80));

    while (!pq.empty())
    {
        cout << pq.top().name << " "
             << pq.top().marks << endl;

        pq.pop();
    }
}