
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

deque<int> final;
unordered_set<int> ans; 	


map<int , set<int>> l;

template<typename T>
 class Graph
 {
 	map<T , T> deg;
 public:
 	void add_edge(T x , T y)
 	{
 		l[x].insert(y);
 		// l[y].pb(x);
 	}
 
	 
 	void bfs(unordered_map<int,string> &rev)
 	{

 		unordered_map<T , bool> visited;
 		queue<T> q;
 		for(auto p : l)
 		{
 			int node = p.first;
 			deg[node] = 0;
 		}
 		
 		for(auto p : l)
 		{
 			for(auto node : p.second)
 			{
 				deg[node]++;
 			}
 		
 		}
 		for(auto x : deg)
 		{
 			if(x.second == 0)
 			{	
 				// cout << rev[x.first] << "  ";
 				int node = x.first;
 				q.push(node);
 				cout << rev[node] << " ";
 				ans.insert(node);
 				visited[node] = true;
 			}
 		}
 		
 		while(!q.empty())
 		{
 			T node = q.front();

 			q.pop();
 
 			for(T nbr : l[node])
 			{

 				if(!visited[nbr])
 				{
 					deg[nbr]--;
 					if(deg[nbr] == 0)
 					{
 						q.push(nbr);
 						visited[nbr] = true;
 						ans.insert(nbr);
 						final.pb(nbr);
 					}
 				}
 			}
 		}

 	}
 }; 

void solve(int n , int cnt)
{

	umpsi fre;
	unordered_map<int,string>  rev; 
	vector<string> str;
	for(int i = 0 ; i < n ; i++)
	{
		string s;
		cin >> s;
		str.pb(s);
		fre[s] = i;
		rev[i] = s;
	}
	
	Graph<int> g;
	int m;
	cin >> m;
	for(int i = 0 ; i < m ; i++)
	{
		string a , b;
		cin >> a >> b;
		g.add_edge(fre[a] ,fre[b]);
	}	
	
	for(auto val : l)
	{
		cout << rev[val.first] << " => ";
		for(auto x : val.second)
			cout << rev[x] << " ";
		cout << "\n";
	}
	cout << "\n\n";

	cout<< "Case #" << cnt << ": Vivek should drink beverages in this order: "; 

	g.bfs(rev);

	

	for(int i = n - 1 ; i >= 0 ; i--)
	{
		if(ans.find(fre[str[i]]) == ans.end())
			final.push_front(fre[str[i]]);
	}
	for(int i = 0 ; i < final.size() - 1; i++)
		cout << rev[final[i]] << " ";
	cout << rev[final[final.size() - 1]] << "." << "\n\n";
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

    int cnt = 1;
    while(cin >> T)
    {
        solve(T , cnt);
        cnt++;
    }

    return 0;
}