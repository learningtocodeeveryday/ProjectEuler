#include <iostream>
using namespace std;

const int THREE = 3;
const int FIVE = 5;

bool isMultiple(int multiple, int value)
{
    return (value % multiple == 0);
}


//Time complexity O(n) || Space complexity O(1)
//Optimizations include variadic templates for any number of multiples to check or an array to take in the multiples
//Another optimization is to perform separate iterations of each multiple and instead count by the multiple (slightly less numbers to traverse but more operations due to comparison)
int multiplesOfThreeOrFive(int upperBound)
{
    int sum = 0;

    for(int count = 1; count < upperBound; count++)
    {
        bool multipleOfThree = isMultiple(THREE, count);
        bool multipleOfFive = isMultiple(FIVE, count);

        if(multipleOfThree || multipleOfFive)
        {
            sum += count;
        }
    }

    return sum;
}

int main()
{
    int sum = multiplesOfThreeOrFive(1000);

    cout << sum;

    return 0;
}