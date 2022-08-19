#include <iostream>
#include <string>
using namespace std;


const int LARGEST_THREE_DIGIT = 999;
const int SMALLEST_THREE_DIGIT = 100;

const long long LARGEST_THREE_DIGIT_PRODUCT = LARGEST_THREE_DIGIT * LARGEST_THREE_DIGIT;
const long long SMALLEST_THREE_DIGIT_PRODUCT = SMALLEST_THREE_DIGIT * SMALLEST_THREE_DIGIT;

//outline: we want to find the largest palindrome product. Requires a helper function to validate a number is a palindrome (string manipulation is simplest but can also be done numerically)
//The possible values are between LARGEST_THREE_DIGIT_PRODUCT and SMALLEST_THREE_DIGIT_PRODUCT. Since we're finding the largest best to start largest to smallest and break when the first one is found.
//When we find a palindrome we have to make sure it's divisible by two three digit values

bool isPalindrome(long long value)
{
    string strNum = to_string(value);

    bool palindromeStatus = true;

    for(int startIndex = 0, endIndex = strNum.size() - 1; startIndex <= (strNum.size() / 2); startIndex++, endIndex--)
    {
        if(strNum[startIndex] != strNum[endIndex])
        {
            palindromeStatus = false;
            break;
        }
    }

    return palindromeStatus;
}

bool twoMultiplesBetween(int lowerBound, int upperBound, long long value)
{  
    bool found = false;


    for(int currentLower = lowerBound; currentLower <= upperBound; currentLower++)
    {
        if(value % currentLower == 0)
        {
            int secondMultiple = value / currentLower;

            if(secondMultiple >= lowerBound && secondMultiple <= upperBound)
            {
                found = true;
                break;
            }
        }
    }

    return found;
}

//should be parameterized to work for a range of values (instead of hard coded in the for loop)
//time complexity is O(n^2) given that we have to traverse the range of three digit products (100x100 through 999 * 999) then for each value we are performing division and palindrome check (maybe + O(m))
//the space complexity is O(1)
long long largestPalindromeProductForThreeDigits()
{

    for(long long largest = LARGEST_THREE_DIGIT_PRODUCT; largest >= SMALLEST_THREE_DIGIT_PRODUCT; largest--)
    {
        bool twoThreeDigitMutliples = twoMultiplesBetween(SMALLEST_THREE_DIGIT, LARGEST_THREE_DIGIT, largest); //the division is less intensive than checking palindrome
        bool palindromeStatus = false; //only checked if divisible by a three digit

        if(twoThreeDigitMutliples)
        {
            palindromeStatus = isPalindrome(largest);
        }

        if(palindromeStatus)
        {
            return largest;
        }

    }

    return -1;
}


int main()
{
    long long solution = largestPalindromeProductForThreeDigits();
    long long flag = -1;

    if(solution == flag)
    {
        cout << "There was no solution";
    }
    else
    {
        cout << "largest palindrome product for three digits is " << solution;
    }

    return 0;
}