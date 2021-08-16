#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int arr[] = {2 , 5 , 6 , 6 , 6 , 7};
	int n = sizeof(arr) / sizeof(int);

	int key;
	cin >> key;

	// O(log n) time

	bool found = binary_search(arr , arr + n , key);
	
	if(found)
		cout << "found" << "\n";
	else
		cout << "Not found" << "\n";

	cin >> key;

	//o(log n) time
	auto lb = lower_bound(arr , arr + n , key);

	if(lb - arr == n)
		cout << "Not found!" << "\n";
	else
		cout << "found at index : " << lb - arr << "\n";

	auto ub = upper_bound(arr , arr + n , key);

	if(ub - arr == n)
		cout << "Not found!" << "\n";
	else
		cout << "found at index : " << ub - arr << "\n";

	cout << "frequency of element is : " << ub - lb << "\n";

	vector<int> arr1 = {9 , 5 , 3 , 3 , 2};

	cin >> key;
	auto lb1 = lower_bound(arr1.begin() , arr1.end() , key , greater<int> ());

	if(lb1 == arr1.end())
		cout << "Not found!" << "\n";
	else
		cout << "found at index : " << lb1 - arr1.begin() << "\n";
	
	// cin >> key;
	auto ub1 = upper_bound(arr1.begin() , arr1.end() , key , greater<int> ());

	if(ub1 == arr1.end())
		cout << "Not found!" << "\n";
	else
		cout << "found at index : " << ub1 - arr1.begin() << "\n";

} 
