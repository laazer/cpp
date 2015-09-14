#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

int fizzbuzz(int n);
int fib(int n);
int sum();
int reverse(string file);
int frame(string file);

//function for problem 1
int fizzbuzz(int n)
{
    int i = 1;
    while(i < n)
    {
        if(i % 3 + i % 5 == 0)
            cout << "fizzbuzz" << endl;
        else if(i % 5 == 0)
            cout << "buzz" << endl;
        else if(i % 3 == 0)
            cout << "fizz" << endl;
        else 
            cout << i << endl;
        i++;
    }
    return 0;
}

//fib helper function
int fibh(int n, int i, int j)
{
    if(n < 0)
    {
        cerr << "Given number must be posotive" << endl;
        return -1;
    }
    cout << i << endl;
    if(n == 0)
        return 0;
        
    else
        fibh(--n, i + j, i);
    
    return 0;
}

//function for problem 2
int fib(int n)
{
    return fibh(n, 1, 0);
}

//function for problem 3
int sum()
{
    int i, s = 0;
    while(cin >> i)
    {
        s += i;
    }
    return s;
}

//simple string reversal function
string strrev(string s)
{
    string result = "";
    for(int i =0; i < s.length(); i++){
        result = s[i] + result;
    }
    return result;
}

//function for problem 4
int reverse(string file)
{
    string line;
    ifstream myfile (file);
    if (myfile.is_open())
    {
        while ( getline(myfile, line) )
        {
            cout << strrev(line) << endl;
        }
        myfile.close();
    }

    else 
    {
        cerr << "Unable to open file"; 
        return -1;
    }

    return 0;
}

//retreives the size of the line in the given text file with the greatest length
int getmaxline(string file)
{
    int maxL = 0; //max line size
    string line;
    ifstream myfile (file);
    if (myfile.is_open())
    {
        while ( getline(myfile, line) )
        {
            maxL = max((unsigned long)maxL, line.length()); 
        }
        myfile.close();
    }

    else 
    {
        cerr << "Unable to open file"; 
        return -1;
    }
    return maxL;
}

//function for problem 5
int frame(string file)
{
    int m = getmaxline(file);
    string stars = "";
    stars.insert(0, m + 3, '*'); //extra 2 stars at beginning and end of line
    string line;
    ifstream myfile (file);
    if (myfile.is_open() && m)
    {
        cout << stars << endl;
        while ( getline(myfile, line) )
        {
            line.insert(line.length() - 1, m - line.length(), ' ');
            cout << "* " + line.substr(0, line.length() - 1) + " *" << endl;
        }
        cout << stars << endl;
        myfile.close();
    }

    else 
    {
        cerr << "Unable to open file"; 
        return -1;
    }
    return 0;
}


int main()
{
    fizzbuzz(100);
    fib(25);
    cout << sum() << endl;
    reverse("reverse_input.txt");
    frame("frame_input.txt");
    return 0;
}