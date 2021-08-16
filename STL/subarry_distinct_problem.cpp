#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
const ll M = 1e9 + 7;

int main()
{

	ll n ;
	cin >> n;

	vector<ll> arr(n);

	for(ll i = 0 ; i < n ; i++)
		cin >> arr[i];
	
	ll i = 0 , j = 0;
	ll ans = 0;
	set<ll> st;

	for(ll i = 0 ; i < n ; i++)
	{
		while(j < n && st.count(arr[j]) == 0)
		{
			st.insert(arr[j]);
			j++;
		}
		st.erase(st.find(arr[i]));
		ll temp = ( (j - i) * (j - i + 1)  / 2 ) % M;
		ans = (ans + temp) % M;

	}
	cout<<ans;

}