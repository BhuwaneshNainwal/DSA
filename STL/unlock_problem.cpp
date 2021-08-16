#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

int main()
{
	ll n , k;

	cin >> n >> k;

	ll mx = n;
	unordered_map<ll , ll> mp;
	vector<int> vec(n);

	for(ll i = 0 ; i < n ; i++)
	{
		ll num;
		cin >> num;
		vec[i] = num;
		if(num > mx)
			mx = num;
		mp[num] = i; 
	}

	ll cnt = 0;
	ll pos = 0;
	for(ll i = mx ; i >= 1 && cnt < k ; i--)
	{
		if(mp[i] == pos)
		{
			pos++;
			continue;
		}
		else
		{
			ll t = mp[i];
			mp[i] = pos;
			mp[vec[pos]] = t;
			swap(vec[t] , vec[pos]);
			cnt++;
			pos++;
		}

	}

	for(ll i = 0 ; i < n ; i++)
		cout << vec[i] << " ";
}