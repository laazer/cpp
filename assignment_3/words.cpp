#include "words.hpp"
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

/*
 * Counts the number of spaces in the given string
 */
int cntSpace(string s);
/*
 * Splits a string into a cstring array of strings and puts them in 
 * the given buffer
 */
char ** splitString(const char words[], char ** buff);
/*
 * combinds the lists of strings in the given words and puts them into
 * the given buffer
 */
int combindList(Words * w1, const Words * w2, char ** buff);

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

int combindList(Words * w1, const Words * w2, char ** buff) {
    char ** pt_buff = buff;
    for(int i = 0; i < w1->num_words; i++) {
        string s = w1->list[i];
        char * pt = new char(s.length() + 1);
        *pt_buff = pt;
        strcpy(*pt_buff, s.c_str());
        pt_buff++;
    }
    for(int j = 0; j < w2->num_words; j++) {
        string s = w2->list[j];
        char * pt = new char(s.length() + 1);
        *pt_buff = pt;
        strcpy(*pt_buff, s.c_str());
        pt_buff++;
    }
    return 0;
}

Words *
newList(const unsigned int max_words)
{
    if(max_words <= 0) {
        return NULL;   
    }
    Words * my_words = new Words;
    my_words->max_words = max_words;
    my_words->num_words = 0;
    return my_words;
}

Words * newList(const char words[])
{
    if(strcmp(words, "") == 0 || words == NULL) {
        return NULL;
    }
    string s = words;
    int num_words = cntSpace(s) + 1;
    Words * my_words = new Words;
    char * wbuff[num_words];
    my_words->list = splitString(words, wbuff);
    my_words->num_words = num_words;
    my_words->max_words = num_words;
    return my_words;
}

int
deleteList(Words *p_w)
{
    if(p_w == NULL) {
        return -1;
    }
    for(int i = 0; i < p_w->num_words; i++) {
        delete p_w->list[i];   
    }
    delete p_w->list;
    delete p_w;
    return 0;
}

int
printList(Words *p_w)
{
    if(p_w == NULL) {
        return -1;
    }
    for(int i = 0; i < p_w->num_words; i++) {
        cout << p_w->list[i] << " " << endl;   
    }
    return 0;
}

int appendList(Words *p_w, const char words[])
{
    if(p_w == NULL || strcmp(words, "") == 0 || words == NULL)
    {
        return -1;
    }
    int wsize = cntSpace(words) + 1;
    int tsize = max(p_w->max_words, wsize + p_w->num_words);
    char * wbuff[tsize];
    Words * tmpWord = newList(words);
    p_w->num_words = p_w->num_words + wsize;
    p_w->max_words = tsize;
    combindList(p_w, tmpWord, wbuff);
    p_w->list = wbuff;
    delete tmpWord;
    return wsize;
}

int appendList(Words *dst, const Words *src)
{
    if(dst == NULL || src == NULL)
    {
        return -1;
    }
    int tsize = max(dst->max_words, dst->num_words + src->num_words);
    char * wbuff[tsize];
    dst->num_words = dst->num_words + src->num_words;
    dst->max_words = tsize;
    int res = combindList(dst, src, wbuff);
    dst->list = wbuff;
    return res;
}

const char * findWord(const Words *p_w, const char word[])
{
    if(p_w == NULL || strcmp(word, "") == 0 || word == NULL)
    {
        return NULL;
    }
    for(int i = 0; i < p_w->num_words; i++)
    {
        char * res = p_w->list[i];
        if(strcmp(res, word) == 0) {
            return res;
        }
    }
    return NULL;
}

int
removeWord(Words *p_w, const char word[])
{
    if(p_w == NULL) {
        return -1;    
    }
    char ** clist = p_w->list;
    bool mvup = false;
    int cnt = 0;
    for(int i = 0; i < p_w->num_words; i++) {
        if(mvup) {
            clist = ++clist;
        }
        if(strcmp(clist[i], word) == 0) {
            char * tmp = clist[i];
            clist = ++clist;
            mvup = true;
            delete tmp;
            tmp = NULL;
            cnt++;
        }
    }
    p_w->num_words = p_w->num_words - cnt;
    return cnt;
}
