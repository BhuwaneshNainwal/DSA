#include <list>
#include <iostream>
#define nl << "\n"
using namespace std;

int main()
{
	//List => doubly linked list

	list<int> l1{5 , 2 , 1 , 4 , 3};

	l1.sort();
	l1.reverse();
	
	for(auto val : l1)
		cout << val << " ---> ";

	l1.pop_back();

	cout nl;
	cout << l1.back() nl;

	l1.pop_front();

	cout << l1.front() nl;

	l1.push_front(11);
	l1.push_back(12);

	for(auto val : l1)
		cout << val << " ---> ";
	cout nl;

	for(auto it = l1.begin() ; it != l1.end() ; it++)
		cout << (*it) << " ---> ";

	cout nl;
//-------------------------------------------------------------------------


	list<string> l2{"mango" , "apple" , "apple" , "kiwi" , "grapes"};
	
	//O(n)

	l2.remove("apple");

	for(auto str : l2)
		cout << str << " ---> "; 

	cout nl;
	// auto it = l2.begin() + 2 then l2.remove(it)  => This won't work here because memory is not contiguous

	//Also direct access operator doesn't work ([])
	auto it = l2.begin();
	it++;
	it++;


	//O(1)
	l2.erase(it);

	for(auto val : l2)
		cout << val << "--->";
	cout nl;

	it = l2.begin();
	it++;
	it++;

	//O(1)
	l2.insert(it , "coconut");

	//it still pointing next to last element

	l2.insert(it , 3 , "papaya");

	for(auto val : l2)
		cout << val << "--->";
}	