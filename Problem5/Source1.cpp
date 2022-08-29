#include <iostream>
#include <vector>
using namespace std;


//example: 2520 can be divisible by 1-10
//factors of 2520 - 2 2 2 3 3 5 7

//possible: start with 1 and add the single lowest factor as required to reach divisibility
// 1 2 3 4 5 6 7 8 9 10
// 1 2 3 2 5   7 2 3

int smallestMultiple(int endValue)
{
	vector<int> factors;
	factors.push_back(1);

	int currentProduct;

	for (int divisible = 1; divisible <= endValue; divisible++)
	{
		bool isDivisible = false;
		currentProduct = 1;

		for (auto factor : factors)
		{
			currentProduct *= factor;
			if (currentProduct % divisible == 0)
			{
				isDivisible = true;
				break;
			}
		}

		if (!isDivisible)
		{
			for (int potentialFactor = 2; potentialFactor <= divisible; potentialFactor++)
			{
				currentProduct *= potentialFactor;
				if (currentProduct % divisible == 0)
				{
					factors.push_back(potentialFactor);
					break;
				}
				else
				{
					currentProduct /= potentialFactor;
				}
			}
		}

	}

	int finalProduct = 1;
	for (auto factor : factors)
	{
		finalProduct *= factor;
	}

	return finalProduct;

}

int main()
{
	cout << smallestMultiple(20);

	return 0;
}