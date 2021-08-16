#include <iostream>
#include <unordered_map>
#define nl << "\n"
using namespace std;

int main()
{
	//Implemented internally as hash table
	//Relative ordering doesn't matter in that we can use hashmap

	unordered_map <string , int>  m;

	//Average taken into account because in case of rehashing it could be O(n)
	//O(1) on average
	m.insert(make_pair("Mango" , 100));
	m.insert(make_pair("Apple" , 130));
	m.insert(make_pair("Banana" , 130));

	auto it = m.find("Banana");
	
	//O(1) on average
	if(it != m.end())
		m.erase(it);

	//O(1) on average 
	auto it1 = m.find("Apple");
	if(it != m.end())
		cout << (*it1).first << " => " << (*it1).second;

	cout nl;
}