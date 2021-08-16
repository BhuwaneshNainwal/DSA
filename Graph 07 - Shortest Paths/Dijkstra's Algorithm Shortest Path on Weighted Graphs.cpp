
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

	Dijkastra's algorithm is a SSSP used with directed / undirected weighted graphs having positive
	weight cycle only
	It is a greedy algorithm
	TC - O(E log V)

*/

template<typename T>
class Graph
{
	unordered_map<T , list<pair<T , int>>> m;

public:

	void add_edge(T u , T  v , int dist , bool bidir = false)
	{
		m[u].pb({v , dist});
		if(bidir)
			m[v].pb({u , dist});
	}

	void print_ad()
	{
		for(auto j : m)
		{
			cout << j.first <<" -> ";

			for(auto l : j.second)
				cout << "( " << l.first << " , " << l.second << ')' << "\n";
		}

	}

	void dijkastra(T src)
	{

		unordered_map<T , int> dist;
		for(auto j : m)
		{
			dist[j.first] = INT_MAX;
			for(auto k : m[j.first])
				dist[k.first] = INT_MAX;
		}
		
		set<pair<int , T>> s;

		dist[src] = 0;
		s.insert({0 , src});

		while(!s.empty())
		{
			auto p = *(s.begin());
			T node = p.second;

			int node_dist = p.first;
			s.erase(s.begin());

			for(auto childpair : m[node])
			{
				if((node_dist + childpair.second) < dist[childpair.first])
				{
					T dest = childpair.first;
					auto f = s.find({dist[dest] , dest});
					
					if(f != s.end())
						s.erase(f);

					dist[dest] = node_dist + childpair.second;
					s.insert({dist[dest] , dest});
				}
			}
		}

		for(auto d : dist)
			cout << d.first << " is located at a distance of " << d.second << "\n";

	}
};


void solve()
{

	Graph<int> g;

	g.add_edge(1 , 2 , 2);
	g.add_edge(1 , 3 , 4);
	g.add_edge(3 , 2 , -3);
	g.dijkastra(1);

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
