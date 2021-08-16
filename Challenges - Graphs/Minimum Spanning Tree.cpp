
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

class DSU
{
	int *parent;
	int *rank;

public:
	DSU(int n)
	{
		parent = new int[n];
		rank = new int[n];
		for(int i = 0 ; i < n ; i++)
		{
			parent[i] = -1;
			rank[i] = 1;
		}
	}

	int find(int i)
	{
		if(parent[i] == -1)
			return i;
		return parent[i] = find(parent[i]);
	}

	void unite(int x , int y)
	{
		int s1 = find(x);
		int s2 = find(y);

		if(s1 != s2)
		{
			if(rank[s1] < rank[s2])
			{
				parent[s1] = s2;
				rank[s2] += rank[s1]; 
			}
			else
			{
				parent[s2] = s1;
				rank[s1] += rank[s2];
			}

		}
	}

};

class Graph
{
	vector<vector<int>> edgelist;
	int V;

public:
	Graph(int V)
	{
		this -> V = V;
	}

	void add_edge(int x , int y , int w)
	{
		edgelist.pb({w , x , y});
	}

	int Kruskal_mst()
	{
		sort(edgelist.begin() , edgelist.end());

		DSU s(V);


		int ans = 0;
		for(auto edge : edgelist)
		{
			int w = edge[0];
			int x = edge[1];
			int y = edge[2];
			if(s.find(x) != s.find(y))
			{
				s.unite(x , y);
				ans += w;
			}
		}

		return ans;
	}

};

void solve()
{
	int v , e;
	cin >> v >> e;
	Graph g(v);
	for(int i = 0 ; i < e ; i++)
	{
		int u , v , w;
		cin >> u >> v >> w;
		g.add_edge(u , v , w);
	}
	cout << g.Kruskal_mst();
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