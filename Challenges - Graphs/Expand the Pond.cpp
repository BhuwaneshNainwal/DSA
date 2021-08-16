
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


int dx[] = {-1 , 0 , 1 , 0};
int dy[] = {0 , -1 , 0 , 1};
bool mat[1003][1003];
int n , m;
bool vis[1002][1002];
int g = 0;
int id[1004][1004];
int store[1000002] = {0};

void bfs(int k , int l)
{
	g++;
	queue<pair<int , int>> q;
	q.push({k , l});
	
	while(!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		vis[x][y] = -1;
		id[x][y] = g; 		
		store[g]++;

        for (int d = 0; d < 4; d ++) 
        {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if(nx < 0 || nx > n || ny < 0 || ny > m)
            	continue;
            if (!vis[nx][ny] and mat[nx][ny]) 
            {
                vis[nx][ny] = true;
                q.push({nx, ny});
         	}
        }
	}
}



void solve()
{
	cin >> n >> m;

	for(int i = 0 ; i < n ; i++)
	{
		for(int j = 0 ; j < m ; j++)
			cin >> mat[i][j];
	}	
		
	// unordered_map<int , unordered_map<int , int>> vis;

	for(int i = 0 ; i < n ; i++)
	{
		for(int j = 0 ; j < m ; j++)
		{
			if(mat[i][j] && !vis[i][j])
			{				
				bfs(i , j);
			}
			
		}
	}

	int ans = 1;

	for(int i = 0 ; i < n ; i++)
	{
		for(int j = 0 ; j < m ; j++)
		{
			if(mat[i][j])
				continue;
			
			set<int> groups;
			for(int d = 0 ; d < 4 ; d++)
			{
				int nx = i + dx[d];
				int ny = j + dy[d];
				if(nx < 0 || nx >= n || ny < 0 || ny >= m)
					continue;

				groups.insert(id[nx][ny]);
			}

			// sort(groups.begin() , groups.end());
			// groups.resize(unique(groups.begin() , groups.end()) - groups.begin());
			int temp = 0;

			for(auto val : groups)
			{
				temp += store[val];
			}
			ans = max(ans , temp + 1);
		}
	}

	cout << ans ;

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