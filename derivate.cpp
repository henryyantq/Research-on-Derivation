#include <iostream>
#include <cmath>
using namespace std;

double fact(double i)
{
	if (i == 0)
		return 1;
	double result = 1;
	for (double k = i; k > 0; k--)
		result *= k;
	return result;
}

double comb(double n, double i)
{
	if (i == 0 || i == n)
		return 1;
	if (i == 1 || i == n - 1)
		return n;
	double res = 1;
	for (int p = n; p > n - i; p--)
		res *= p;
	return res / fact(i);
}

double func(double x)
{
	return x * x * x - 2 * x * x + 3 * x - 6;
}

int main()
{
	double x;					// 在x处
	double n;					// n阶求导
	cout << "x = ";
	cin >> x;
	cout << "n = ";
	cin >> n;
	double sum = 0;
	for (double i = 0; i <= n; i++)
		sum += pow(-1, i) * comb(n, i) * func(x + (n - i) * 0.001);
	cout << "Result: " << sum / pow(0.001, n);
}
