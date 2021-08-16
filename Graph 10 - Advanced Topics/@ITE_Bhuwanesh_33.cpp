//Bhuwanesh Nainwal

#include<iostream>
using namespace std;

class Complex
{

public:
	int x , y;

	void get_data(int x , int y)
	{
		this -> x = x;
		this -> y = y;
	}

	void print(Complex c)
	{
		cout << c.x << " " << c.y << "\n";
	}
	//Member function
	// Complex operator*(Complex c)
	// {
	// 	Complex temp;
	// 	temp.x = (c.x * x) - (c.y * y);
	// 	temp.y = (c.x * y) + (c.y * x);
	// 	return temp;
	// }

	friend Complex operator*(Complex& , Complex&);

};

//Friend function
Complex operator*(Complex &c1 , Complex &c2)
{
		Complex temp;
		temp.x = (c1.x * c2.x) - (c1.y * c2.y);
		temp.y = (c1.x * c2.y) + (c1.y * c2.x);
		return temp;
}


int main()
{
	int x , y , p , q;

	cin >> x >> y >> p >> q;
	Complex c;
	c.get_data(x , y);
	Complex c1;
	c1.get_data(p , q);
	Complex z = c1 * c;
	z.print(z);
}