#include <bits/stdc++.h>

typedef long long int ll;

using namespace std;

int main()
{
	ll q , k;

	cin >> q >> k;
	
	priority_queue<ll> pq;

	ll val;

	while(q --)
	{
		ll type;
		
		cin >> type;

		if(type == 1)
		{
			ll x , y;
			cin >> x;
			cin >> y;
			ll two = 2;
			val = x * x + y * y;
		}
		
		

		if(type == 1)
		{
			if(st.size() < k)
				st.insert(val);
				
			else if(val <= pq.top())
			{
				pq.pop(); //O(1) Amortized				
				pq.push(val);
			}	
		}
		else
			cout << pq.top() << "\n";

	}
}