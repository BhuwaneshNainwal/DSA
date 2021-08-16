#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef tree<pair<int , int> , null_type , less<pair<int , int>> , rb_tree_tag , tree_order_statistics_node_update> 
PBDS;
typedef long long int ll;

int main()
{
	PBDS st;

	ll n;
	cin >> n;

	ll a[n] , b[n] , c[n];

	for(ll i = 0 ; i < n ; i++)
		cin >> a[i];
	for(ll i = 0 ; i < n ; i++)
		cin >> b[i];

	for(ll i = 0 ; i < n ; i++)
		c[i] = (a[i] - b[i]);

	ll ans = 0;
	for(ll i = 0 ; i < n ; i++)
	{
		ans += st.size() - st.order_of_key({-c[i] , 1e10});
		st.insert({c[i] , i});
	}
	cout << ans ;

	return 0;
}