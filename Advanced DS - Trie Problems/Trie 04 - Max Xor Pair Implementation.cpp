
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


class Node
{
	public:
		int data;
		Node *left;
		Node *right;
};

class Trie
{
	Node *root;
	public:
		Trie()
		{
			root = new Node();
		}

		//Insert function
		//5 - 000000101 => 32 bit integer

		void insert(int n)
		{

			Node *temp = root;
			for(int i = 31 ; i >= 0 ; i--)
			{
				int bit = (n >> i) & 1;
				if(bit == 0)
				{
					if(temp -> left == NULL)
						temp -> left = new Node(); 
					temp = temp -> left;
				}
				else
				{
					if(temp -> right == NULL)
						temp -> right = new Node();

					temp = temp -> right;
				}
			}
		}

	int max_xor_helper(int value)
	{
		Node *temp = root;
		int current_ans = 0;
		for(int j = 31 ; j >= 0 ; j--)
		{
			int bit = (value >> j) & 1;

			if(bit == 0)
			{
				if(temp -> right != NULL)
				{
					temp = temp -> right;
					current_ans += (1 << j);
				}
				else
					temp = temp -> left;
			}
			else
			{
				if(temp -> left != NULL)
				{
					temp = temp -> left;
					current_ans += (1 << j);
				}
				else
                	temp = temp -> right;

			}
		}
		return current_ans;
	}

	int max_xor(int *input , int n)
	{
		int max_xor = 0;

		for(int i = 0 ; i < n ; i++)
		{
			int val = input[i];
			insert(val);
			int current_xor = max_xor_helper(val);
			// cout << current_xor << " ";
			max_xor = max(current_xor , max_xor);
		}

		return max_xor;
	}

};


void solve()
{
	int input[] = {3 , 10 , 5 , 25 , 2 , 8};
	Trie t;
	cout << t.max_xor(input , 6);

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