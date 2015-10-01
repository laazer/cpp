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

char ** splitString(const char words[], int w_cnt) {
    string s = words;
    char * result[w_cnt];
    int index, j = 0;
    bool addWord = false;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == ' ') {
            cout << "found space" << endl;
            if(addWord) {
                string tmp = s.substr(j, i);
                //+ 1 for null char
                char * pt = new char(tmp.length() + 1);
                result[index] = pt;
                strcpy(result[index], tmp.c_str());
                index++;
                addWord = false;
            }
            j = i + 1;
        }
        else {
            addWord = true;   
        }
    }
    char ** res = result;
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

//char **strsplit(const char* str, const char* delim, size_t* numtokens) {
//    // copy the original string so that we don't overwrite parts of it
//    // (don't do this if you don't need to keep the old line,
//    // as this is less efficient)
//    char *s = strdup(str);
//
//    // these three variables are part of a very common idiom to
//    // implement a dynamically-growing array
//    size_t tokens_alloc = 1;
//    size_t tokens_used = 0;
//    char **tokens = calloc(tokens_alloc, sizeof(char*));
//
//    char *token, *strtok_ctx;
//    for (token = strtok_r(s, delim, &strtok_ctx);
//            token != NULL;
//            token = strtok_r(NULL, delim, &strtok_ctx)) {
//        // check if we need to allocate more space for tokens
//        if (tokens_used == tokens_alloc) {
//            tokens_alloc *= 2;
//            tokens = realloc(tokens, tokens_alloc * sizeof(char*));
//        }
//        tokens[tokens_used++] = strdup(token);
//    }
//
//    // cleanup
//    if (tokens_used == 0) {
//        free(tokens);
//        tokens = NULL;
//    } else {
//        tokens = realloc(tokens, tokens_used * sizeof(char*));
//    }
//    *numtokens = tokens_used;
//    free(s);
//
//    return tokens;
//}

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
    char * list[] = {"abc", "i", "djaksdj", "sdsakdjasadasd", "hhjh"};
    const char test[] = "abc def jkjk lmnop";
    string stest = test;
    print_array(splitString(test, 4), 4);
    //cout << cntSpace(stest) << endl;
    cout << "True " << true << " False " << false << endl;
    cout << repeat() << endl;
    
}