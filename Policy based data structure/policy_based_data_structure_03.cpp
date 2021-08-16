#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef tree<pair<int , int> , null_type , less<pair<int , int>> , rb_tree_tag , tree_order_statistics_node_update> 
PBDS;

int main()
{
	PBDS st;

	int n;
	cin >> n;

	// PBDS st;

	for(int i = 0 ; i < 2 * n ; i++)
	{
		int num;
		cin >> num;
		st.insert({num , i});
	}
	int ans  = 0;
	int cnt = 0;
	int target = 2 * n;
	for(auto it = st.begin() ; it != st.end() ; it++)
	{
		cnt++;
		if(cnt == target / 2)
		{
			ans = it -> first;
			break;
		}
	}
	cout << ans;

}