
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
	The polygon containing a set of points

*/



struct point
{
	int x , y;

	bool operator < (point &p)
	{
		if(p.x == x)
			return y < p.y;
		return x < p.x; 
	}

	bool operator == (point & p)
	{
		return (x == p.x && y == p.y);
	}
};

bool clockwise(point a , point b , point c)
{
	return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) > 0;
}


bool counter_clockwise(point a , point b , point c)
{
	return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) < 0;
}	

bool collinear(point a , point b , point c)
{
	return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) == 0;
}

void convex_hull(vector<point> &p)
{
	if(p.size() <= 2)
		return;

	sort(p.begin() , p.end());


	int i , n = p.size();

	//Now p[0] is p1 and p[n - 1] is p2
	point p1 = p[0] , p2 = p[n - 1];
	
	vector<point> up , down;
	up.pb(p1);
	down.pb(p1);



	for(int i = 1 ; i < n ; i++)
	{
		//Upper half
		if(i == n - 1 || !counter_clockwise(p1 , p[i] , p2))
		{
			//Checking fo those points which lies inside Rubberband
			while(up.size() >= 2 && counter_clockwise(up[up.size() - 2] , up[up.size() - 1] , p[i]))
			{
				up.pop_back();
			}

			up.pb(p[i]);

		}

		//Lower half
		if(i == n - 1 || !clockwise(p1 , p[i] , p2))
		{
			//Checking fo those points which lies inside Rubberband
			while(down.size() >= 2 && clockwise(down[down.size() - 2] , down[down.size() - 1] , p[i]))
			{
				down.pop_back();
			}

			down.pb(p[i]);		
		}
	}

	p.clear();

	for(int i = 0 ; i < up.size() ; i++)
		p.pb(up[i]);

	for(int i = 0 ; i < down.size() ; i++)
		p.pb(down[i]);

	//P contains all the points from up as well as down
	sort(p.begin() , p.end());
	p.resize(unique(p.begin() , p.end()) - p.begin());
}

void solve()
{
	
	int n;
	cin >> n;

	vector<point> p(n);

	for(int i = 0 ; i < n ; i++)
	{
		cin >> p[i].x >> p[i].y;
	}
	convex_hull(p);

	for(auto val : p)
		cout << val.x << " " << val.y << "\n";
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