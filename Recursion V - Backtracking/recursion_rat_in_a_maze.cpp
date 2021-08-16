
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


bool ans[1000][1000]= {{0}};

void print_solution(int n , int m)
{
	for(int i = 0 ; i < n ; i++)
	{
		for(int j = 0 ; j < m ; j++)
			cout << ans[i][j] << " ";
		cout << "\n";
	}
}

// bool is_safe(vector<vector<char>> &maze , int i , int j)
// {
// 	int n = maze.size();
// 	int m = maze[0].size();
// 	if(i < n && j < m && maze[i][j] != 'X')
// 		return true;
// 	return false;
// }

// void recursive(vector<vector<char>> &maze , int i , int j , int &cnt )
// {
// 	//base case
// 	if(i == maze.size() - 1 && j == maze[0].size() - 1 && cnt == 0)
// 	{
// 		cnt++;
// 		print_solution(maze.size() , maze[0].size());
// 		return;
// 	}
// 	//checking for forward position
// 	if(is_safe(maze , i , j + 1))
// 	{
// 		ans[i][j + 1] = 1;
// 		recursive(maze ,  i , j + 1 , cnt);
// 		ans[i][j + 1] = 0;
// 	}
// 	if(cnt == 1)
// 		return;
// 	//checking for down position
// 	if(is_safe(maze , i + 1, j))
// 	{
// 		ans[i + 1][j] = 1;
// 		recursive(maze , i + 1 , j , cnt);
// 		ans[i + 1][j] = 0;
// 	}
// 	return;

// }

/*
	Another version
*/
bool rat_in_maze(char maze[10][10] , int soln[][10] , int i , int j ,int m , int n)
{
	if(i == m && j == n)
	{
		soln[m][n] = 1;
		for(int i = 0 ; i <= m ; i++)
		{
			for(int j = 0 ; j <= n ; j++)
				cout << soln[i][j] << " ";
			cout << "\n";
		}
		cout << "\n\n";
		return true;
	}

	//Rat should be inside the grid
	if(i > m || j > n)
		return false;
	if(maze[i][j] == 'X')
		return false;
	//Assume solution exists through the cell
	soln[i][j] = 1;

	bool rightsuccess = rat_in_maze(maze , soln , i , j + 1 , m , n);
	bool leftsuccess = rat_in_maze(maze , soln , i + 1 , j , m , n);
	soln[i][j] = 0;
	if(rightsuccess || leftsuccess)
		return true;
	return false;
}



void solve()
{
	char maze[10][10] = {"OOOO" , "OOXO" , "OOOX" , "OXOO"};
	int soln[10][10] = {0};
	int m = 4 , n = 4;
	bool ans = rat_in_maze(maze , soln , 0 , 0 , m - 1 , n - 1);
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