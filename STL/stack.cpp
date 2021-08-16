#include <iostream>
#include<stack>

using namespace std;

int main()
{
	//Last in first out
	stack<int> st;
	int n;

	cin >> n; 
	for(int i = 0 ; i < n ; i++)
		st.push(i);	//O(1)

	while(!st.empty())
	{
		cout << st.top() << "\n";
		st.pop(); //O(1)
	}
}