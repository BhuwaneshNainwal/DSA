
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



bool bfs(int **residualCapacity , int source , int sink , int n , int *parent)
{
	bool visited[n];
	memset(visited , 0, sizeof(visited));
	queue<int> que;
	visited[source] = true;
	que.push(source);
	bool foundAugmentedPath = false;
	while(!que.empty())
	{
		int u = que.front();
		que.pop();
		for(int v = 0 ; v < n ; v++)
		{
			if(visited[v] == false && residualCapacity[u][v] > 0)
			{
				parent[v] = u;
				visited[v] = true;
				que.push(v);
				if(v == sink)
				{
					foundAugmentedPath = true;
					break;
				}
			}
		}
	}

	return foundAugmentedPath;
}

void printAugmentedPath(vector<vector<int>> augmentedPaths)
{
	for(int i = 0 ; i < augmentedPaths.size() ; i++)
	{
		for(int j = 0 ; j < augmentedPaths[i].size() ; j++)
			cout << augmentedPaths[i][j] << ", ";
	}
	cout << '\n';
}

int maxFlow(int **capacity , int source , int sink , int v)
{
	int **residualCapacity = new int*[v];
	for(int i = 0 ; i < v ; i++)
		residualCapacity[i] = new int[v];

	for(int i = 0 ; i < v ; i++)
	{
		for(int j = 0 ; j < v ; j++)
			residualCapacity[i][j] = capacity[i][j];
	}

	int *parent = new int[1000];  
	vector<vector<int>> augmentedPaths;
	int maxFlow = 0;
	while(bfs(residualCapacity , source , sink , v , parent))
	{
		vector<int> currentAugmentedPath;
		int flow = INT_MAX;
		int v = sink;
		while(v != source)
		{
			currentAugmentedPath.pb(v);
			int u = parent[v];
			if(flow > residualCapacity[u][v])
			{
				flow = residualCapacity[u][v];
			}
			v = u;
		}

		currentAugmentedPath.pb(source);
		reverse(currentAugmentedPath.begin() , currentAugmentedPath.end());
		augmentedPaths.pb(currentAugmentedPath);
		maxFlow += flow;
	
		v = sink;
		while(v != source)
		{
			int u = parent[v];
			residualCapacity[u][v] -= flow;
			residualCapacity[v][u] += flow;

		}
	}

	return maxFlow;
}

void solve()
{
	
	int v , e;
	cin >> v >> e;
	int **capacity = new int*[v];
	for(int i = 0 ; i < v ; i++)
	{
		capacity[i] = new int[v];
	}

	for(int i = 0 ; i < e ; i++)
	{
		int u , v , c;
		cin >> u >> v >> c;
		capacity[u][v] = c;
	}

	cout << maxFlow(capacity , 0 , 1 , v);
	
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