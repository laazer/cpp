#include "words.hpp"
#include <cstring>
#include <iostream>
using namespace std;

int getSize(Words * p_w);
int getSize(char ** words);
char ** splitString(const char words[]);
char ** splitString(const char words[], int w_cnt);

char ** splitString(const char words[]) {
    return splitString(words, 100);   
}

char ** splitString(const char words[], int w_cnt) {
    string s = words;
    char result[cnt];
    int start, index = 0;
    bool addWord = false;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == ' ') {
            if(addWord) {
                result[index] = s.substr(j, i - 1);
                index++;
            }
            j = i + 1;
        }
        else {
            addWord = true;   
        }
    }
    return result;
}

int getSize(Words * p_w) {
    char ** p_l = p_w->list;
    int res = getSize(p_l);
    return res;   
}

int getSize(char ** words) {
    int wordsSize = sizeof(words);
    if(!wordsSize) {
        return 0;
    }
    return wordsSize/sizeof(words[0]);
}

Words *
newList(const unsigned int max_words)
{
    Words * my_words = new Words;
    my_words->max_words = max_words;
    return my_words;
}

Words *
newList(const char words[])
{
    if(!sizeof(words)) {
        return NULL;
    }
    int size = getSize(words);
    Words * my_words = new Words;
    my_words->list = words;
    my_words->num_words = size;
    my_words->max_words = sizeof(words);
    return my_words;
}

int
deleteList(Words *p_w)
{
    int size = getSize(p_w);
    for(int i = 0; i < size; i++) {
        delete p_w->list[i];   
    }
    delete p_w->list;
    delete p_w;
    return 0;
}

int
printList(Words *p_w)
{
    int size = getSize(p_w);
    for(int i = 0; i < size; i++) {
        cout << p_w->list[i] << " " << endl;   
    }
    return 0;
}

int
appendList(Words *p_w, const char words[])
{
  // TODO
  return -1;
}

int
appendList(Words *dst, const Words *src)
{
  // TODO
  return -1;
}

const char *
findWord(const Words *p_w, const char word[])
{
  // TODO
  return NULL;
}

int
removeWord(Words *p_w, const char word[])
{
  // TODO
  return -1;
}
