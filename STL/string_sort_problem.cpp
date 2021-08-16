#include<bits/stdc++.h>

typedef long long int ll;
using namespace std;

bool compare(string &a , string &b)
{
	if(a.length() <= b.length() && (b.substr(0 , a.size()) == a))
		return false;
	else if(a.length() >= b.length() && (a.substr(0 , b.size()) == b))
		return true;
	return a < b;
}

int main() 
{
	ll n ;
	cin >> n;

	string str[n];

	for(ll i = 0 ; i < n ; i++)
	{
		cin >> str[i];
	}

	sort(str , str + n , compare);

	for(ll i = 0 ; i < n ; i++)
		cout << str[i] << "\n";
	return 0;
}