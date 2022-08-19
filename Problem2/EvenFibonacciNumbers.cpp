#include <iostream>
#include <vector>
using namespace std;

const int UPPER_BOUND = 4000000;

const int FIRST_FIB = 1;
const int SECOND_FIB = 2;

bool isEven(int value)
{
    return (value % 2 == 0);
}

//assuming an upper bound above 2
vector<int> fibValuesUpToBoundary(int upperBound)
{
    vector<int> fibValues = {FIRST_FIB, SECOND_FIB};

    int iterationMinusTwo = FIRST_FIB;
    int iterationMinusOne = SECOND_FIB;
    int current;

    while(true)
    {
        current = iterationMinusTwo + iterationMinusOne;

        iterationMinusTwo = iterationMinusOne;
        iterationMinusOne = current;

        if(current >= upperBound)
        {
            break;
        }

        fibValues.push_back(current);
    }

    return fibValues;

}

int sumOfEvens(vector<int> values)
{
    int sum = 0;
    for(int value : values)
    {
        if(isEven(value))
        {
            sum += value;
        }
    }

    return sum;
}

int sumOfFibValuesUpToBoundary(int upperBoundary)
{
    vector<int> fibValues = fibValuesUpToBoundary(UPPER_BOUND);
    int sum = sumOfEvens(fibValues);

    return sum;
}

//Using memoization this is O(n) time complexity and also O(n) space complexity due to storing of the fib values. Can optimize the space by summing the even fib values instead of storing them in an array
int main()
{
    int sum = sumOfFibValuesUpToBoundary(UPPER_BOUND);
    cout << sum;


    return 0;
}