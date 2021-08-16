#include <ext/pd_ds/assoc_container.hpp>
#include <ext/pd_ds/tree_policy.hpp>
//Including_tree_order_statistics_node_update

using namespace __gnu_pads;
using namespace std;

//Declaration of tree based container

template <
	//Key type
	typename key;

	//Mapped policy
	typename Mapped;

	//Key comparison functor
	typename Cmp_Fn = std::less<key>,

	//Specifies which underlying data structure to use
	typename Tag = rb_tree_tag;

	typename<
		typename Const_Node_Iterator,
		typename Node_Iterator,
		typename Cmp_Fn_,
		typename Allocator_ >

		//A policy for updating node invariants
		class Node_Update = null_node_update,

		//An allocator type
		typename Allocator = std::allocator<char> >

class tree;

typedef tree<int , null_type , less<int> , rb_tree_tag , tree_order_statistics_node_update> 
new_data_set;

/*

Tree structure

rb_tree_tag  		(red - black tree)
splay_tree_tag  	(splay - tree)
ov_tree_tag 		(ordered - vector tree)

*/

/* Why PBDS ?

1> They are like a set but with some extra functionality . For ex, we can use index concept 
in associative containers like vectors

2> They are quite flexible

Functionalities :

1> find_by_order(k) - return the iterator to the kth smallest element => O(Log n) (value at index k in  case of set)

2> order_by_key(val) - return the numbers of elements strictly less than val in container 
 => O(Log n)  (Indirectly returning index of element val in case of set)

for ex, 2 4 5 7

order_by_key(7) = 3
order_by_key(6) = 2

*/



int main()
{

}