#include <iostream>
#include <queue>

using namespace std;

int main()
{
	// Max heap
	priority_queue<int> pq;

	//Min heap
	priority_queue<int , vector<int> , greater<int>> pq1;


	int n;
	cin >> n;

	for(int i = 0 ; i < n ; i++)
	{
		int num;
		cin >> num;
		pq.push(num);  //O(logn)
	}

	while(!pq.empty())
	{
		cout << pq.top() << " ";  //O(1)
		pq.pop();  //O(logn)
	}
}