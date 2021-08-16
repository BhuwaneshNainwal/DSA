
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
const int chkprc = 1e-9;  // Check for precision error in double


//Eulerian cycle
int dfs(int cur , vector<bool> &vis , vci *gr)
{
	vis[cur] = true;
	int ans = gr[cur].size() % 2;
	for(auto nbr : gr[cur])
	{
		if(!vis[nbr])
			ans += dfs(nbr , vis , gr);
	}

	return ans;
}


void solve()
{
	
	int n;
	cin >> n;
	set<pair<int , int>> st;
	vector<pair<int , int>> vc;
	for(int i = 0 ; i < n ; i++)
	{
		int x1 , y1 , x2 , y2;
		cin >> x1 >> y1 >> x2 >> y2;
		st.insert({x1 , y1});
		st.insert({x2 , y2});
		vc.pb({x1 , y1});
		vc.pb({x2 , y2});
	}

	map<pair<int , int> , int> mp;
	int cnt = 0;
	for(auto ele : st)
	{
		mp[ele] = cnt++;
	}

	vci gr[st.size()];
	for(int i = 0 ; i < vc.size() - 1 ; i += 2)
	{
		gr[mp[vc[i]]].pb(mp[vc[i + 1]]);
		gr[mp[vc[i + 1]]].pb(mp[vc[i]]);
	}	

	vector<bool> vis(st.size());
	for(int i = 0 ; i < st.size() ; i++)
		vis[i] = false;

	int final = 0;
	cnt = 0;
	for(int i = 0 ; i < st.size() ; i++)
	{
		if(!vis[i])
		{
			cnt++;
			final += max(dfs(i , vis , gr) , (int)2);
		}
	}
	cout << max(cnt - 1 , (final - 1) / 2);

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