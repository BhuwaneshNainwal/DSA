#include <iostream>
#include <cstring>
#include <queue>
#define nl << "\n"
using namespace std;
	

class Person
{

public:
	string name;
	int age;

	//Constructor
	Person(string n , int a)
	{
		name = n;
		age = a;
	}
};

class Person_compare
{	

public:
	//Overloaded functions used for user defined variables
	bool operator()(Person A , Person B)
	{
		return A.age < B.age;
	}
};

int main()
{
	int n;
	cin >> n;

	//Priority queue accepts comparator class

	priority_queue<Person , vector<Person> , Person_compare> pq;
	for(int i = 0 ; i < n ; i++)
	{
		string name;
		int age;

		cin >> name >> age;
		Person p(name , age);

		pq.push(p);
	}

	int k;
	cin >> k;

	for(int i = 0 ; i < k ; i++)
	{
		Person p = pq.top();
		cout << p.name << " " << p.age nl;
		pq.pop();
	}

}