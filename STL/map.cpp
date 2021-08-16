#include <iostream>
#include <map>
#include <string>

#define nl << "\n"
using namespace std;

int main()
{	
	//Map is implemented internally as self balancing binary tree
	//It only stores unique keys or modifies existing ones
		
	map<string , int> m;

	m.insert(make_pair("Mango" , 100));

	pair<string , int> p;
	p.first = "Apple";
	p.second = 120;
	
	m.insert(p);

	m["Banana"] = 30;

	string fruit;
	cin >> fruit;

	//O(log n)

	auto it = m.find(fruit);
	
	if(it == m.end())
		cout << "Not present" nl; 
	else
		cout << "Price of fruit is : " << m[fruit] nl; 

	cin >> fruit;

	if(m.count(fruit) == 1)
		cout << "Price of " << fruit << "is : " << m[fruit] nl;
	else
		cout << "Not present" nl;

	//Amortized constant O(1)

	m.erase(fruit);

	if(m.count(fruit) == 1)
		cout << "Price of " << fruit << "is : " << m[fruit] nl;
	else
		cout << "Not present" nl;
	
	cout nl;

	m["Papaya"] = 30;
	m["Kiwi"] = 40;

	for(auto it = m.begin() ; it != m.end() ; it++)
		cout << it -> first << " " << it -> second nl; // (*it).first and (*it).second

	cout nl;

	for(auto p : m)
		cout << p.first << " " << p.second nl;

	cout nl;

	auto it1 = m.find("Apple");
	auto it2 = m.find("Mango");

	//O(n) in distance(it1 , it2)
	m.erase(it1 , it2);

	for(auto p : m)
		cout << p.first << " " << p.second nl;
	cout nl;

	//O(log n)
	auto ip = m.erase("Mango");
	for(auto p : m)
		cout << p.first << " " << p.second nl;

}