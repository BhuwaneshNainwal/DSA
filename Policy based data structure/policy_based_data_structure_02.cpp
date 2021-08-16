#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef tree<int , null_type , less<int> , rb_tree_tag , tree_order_statistics_node_update> 
PBDS;

int main()
{
	PBDS st;
	st.insert(1);
	st.insert(2);
	st.insert(3);
	st.insert(6);
	st.insert(14);
	st.insert(8);	

	for(int i = 0 ; i < 6 ; i++)
		cout << i << " => " << *st.find_by_order(i) << "\n";
	cout << "\n";

	cout << st.order_of_key(7) << "\n\n";
	cout << st.order_of_key(3) << "\n\n";

	// If we want to make multiple elements we can replace int in typedef by pair<int , int> 
}