Coupon collector problem:

Uncle chips always distributes a coupon in packet of chips , the packet choosen for each packet is choosen
randomly from n distinct coupons. What is the expected number of coupons one must buy so that we get all n distinct
coupons.

Let xi be number of coupons to get ith new coupon
p(xi) = (n - (n - i)) / n 
E(xi) = 1/p = n/n - i + 1
E(x) = E(x1 + x2 + x3 + x4 + .... + xn) = E(x1) + E(x2) + .... + E(xn)
E(x) = n * (1 + 1/2 + 1/3 + 1/4 + .... + 1/n)