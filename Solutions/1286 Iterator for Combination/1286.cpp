#include <iostream>
#include <string.h>
#include <string>

/* For n characters we can represent our desired result as a number in binary
 * (esp since the character length is limited to 15). We can then use the
 * binary number as a mask of indicies to print the characters.
 */

class CombinationIterator
{
  public:
    int length, mask;
    std::string input;

    CombinationIterator(std::string characters, int combinationLength)
    {
        input = characters;
        length = combinationLength;
        // We're using the mask for indicies so for n characters we start at n-1
        mask = (1 << characters.length()) - 1;
    }

    std::string next()
    {
        std::string output;
        // As long as mask is >0 and doesn't match our combination length change it
        while (mask && __builtin_popcount(mask) != length)
        {
            mask--;
        }
        for (int i = 0; i < input.length(); i++)
        {
            /* If we match the bit in our mask, add the letter to the output combination
             * Note that this only works because our list is sorted and we aren't required
             * to loop back around, ie 'abc,2' doesn't require us to print 'ba' or 'ca,cb'
             */
            if (mask & 1 << (input.length() - i - 1))
            {
                output += input[i];
            }
            // If we already have enough characters, break out to save a bit of time
            if (output.length() == length)
            {
                break;
            }
        }
        // Now that we have our result, force us to move onto the next one
        mask--;
        return output;
    }

    bool hasNext()
    {
        // Do the same subtraction again and check if mask is 0 or not after
        while (mask && __builtin_popcount(mask) != length)
        {
            mask--;
        }
        if (!mask)
        {
            return false;
        }
        return true;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

int main()
{
    std::string characters = "abc";
    int combinationLength = 2;

    CombinationIterator *obj = new CombinationIterator(characters, combinationLength);
    std::string param_1;
    bool param_2 = 1;

    while (param_2)
    {
        param_1 = obj->next();
        param_2 = obj->hasNext();
        std::cout << param_1 << std::endl;
        std::cout << param_2 << std::endl;
    }
}