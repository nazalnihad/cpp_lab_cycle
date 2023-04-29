#include <iostream>
#include <cmath>
class vector
{
	float x, y, z;
	long double magnitude;

public:
	vector() {}
	void getvalues();
	int getmagnitude();
	void display();
	void operator==(const vector &);
	void operator!=(const vector &);
	void operator<(const vector &);
	void operator<=(const vector &);
	void operator>=(const vector &);
};
void vector::getvalues()
{
	std::cout << "\nEnter the vector values \n";
	std::cout << "x = ";
	std::cin >> x;
	std::cout << "y = ";
	std::cin >> y;
	std::cout << "z = ";
	std::cin >> z;
}
int vector::getmagnitude()
{
	std::cout << "\nThe magnitude of your vector is \n";
	magnitude = (x * x) + (y * y) + (z * z);
	magnitude = sqrt(magnitude);
	std::cout << magnitude << "\n";
	return magnitude;
}
void vector::display()
{
	if (y < 0 and z < 0)
	{
		std::cout << x << "i " << y << "j " << z << "k\n";
	}
	else if (y < 0 and z > 0)
	{
		std::cout << x << "i " << y << "j + " << z << "k\n";
	}
	else if (y > 0 and z < 0)
	{
		std::cout << x << "i + " << y << "j " << z << "k\n";
	}
	else
	{
		std::cout << x << "i + " << y << "j + " << z << "k \n";
	}
}
void vector::operator==(const vector &a)
{
	if (magnitude == a.magnitude)
	{
		std::cout << "\nBoth vectors have equal magnitude \n";
	}
	else
	{
		std::cout << "\nThe vectors are not equal \n";
	}
}
void vector::operator!=(const vector &a)
{
	if (magnitude != a.magnitude)
	{
		std::cout << "\nThe vector are unequal in magnitude \n";
	}
	else
	{
		std::cout << "\nThe vectors have equal magnitude \n";
	}
}
void vector::operator<(const vector &a)
{
	if (magnitude < a.magnitude)
	{
		std::cout << "\nThe vector 2 is greater than vector 1 \n";
	}
	else
	{
		std::cout << "\nThe vector 2 is less than vector 1 \n";
	}
}
void vector::operator<=(const vector &a)
{
	if (magnitude <= a.magnitude)
	{
		std::cout << "\nthe vector 1 is less than or equal to vector 2\n";
	}
	else
	{
		std::cout << "\nthe vector 1 is greater than the vector 2\n";
	}
}
void vector::operator>=(const vector &a)
{
	if (magnitude >= a.magnitude)
	{
		std::cout << "\nthe vector 1 is greater than or equal to vector 2\n";
	}
	else
	{
		std::cout << "\nthe vector 1 is less than vector 2 \n";
	}
}
int main()
{
	vector a, b;
	a.getvalues();
	a.getmagnitude();
	b.getvalues();
	b.getmagnitude();
	std::cout << "\nThe entered vectors are \n";
	a.display();
	b.display();
	int choice;
	std::cout << "\n=== vectors with operator overloading ===\n";
	do
	{
		std::cout << "\n1 - to check a == b \n";
		std::cout << "2 - to check a < b \n";
		std::cout << "3 - to check a >= b \n";
		std::cout << "4 - to check a <= b \n";
		std::cout << "5 - to check a != b \n";
		std::cout << "6 - to quit \n";
		std::cin >> choice;
		switch (choice)
		{
		case 1:
			a == b;
			break;
		case 2:
			a < b;
			break;
		case 3:
			a >= b;
			break;
		case 4:
			a <= b;
			break;
		case 5:
			a != b;
			break;
		case 6:
			std::cout << "\nExiting...";
			return 0;
		default:
			std::cout << "pls enter a valid value \n";
			break;
		}
	} while (choice != 6);

	return 0;
}
