#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int arr[] = {4 , 5 , 1 , 7};
	int n = sizeof(arr) / sizeof(int);

	int key; 
	cin >> key;

	//o(n) time
	
	auto it = find(arr , arr + n , key);
	if(it == arr + n)
		cout << "Not found" << "\n";
	else 
		cout << "found at : " << it - arr << "\n"; 

} 
