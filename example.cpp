#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

enum Season {SPRING, SUMMER, FALL, WINTER};

typedef struct {
    string color = "light green";
} Leaf;

class Tree {
    public:
        Tree() {
            Tree(100);
        }
        ~Tree() {}
        Tree (int maxLeaf) {
            m_maxLeaf = maxLeaf;
            leaves = new Leaf *[100];
        }
        void changeSeason() {
            switch(s) {
                    case(SPRING): cout << "Summer Time!" << endl;
                                  s = SUMMER;
                                  for(int i = 0; i < m_maxLeaf; i++) {
                                      leaves[i]->color = "dark green";
                                  }
                                  return;
                    case(SUMMER): cout << "Fall Time!" << endl;
                                  s = SUMMER;
                                  for(int i = 0; i < m_maxLeaf; i++) {
                                      leaves[i]->color = "orange and red";
                                  }
                                  return;
                    case(FALL):  cout << "Winter Time!" << endl;
                                  s = SUMMER;
                                  for(int i = 0; i < m_maxLeaf; i++) {
                                      delete leaves[i];
                                  }
                                  return;
                    case(WINTER): cout << "Spring Time!" << endl;
                                  s = SUMMER;
                                  for(int i = 0; i < m_maxLeaf; i++) {
                                      leaves[i] = new Leaf;
                                  }
                                  return;
            }
            return;
            
        }
        
    
    private:
        Season s;
        int m_maxLeaf;
        Leaf ** leaves;
};


int main() {
    
    Tree t = Tree(100);
    t.changeSeason();
    t.changeSeason();
    //delete t;
   return 0; 
}


