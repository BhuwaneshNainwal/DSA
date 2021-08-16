
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


template<typename T>
class Graph
{
	unordered_map<T , list<T>> l;

public:
	void add_edge(T x , T y)
	{
		l[x].pb(y);
		// l[y].pb(x);
	}

	void dfs_helper(T src , unordered_map<T , bool> &visited)
	{
		// cout << src << " ";
		visited[src] = true;
		for(T nbr : l[src])
		{
			if(!visited[nbr])
				dfs_helper(nbr , visited);
		}
		cout << " " << src;
	}
	
	void dfs(vcc &a , vcc &b , int &cnt)
	{
		unordered_map<T , bool> visited;
		for(auto p : l)
		{
			T node = p.first;
			visited[node] = false;
		}
		cout << "Case #" << cnt << ": Vivek should drink beverages in this order:";
		for(int i = 0 ; i < b.size() ; i++)
		{
			if(visited[b[i]] != 1)
				dfs_helper(b[i] , visited);
		}
		for(int i = 0 ; i < a.size() ; i++)
		{
			if(visited[a[i]] != 1)
				dfs_helper(a[i] , visited);	
		}
		cout << '.';
	}
};

void solve(int n , int &cnt)
{
	
	// int n;
	// cin >> n;
	vcc a(n);
	for(int i = 0 ; i < n ; i++)
	{
		cin >> a[i]; 
	}

	int m;
	cin >> m;
		
	Graph<char> g;
	vcc b;
	for(int i = 0 ; i < m ; i++)
	{
		char u , v;
		cin >> u >> v;
		g.add_edge(v , u);
		b.pb(v);
	}

	g.dfs(a , b , cnt);
	cout << "\n\n";
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
    int T;
    int cnt = 1;
    while(cin >> T)
    {
        solve(T , cnt);
        cnt++;
    }

    return 0;
}