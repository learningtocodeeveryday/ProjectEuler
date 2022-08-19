#include <iostream>
#include <cmath>
using namespace std;

//outline: iterate through potential factors (1 to n/2), each factor will repeatedly reduce the number (in effect a smaller number will be the upperbound). Worst case it's a prime, regardless time
//complexity is O(n^2) and space complexity is O(1). (only need to retain current value/upperbound, largest prime seen so far)

//The time complexity is quadratic because I may potentially have to go to the upperbound and also because I have to do a check that it is a prime factor

bool isPrime(long long int n)
{
    bool primeStatus = true;

    for(long long int potentialFactor = 2; potentialFactor <= sqrt(n); potentialFactor++)
    {
        if(n % potentialFactor == 0)
        {
            primeStatus = false;
            break;
        }
    }

    return primeStatus;
}

long long int largestPrime(long long int fullValue)
{
    long long int currentValue = fullValue;

    long long int largestPrimeFactor = -1;

    for(long long int potentialFactor = 2; potentialFactor <= currentValue; potentialFactor++) //key step here is to remember that go up to the current value (otherwise you may miss the last prime factor). This happens because the current value is reduced by factors and the full current value may be the factor itself
    {
        bool primeStatus = isPrime(potentialFactor);
        bool isFactor = (currentValue % potentialFactor == 0);

        if(primeStatus && isFactor)
        {
            largestPrimeFactor = potentialFactor;
        }

        if(isFactor)
        {
            while(currentValue % potentialFactor == 0)
            {
                currentValue = (currentValue / potentialFactor);
            }
        }

    }

    return largestPrimeFactor;
}


int main()
{
    long long int upperBound = 600851475143;
    long long int lPrimeFactor = largestPrime(upperBound);

    if(lPrimeFactor == -1)
    {
        cout << "No prime factors";
    }
    else
    {
        cout << "Largest prime factor is " << lPrimeFactor;
    }

}