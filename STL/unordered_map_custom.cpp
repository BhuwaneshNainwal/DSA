#include <iostream>
#include <string>
#include <cstring>
#include <unordered_map>

#define nl << "\n"
using namespace std;
	
class Student
{
	public:
	string firstname;
	string lastname;
	string rollno;

	//Parameterized constructor
	Student(string f , string l , string roll)
	{
		firstname = f;
		lastname = l;
		rollno = roll;
	}

	bool operator==(const Student &s) const
	{
		return rollno == s.rollno;
	}


};

class HashFn
{
	public:
	size_t operator()(const Student &s) const
	{
		return s.firstname.length() + s.lastname.length();
	}
};

int main()
{
	unordered_map<Student , int , HashFn> m;
	Student s1("Bhuwanesh" , "Nainwal" , "32");
	Student s2("Bhuwanesh" , "Nainwal" , "34");
	Student s3("Avdhesh" , "Kumar" , "41");

	m[s1] = 100;
	m[s2] = 90;
	m[s3] = 95;

	for(auto p : m)
		cout << p.first.firstname << " => " << p.first.rollno << " => " << p.second nl;
	

}