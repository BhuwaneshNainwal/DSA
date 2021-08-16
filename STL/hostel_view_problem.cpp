#include <bits/stdc++.h>

typedef long long int ll;

ll binpow(ll a , ll n)
{
 
 ll res = 1;
	
	while(n)
	{
		if(n % 2 != 0)
			res = res * a;

		a = a * a;
		n = n / 2; 
	}
	return res;
}

using namespace std;

int main()
{
	ll q , k;

	cin >> q >> k;
	
	multiset<ll , greater<ll>> st;

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
			val = pow(x , two) + pow(y , two);
		}
		
		

		if(type == 1)
		{
			if(st.size() < k)
				st.insert(val);
				
			else if(val <= *(st.begin()))
			{
				auto it = st.begin();
				st.erase(it); //O(1) Amortized
				st.insert(val);
				
			}	
		}
		else
			cout << *(st.begin()) << "\n";

	}
}