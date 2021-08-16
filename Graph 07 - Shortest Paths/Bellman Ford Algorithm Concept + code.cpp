
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


/*

	Bellman Ford is a SSSP algorithm used with directed graphs with negative weights also.
	It is DP based algoritm
	
	TC - O(V * E)
	
	Steps :

	1> Init dist[vertices] = INT_MAX , dist[src] = 0
	2> Relax all edges V - 1 times [Most important]
	3> Negative weight cycle detection
*/

vector<int> bellman_ford(int v , int src , vector<vector<int>> edges)
{
	vector<int> dist(v + 1 , INT_MAX);
	dist[src] = 0;

	//relax all the edges v - 1 times
	for(int i = 0 ; i < v - 1 ; i++)
	{
			for(auto edge : edges)
			{
				int u = edge[0];
				int v = edge[1];
				int wt = edge[2];

				if(dist[u] != INT_MAX && dist[u] + wt < dist[v])
					dist[v] = dist[u] + wt;

			}
	}

	//negative weight cycle
	for(auto edge : edges)
	{
		int u = edge[0];
		int v = edge[1];
		int wt = edge[2];
		if(dist[u] != INT_MAX && dist[u] + wt < dist[v])
		{
			cout << "Negative weight cycle found";
			exit(0);
		}

	}
	return dist;
}

void solve()
{

	int n , m;
	cin >> n >> m;

	vector<vector<int>> edges;

	for(int i = 0 ; i < m ; i++)
	{
		int u , v , wt;
		cin >> u >> v >> wt;
		edges.pb({u , v , wt});
	}
	
	vector<int> distances = bellman_ford(n , 1 , edges);

	for(int i = 1 ; i <= n ; i++)
	{
		cout << "Node " << i << " is at the distance " << distances[i] << "\n";
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