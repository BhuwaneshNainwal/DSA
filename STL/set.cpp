#include <iostream>
#include <set>
#define nl << "\n"

using namespace std;

int main()
{
	//BST or RBT
	//Unique elements in sorted order
	set<int> s{4 , 3 , 2 , 1};

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

	//O(log n)
	s.insert(11);
	s.insert(11);

	for(auto val : s)
		cout << val << " ";
	cout nl;
}