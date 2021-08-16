#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

int main()
{
	string str1;
	string str2;
	getline(cin , str1);
	getline(cin , str2);

	ll n2 = str2.length();
	ll n1 = str1.length();

	ll i = 0 , j = 0;
	unordered_map<char , ll> mp;
	unordered_map<char , ll> fre;

	ll res1 = 0 , res2 = n1 + 2;
	for(auto c : str2)
		mp[c]++;
	
	ll l = 0;
	ll r = 0;

	for(r ; r < n1 ; r++)
	{
		fre[str1[r]]++;

		bool good = true;
		for(auto p : mp)
		{
			if(fre[p.first] < p.second)
			{
				good = false;
				break;				
			}
		}
		if(!good)
			continue;


		while(l < n1 && l <= r && (fre[str1[l]] == 0|| fre[str1[l]] > mp[str1[l]]))
		{
			
			fre[str1[l]]--;
			l++;
		}
		// cout << l << " " << r << '\n';

		if(r - l + 1 < res2 - res1 + 1)
		{
			res1 = l;
			res2 = r;
		}
	}
	
	if(res1 == 0 && res2 == n1 + 2)
		cout << "No String"<<'\n';
	else
		cout << str1.substr(res1, res2 - res1 + 1)<<'\n'; 
}