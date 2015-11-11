#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

string strrev(string s)
{
    string result = "";
    for(int i =0; i < s.length(); i++){
        result = s[i] + result;
    }
    return result;
}

string repeat()
{
    string s = "";
    s.insert(0, 5, '*');
    return s;
}

char ** splitString(const char words[], char ** buff) {
    string s = words;
    char ** pt_result = buff;
    int index, j = 0;
    bool addWord = false;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == ' ' || (i + 1) == s.length()) {
            if(addWord) {
                string tmp = s.substr(j, i - j);
                //+ 1 for null char
                char * pt = new char(tmp.length() + 1);
                *pt_result = pt;
                strcpy(*pt_result, tmp.c_str());
                pt_result++;
                addWord = false;
            }
            j = i + 1;
        }
        else {
            addWord = true;   
        }
    }
    char ** res = buff;
    return res;
}

int cntSpace(string s) {
    int x = 0;
    int size = s.length();
    for(int i = 0; i < size; i++) {
        if(s[i] == ' ') {
            x++;   
        }
    }
    return x;
}

int print_array(char ** words, int len) {
    int i = 0;
    while(i < len) {
        cout << words[i] << endl;
        i++;
    }
    return 0;
}

int main() 
{
    string s1 = "abcd";
    string * s = &s1;
    string * s2 = s;
    char * list[] = {"abc", "i", "djaksdj", "sdsakdjasadasd", "hhjh"};
    const char test[] = "abc def jkjk lmnop";
    string stest = test;
    char * tbuff[4];
    print_array(splitString(test, tbuff), 4);
    //cout << cntSpace(stest) << endl;
    cout << "True " << true << " False " << false << endl;
    cout << repeat() << endl;
    
}
