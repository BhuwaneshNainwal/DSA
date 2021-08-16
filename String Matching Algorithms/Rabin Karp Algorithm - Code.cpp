
/*
	ॐ
		JAI SHREE RAM

		Hare Krishna Hare Krishna Krishna Krishna Hare Hare
		Hare Rama Hare Rama Rama Rama Hare Hare
	
												ॐ
*/

//Written by Bhuwanesh Nainwal
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
pbds;



#define fast            	ios_base::sync_with_stdio(false) , cin.tie(NULL) , cout.tie(NULL)
#define int					long long int
#define vci              	vector<int>
#define vcvci             	vector<vector<int>>
#define vcpi             	vector<pair<int,int>>
#define vcs					vector<string>
#define pb              	push_back
#define mpii             	map<int , int>
#define mpsi             	map<string , int>
#define mpci             	map<char , int>
#define umpii             	unordered_map<int , int>
#define umpsi             	unordered_map<string , int>
#define umpci             	unordered_map<char , int>
#define all(x)				auto it = x.begin() ; it != x.end() ; it++
#define vcc              	vector<char>
#define vcs              	vector<string>
#define sti            		set<int>
#define stc            		set<char>
#define sts            		set<string>
#define pqmx				priority_queue<int>
#define pqmn				priority_queue<int , vi , greater<int>>
#define null            	NULL
#define ff            		first
#define ss              	second
#define stb(x)				__builtin_popcount(x)
#define lzr(x)				__builtin_clz(x)
#define tzr(x)					__builtin_ctz(x)
#define prc(x , y)          fixed << setprecision(y) << x
#define max3(a, b, c)   	max(a, max(b, c))
#define min3(a, b, c)   	min(a, min(b, c))

using namespace std;

const int mod = 1e9 + 7;
const int INF = 1e9;
const int LINF = 1e18;
const int N = 1e4;
const int p = 1e4;

const int chkprc = 1e-9;  // Check for precision error in double


int powr(int x , int n)
{
	int ans = 1;
	while(n)
	{
		if(n & 1 == 1)
			ans = (ans * x) % mod;
		x = (x * x) % mod;
		n = n >> 1;
	}
	return ans;
}

int inv(int a)
{
	return powr(a , mod - 2);
}


int polyHashString(string s)
{
	int p_powr = 1;
	int hash = 0;
	for(int i = 0 ; i < s.size() ; i++)
	{
		hash += p_powr * (s[i] - 'a' + 1);
		p_powr *= p;
		p_powr %= mod;
		hash %= mod;
	}

	return hash;
}

void solve()
{
	string text = "abcdegh" , pat = "degh";
	int pat_hash = polyHashString(pat);

		
	int n = text.length() , m = pat.length();

	int text_hash = polyHashString(text.substr(0 , m));
		
	if(text_hash == pat_hash)
	{
		cout << "0" << "\n";
		return;
	}

	for(int i = 1 ; i + m <= n ; i++)
	{
		int new_hash = text_hash;

		//Ist step
		new_hash = (new_hash - (text[i - 1] - 'a' + 1) +  mod) % mod;
		
		//Second step
		new_hash *= inv(p);
		new_hash %= mod;

		//Third step
		new_hash = new_hash + (text[i + m - 1] - 'a' + 1) * powr(p , m - 1);
		new_hash %= mod;
		
		if(new_hash == pat_hash)
		{
			cout << i;
		}

		text_hash = new_hash;
	}

}

void local()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

int32_t main()
{

    fast;
    local();
    int T = 1;
    // cin>>T;

    while(T--)
    {
        solve();
    }

    return 0;
}