#include <bits/stdc++.h>

typedef long long int ll;


using namespace std;

int main()
{
	ll q , k;

	cin >> q >> k;
	
	multiset<ll , greater<ll>> st;

	ll temp;

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
			temp = pow(x , two) + pow(y , two);
		}
		
		

		if(type == 1)
		{
			if(st.size() < k)
				st.insert(temp);
				
			else if(temp <= *(st.begin()))
			{
				auto it = st.begin();
				st.erase(it); //O(1) Amortized
				st.insert(temp);
				
			}	
		}
		else
			cout << *(st.begin()) << "\n";

	}




}