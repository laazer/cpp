#ifndef _WORDS_HPP_
#define _WORDS_HPP_

/* Words structure
 */

struct Words {
  unsigned int num_words; // Number of words currently in list
  unsigned int max_words; // The total size allocated to the list
  char **list;            // The list storing the words
};



/* Function: newList
 *
 * Takes the max_words of the list and creates a new Words
 * with the given max_words without assigning any words, sets 
 * num_words to zero. returns the new list to the calling function.
 * max_words must be greater than zero, otherwise newList returns 
 * NULL.
 */
Words *newList(const unsigned int max_words);


/* Function: newList
 *
 * Overloaded version of newList, this one takes a character 
 * array with words separated by any number of spaces, for example:
 *
 * "charmeleon mewtwo pikachu charmander squirtle caterpie raichu butterfree abra kadabra alakazam slowpoke spoink"
 *
 * has 13 words.  This newList will allocate enough space
 * for the words, then the list will be initialized to those
 * words and returns the list to the calling function. If  
 * words is empty, newList does nothing and returns NULL.
 */
Words *newList(const char words[]);


/* Function: deleteList
 *
 * Takes a dynamically allocated Words and deletes
 * the list and then the Words itself, returns 0.  
 * If the Words is NULL deleteList does nothing and 
 * returns -1;
 */
int deleteList(Words *p_w);


/* Function: printList
 *
 * Prints the words in the Words on a single Line 
 * with a single space between words. There is no 
 * space after the last word, but there is a newline,
 * returns 0 for successful print. If p_w is NULL, 
 * printList does nothing returns -1.
 */
int printList(Words *p_w);

/* Function: appendList
 *
 * Takes a Words and a character array consisting of words
 * separated by spaces, for example:
 *
 * "charmander squirtle caterpie raichu"
 *
 * Contains four words. appendList will take the Words
 * and append these words to list.  If the Words does not
 * have enough space, appendList will dynamically allocate
 * more space to list to allow these new words to fit.  
 * Returns the number of words appended.  If words is empty 
 * or if p_w is NULL then appendList does nothing and returns -1.
 */
int appendList(Words *p_w, const char words[]);


/* Function: appendList
 *
 * Takes two Words, appends the contents of src
 * to dst.  If dst does not have enough space
 * appendList should dynamically allocate additional space
 * then append the contents of src to dst, returns 
 * 0 on success.  If either Words is NULL appendList does 
 * nothing and returns -1.
 */
int appendList(Words *dst, const Words *src);


/* Function: findWord
 *
 * Finds the first occurrence of the word in the Words
 * returns a pointer to that word in the list.  Otherwise
 * returns NULL. If p_w is NULL returns NULL.
 */
const char *findWord(const Words *p_w, const char word[]);


/* Function: removeWord
 *
 * If p_w is null, returns -1. Otherwise, searches for every 
 * occurrence of word[], and removes that word of the list, returns 
 * the number of words removed.
 */
int removeWord(Words *p_w, const char word[]);

#endif
