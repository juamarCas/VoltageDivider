#include "resistor.h"
#define bl 0
#define br 1
#define r 2
#define or 3
#define ye 4 // black, brown, red, orange, yellow, green, blue, violet, grey, white
#define gr 5
#define blu 6
#define vi 7
#define gre 8
#define wh 9

float stablishValue(char isByValue, double value, int c1, int c2, int c3, int c4)
{
    if (c1 < 0 || c2 < 0 || c3 < 0 || c4 < 0 || isByValue < 0 || value < 0)
    {
        printf("Error, negative values not allowed");
        return -1;
    }
    int values[10] = {bl, br, r, or, ye, gr, blu, vi, gre, wh};
    int result;

    if (isByValue)
    {
        if (!isInteger(value))
        {
            return -1;
        }

        result = value;
    }
    else
    {
        if (c4)
        {
            result = (values[c1] * 100 + values[c2] * 10 + values[c3]) * power(10, values[c4]);
        }
        else
        {
            result = (values[c1] * 10 + values[c2]) * power(10, values[c3]);
        }
    }
    return result;
}

int isInteger(double val)
{
    int truncated = (int)val;
    char res = 1;
    if (val != truncated)
    {
        res = 0;
    }
    return res;
}

float power(float a, float b)
{
    int result = 1;
    for (int i = 0; i < b; i++)
    {
        result *= a;
    }

    return result;
}