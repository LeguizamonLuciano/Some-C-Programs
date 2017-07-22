#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

/**
*\brief User inputs float x and float y
**\return X+Y
*
*/
float addition(float x, float y)
{
    float addition;
    addition=x+y;
    return addition;
}

/**
*\brief User inputs float x and float y
**\return X-Y
*
*/
float substraction(float x, float y)
{
    float substraction;
    substraction=x-y;
    return substraction;
}

/**
*\brief User inputs float x and float y
**\return X/Y
*
*/
float quotient(float x, float y)
{
    float quotient;
    quotient=x/y;
    return quotient;
}

/**
*\brief User inputs float x and float y
**\return X*Y
*
*/
float product(float x, float y)
{
    float product;
    product=x*y;
    return product;
}

/**
*\brief User inputs float x
**\return !X
*
*/
float factorial(float x)
{
    float i=0;
    float factorial=1;
    for(i=1;i<=x;i++)
    {
        factorial=factorial*i;
    }
    return factorial;
}

/**
*\brief User inputs float x and float y
**\return (X+Y)+(X-Y)+(X/Y)+(X*Y)+(!X)
*
*/
float allOperations(float x, float y)
{
    float addition;
    float substraction;
    float quotient;
    float product;

    addition=x+y;
    substraction=x-y;
    quotient=x/y;
    product=x*y;

    float i=0;
    float factorial=1;

}
