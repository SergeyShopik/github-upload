#include"Array.h"
#include"string"

void equation1(double a, double b, double c)
{
	double dis = b * b - 4 * a * c;
	//без спецификации исключения
	if (dis < 0) throw std::string("Error");

	double x1 = (-b + sqrt(dis)) / 2 * a;
	double x2 = (-b - sqrt(dis)) / 2 * a;

	if (dis == 0) throw std::string("x1 = x2");

	std::cout << "X1 " << x1 << ", X2 " << x2 << std::endl;
}
void equation2(double a, double b, double c)
{
	double dis = b * b - 4 * a * c;
	//без спецификации исключения
	if (dis < 0) throw int();

	double x1 = (-b + sqrt(dis)) / 2 * a;
	double x2 = (-b - sqrt(dis)) / 2 * a;

	std::cout << "X1 " << x1 << ", X2 " << x2 << std::endl;
}

int main()
{
	double a = 1, b = 2, c = 1;
	try
	{
		equation1(a, b, c);
	}
	catch (std::string s)
	{
		std::cout << s;
	}

	/*Array a(5), b(20), c = a;

	try 
	{
		for (size_t i = 0; i < a.getSize(); i++)
		{
			a.set(i, 666);
			std::cout << a[i + 1];
		}
	}
	catch (Array::ErrorIndex& ex)
	{
		std::cout << "Wrong index.\n" << ex.ind << std::endl;
		std::cout << ex.what() << std::endl;
	}
	
	catch (NoSix n)
	{
		std::cout << n.what();
	}
	catch (std::exception& e)
	{
		std::cout << e.what();
	}
	catch (...)
	{
		std::cout << "Any exception.\n";
	}

	std::cin >> a;
	std::cout << std::endl;
	std::cout << a;
	b = a;
	std::cout << std::endl;
	std::cout << b;*/

	return 0;
}