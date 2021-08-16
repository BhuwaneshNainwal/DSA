#include <queue>
#include <iostream>

using namespace std;

int main()
{
	//Based on first in first out
	queue<int> q;

	int n;
	cin >> n;
	for(int i = 0 ; i < n ; i++)
		q.push(i); //O(1)

	while(!q.empty())
	{
		cout << q.front() << "\n";
		q.pop(); //O(1)
	}
}