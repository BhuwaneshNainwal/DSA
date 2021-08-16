#include <iostream>
#include <vector>
#include <algorithm>
 #define nl << "\n"
using namespace std;

int main()
{
	vector <int> a(6 , 0);
	vector <int> b {6 , 7 , 8 , 9 , 9};
	vector <int> c(b.begin() , b.end());

	for(auto val : c)
		cout << val << " " ;
	cout nl;

	vector <int> d(6);

	for(auto &val : d)
		cin >> val;

	for(auto val : d)
		cout << val << " ";
	cout nl;

	vector <int> e;
	for(int i = 0 ; i < 5 ; i++)
	{
		int num;
		cin >> num;
		e.push_back(num);

	}
	cout << e.size() nl; //number of elements
	cout << e.capacity() nl; // total holding capacity without more resize
	cout << e.max_size()  nl nl; //max possible size on RAM

//----------------------------------------------------------------


	vector<int> p{1 , 2 , 3 , 4 , 5};

	//O(1) in most of the cases

	p.push_back(7);

	//o(1) 
	p.pop_back();

	// pop_back() doesn't work here

	for(auto val : p)
		cout << val << " ";

	cout nl;

	//o(N) where N = total elements added + total elements shifted
	p.insert(p.begin() + 2 , 5 , 50);
	p.erase(p.begin() + 1);
	p.erase(p.begin() + 1 , p.begin() + 5);


	for(auto val : p)
		cout << val << " ";
	cout nl;

	//shrink operation is avoided for underlying capacity
	cout << p.size() nl;
	cout << p.capacity() nl;

	p.resize(3);
	
	cout << p.size() nl;
	cout << p.capacity() nl;	

	for(auto val : p)
		cout << val << " ";
	cout nl;

	//This free the memory occupied by vector

	p.clear();

	if(p.empty())
		cout << "vector p is empty" nl;

	cout << p.size() nl;
	cout << p.capacity() nl;

	p.push_back(11);
	p.push_back(12);
	p.push_back(16);

	cout << p.front() << " " << p.back() nl;

	vector<int> vec;

	int n;

	cin >> n; 
	
	for(int i = 0 ; i < n ; i++)
	{
		int val;
		cin >> val;
		vec.push_back(val);
		cout << vec.capacity() << " ";
	}

	cout nl;
	vector<int> vec1;

	//To stop doubling vector till n
	vec1.reserve(n);

	for(int i = 0 ; i < n ; i++)
	{
		int num;
		cin >> num;
		vec1.push_back(num);
		cout << vec1.capacity() << " ";
	}

	cout nl;

	vec1.push_back(11);

	cout << vec1.capacity();

	vector<int> vec2;

	vec2.emplace_back(4);

	for(auto c : vec2)
		cout << c nl;
}