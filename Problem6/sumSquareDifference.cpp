#include <iostream>
#include <cmath>
using namespace std;

const int START_NATURAL_NUMBER = 1;

long long sumOfSquares(int endNaturalNumber)
{
    long long sum = 0;
    
    for(int current = START_NATURAL_NUMBER; current <= endNaturalNumber; current++)
    {
        sum += pow(current, 2);
    }
    
    return sum;
}

long long squareOfSums(int endNaturalNumber)
{
    long long sum = 0;
    for(int current = START_NATURAL_NUMBER; current <= endNaturalNumber; current++)
    {
        sum += current;
    }
    
    sum = pow(sum, 2);
    
    return sum;
}


long long sumSquareDifference(int endNaturalNumber)
{
    long long sumOfSquare = sumOfSquares(endNaturalNumber);
    long long squareOfSum = squareOfSums(endNaturalNumber);
    
    return (squareOfSum - sumOfSquare);
}

int main()
{
    
    
    cout << sumSquareDifference(100);
    

    return 0;
}
