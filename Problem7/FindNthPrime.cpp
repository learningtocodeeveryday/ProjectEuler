#include <iostream>
#include <cmath>
using namespace std;

const int GOAL_COUNT = 10001;

bool isPrime(int value) //notifies whether prime
{
    bool primeStatus = true;
    
    for(int current = 2; current <= sqrt(value); current++)
    {
        if(value % current == 0)
        {
            primeStatus = false;
            break;
        }
    }
    
    return primeStatus;
}


int findNthPrime(int n) //counter until you find 10001st prime
{
    int countOfPrimes = 0;
    
    int currentValue = 2;
    
    while(true)
    {
        // countOfPrimes += isPrime(currentValue);
        bool primeStatus = isPrime(currentValue);
        
        if(primeStatus)
        {
            countOfPrimes++;
        }
        
        if(countOfPrimes == GOAL_COUNT)
        {
            break;
        }
        
        currentValue++;
    }
    
    return currentValue;
}

int main()
{
    
    
    cout << findNthPrime(GOAL_COUNT);
    

    return 0;
}
