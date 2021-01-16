#include "myexp.h"
#include <iostream>

MyExp::MyExp()
{
    this->mX = 0.0;
}
MyExp::MyExp(double x)
{
    this->mX = x;
}
MyExp::MyExp(const MyExp &obj)
{
    this->mX = obj.getX();
}
MyExp::~MyExp()
{
    this->mX = 0.0;
}
double MyExp::value()
{
    double sum=0.0;
    for(int k=0; k<=10; k++)
        sum = sum + (this->power(this->mX,k) / this->factorial(k));
    return sum;
}
void MyExp::setX(double x)
{
    this->mX = x;
}
double MyExp::getX() const
{
    return this->mX;
}
unsigned int MyExp::factorial(unsigned int n)
{
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}
double MyExp::power(double x, unsigned int y)
{
    if (y == 0)
        return 1.0;
    else if (y % 2 == 0)
        return power(x, y / 2.0) * power(x, y / 2.0);
    else
        return x * power(x, y / 2.0) * power(x, y / 2.0);
}
int main(int argc, char **argv)
{
    MyExp me(5.0);

    std::cout << me.value() << "\n";

    return 0;
}