#include <iostream>
#include <map>
#include <string>

#define nl << "\n"

using namespace std;

int main()
{
	//Implemented using self BST
	//Muliple elements can have same key
	multimap <char , string> m;

	int n;
	cin >> n;

	for(int i = 0 ; i < n ; i++)
	{
		char c;
		string str;
		cin >> c >> str;
		m.insert({c , str}); // or m.insert(make_pair(c , str))	
	}

	for(auto p : m)
		cout << p.first << " => " << p.second nl;
	cout nl;

	//square bracket (access operator) doesn't work here i.e , [] 


	auto it1 = m.lower_bound('B');
	auto it2 = m.upper_bound('B');

	for(auto it = it1 ; it != it2 ; it++)
		cout << it -> first << " => " << it -> second nl;

	cout nl;
	m.insert({'C' , "cat"});

	// Erase all occurences of B
	// O(n)

	m.erase('B');

	//Erase first occurence of C
	//Amortized O(1)
	auto it = m.find('C');
	m.erase(it);

	for(auto p : m)
		cout << p.first << " => " << p.second nl;
	

}