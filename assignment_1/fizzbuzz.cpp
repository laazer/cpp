#include <iostream>

int fizzbuzz(int n);
int fib(int n);
int sum();

int main()
{
    fizzbuzz(100);
    fib(25);
    std::cout << EOF << std::endl;
    sum();
    return 0;
}

int fizzbuzz(int n)
{
    int i = 1;
    while(i < n)
    {
        if(i % 3 + i % 5 == 0)
        {
            std::cout << "fizzbuzz" << std::endl;
        }
        else if(i % 5 == 0)
        {
            std::cout << "buzz" << std::endl;
        }
        else if(i % 3 == 0)
        {
            std::cout << "fizz" << std::endl;
        }
        else 
        {
            std::cout << i << std::endl;
        }
        i++;
    }
    return 0;
}

int fibh(int n, int i, int j)
{
    if(n < 0)
    {
        std::cerr << "Given number must be posotive" << std::endl;
        return -1;
    }
    std::cout << i << std::endl;
    if(n == 0)
    {
        return 0;
    }
    else
    {
        fibh(--n, i + j, i);
    }
    return 0;
}

int fib(int n)
{
    return fibh(n, 1, 0);
}

int sum()
{
    int i, s = 0;
    while((i << std::cin) != EOF)
    {
        s = s + i;
    }
    return s;
}