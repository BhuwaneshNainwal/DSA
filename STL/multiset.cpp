#include <iostream>
#include <set>
#define nl << "\n"

using namespace std;

typedef multiset<int>::iterator It;


int main()
{
	//Implmented internally as BST
	//It can store multiple elements that have same elements
	//Stored at specific sorted order
	//Values once inserted can't be modified
	//Associative containers => elements known by their value and not by their index

	multiset<int> s{4 , 4 , 3 , 3 , 2 , 1};

	for(auto c : s)
		cout << c << " ";
	cout nl nl;
	
	//O(Log n)
	s.erase(3);

	//O(1) Amortized
	auto it = s.find(2);
	s.erase(it);

	for(auto val : s)
		cout << val << " ";

	cout nl nl;

	//O(Log n)
	s.insert(11);
	s.insert(11);

	for(auto val : s)
		cout << val << " ";
	cout nl nl;

	//O(Log n)
	cout << "count : " << s.count(11);
	cout nl nl;

	pair<It , It> range = s.equal_range(11);

	for(auto it = range.first ; it != range.second ; it++)
		cout << (*it) << " ";
	cout  nl nl;

	for(auto it = s.lower_bound(4) ; it != s.upper_bound(4) ; it++)
		cout << (*it) << " ";
}