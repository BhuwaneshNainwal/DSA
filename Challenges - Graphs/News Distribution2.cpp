
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
const int N = 1e6 ;
const int chkprc = 1e-9;  // Check for precision error in double


class Graph
{

public:
	list<pair<int , int>> l;

	void add_edge(int u , int v)
	{
		l.push_back({u , v});
	}

	int find_representative(int i , int parent[])
	{
		if(parent[i] == -1)
			return i;
		return parent[i] = find_representative(parent[i] , parent);
	}

	void union_set(int u , int v , int *parent , int *rank)
	{
		

		int r1 = find_representative(u , parent);
		int r2 = find_representative(v , parent);
		
		if(r1 != r2)
		{

			if(rank[r1] < rank[r2])
			{
				parent[r1] = r2;
				rank[r2] += rank[r1];
			}
			else
			{
			
				parent[r2] = r1;
				rank[r1] += rank[r2];
			}

		}
	}
	void find_answer(int n)
	{
		int parent[n];
		int *rank = new int[n]{0};

		for(int i = 0 ; i < n ; i++)
			rank[i] = 1;
		memset(parent , -1 , sizeof(parent));

		for(auto edge : l)
		{
			int u = edge.first;
			int v = edge.second;
			if(u != v)
				union_set(u , v , parent , rank);
		}

		for(int i = 0 ; i < n ; i++)
		{
			cout << rank[find_representative(i , parent)] << " ";
		}
	}
};

void solve()
{
	int n , m;
	cin >> n >> m;
	Graph g;

	for(int i = 0 ; i < m ; i++)
	{
		int k;
		cin >> k;
		if(k == 0)
			continue;
		int root;
		cin >> root;
		root--;
		for(int j = 1 ; j < k ; j++)
		{
			int node;
			cin >> node;
			node--;
			g.add_edge(root , node);
		}
	}
	g.find_answer(n);
	
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