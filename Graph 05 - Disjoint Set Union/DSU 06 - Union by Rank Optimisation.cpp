
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


class Graph
{
	int V;
	list<pair<int , int>> l;
public:
	Graph(int V)
	{
		this -> V = V;
	}

	void add_edge(int u , int v)
	{
		l.pb(make_pair(u , v));
	}

	int find_set(int i , int parent[])
	{
		if(parent[i] == -1)
			return i;
		return parent[i] = find_set(parent[i] , parent);
	}

	void union_set(int x , int y , int parent[] , int rank[])
	{
		int s1 = find_set(x , parent);
		int s2 = find_set(y , parent);
		
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
	bool contains_cycle()
	{
		int *parent = new int[V];
		int *rank = new int[V]{0};

		for(int i = 0 ; i < V ; i++)
		{
			parent[i] = -1;
			rank[i] = 1;
		}
		
		for(auto edge : l)
		{
			int i = edge.first;
			int j = edge.second;

			int s1 = find_set(i , parent);
			int s2 = find_set(j , parent);

			if(s1 != s2)
				union_set(s1 , s2 , parent , rank);
			else
				return true;
		}

		delete [] parent;
		return false;
	}
};


void solve()
{
	Graph g(4);
	g.add_edge(0 , 1);
	g.add_edge(1 , 2);
	g.add_edge(2 , 3);
	g.add_edge(3 , 0);

	cout << g.contains_cycle();
	

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
