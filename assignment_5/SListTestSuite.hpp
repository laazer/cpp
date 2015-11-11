#include <cxxtest/TestSuite.h>
#include <iostream>
#include "SList.hpp"

class SListTestSuite : public CxxTest::TestSuite
{
public:
    
    void testSList_Iterator(void) {
        SList_Node<int> * pn1 = new SList_Node<int>(1, NULL);
        SList_Node<int> * pn2 = new SList_Node<int>(2, pn1);
        SList_Node<int> * pn3 = new SList_Node<int>(3, pn2);
        SList_Node<int> * pn3b = new SList_Node<int>(3, pn2);
        SList_Iterator<int> li1 = SList_Iterator<int>(pn3);
        SList_Iterator<int> li2 = SList_Iterator<int>(pn3b);
        SList_Iterator<int> li3 = SList_Iterator<int>(pn2);
        TS_ASSERT_EQUALS(li1, li2);
        TS_ASSERT(li1 != li3);
        TS_ASSERT_EQUALS(li1.node, pn3);
        TS_ASSERT_EQUALS(*li1, 3);
        li1++;
        TS_ASSERT_EQUALS(li1.node, pn2);
        TS_ASSERT_EQUALS(li1, li3);
        TS_ASSERT_EQUALS(*li1, 2);
        li1++;
        TS_ASSERT_EQUALS(li1.node, pn1)
        TS_ASSERT_EQUALS(*li1, 1);
        SList_Iterator<int> lin1 = SList_Iterator<int>(NULL);
        SList_Iterator<int> lin2 = SList_Iterator<int>(NULL);
        TS_ASSERT_EQUALS(lin1, lin2);
        TS_ASSERT(lin1 != li1);
        
    }
    
    void testSList_ConstIterator(void) { 
        SList_Node<int> * pn1 = new SList_Node<int>(1, NULL);
        SList_Node<int> * pn2 = new SList_Node<int>(2, pn1);
        SList_Node<int> * pn3 = new SList_Node<int>(3, pn2);
        SList_Node<int> * pn3b = new SList_Node<int>(3, pn2);
        SList_ConstIterator<int> li1 = SList_ConstIterator<int>(pn3);
        SList_ConstIterator<int> li2 = SList_ConstIterator<int>(pn3b);
        SList_Iterator<int> cli1 = SList_Iterator<int>(pn3b);
        SList_ConstIterator<int> li3 = SList_ConstIterator<int>(pn2);
        TS_ASSERT_EQUALS(li1, li2);
        TS_ASSERT_EQUALS(li1, cli1);
        TS_ASSERT_EQUALS(cli1, li1);
        TS_ASSERT(li1 != li3);
        TS_ASSERT_EQUALS(li1.node, pn3);
        TS_ASSERT_EQUALS(*li1, 3);
        li1++;
        TS_ASSERT_EQUALS(li1.node, pn2);
        TS_ASSERT_EQUALS(li1, li3);
        TS_ASSERT_EQUALS(*li1, 2);
        li1++;
        TS_ASSERT_EQUALS(li1.node, pn1)
        TS_ASSERT_EQUALS(*li1, 1);
        SList_ConstIterator<int> li1b = SList_ConstIterator<int>(li1);
        TS_ASSERT_EQUALS(li1, li1b);
        SList_ConstIterator<int> lin1 = SList_ConstIterator<int>(NULL);
        SList_ConstIterator<int> lin2 = SList_ConstIterator<int>(NULL);
        TS_ASSERT_EQUALS(lin1, lin2);
    }
    
    void testSlist(void) {
        SList_Node<int> * pn1 = new SList_Node<int>(1, NULL);
        SList_Node<int> * pn2 = new SList_Node<int>(2, pn1);
        SList_Node<int> * pn3 = new SList_Node<int>(3, pn2);
        SList_Node<int> * pn3b = new SList_Node<int>(3, pn2);
        SList_Iterator<int> li1 = SList_Iterator<int>(pn3);
        SList_Iterator<int> li2 = SList_Iterator<int>(pn3b);
        SList_Iterator<int> li3 = SList_Iterator<int>(pn2);
        SList<int> l1 = SList<int>();
        SList<int> l2 = SList<int>();
        TS_ASSERT(l1.empty());
        l1.push_front(1);
        TS_ASSERT(!l1.empty());
        l1.push_front(2);
        l1.push_front(3);
        TS_ASSERT_EQUALS(l1.end(), l2.end());
        TS_ASSERT(l1.begin() != l2.begin());
        l2.push_front(1);
        l2.push_front(2);
        l2.push_front(3);
        SList_Iterator<int> li1b = l1.begin();
        SList_Iterator<int> li2b = l2.begin();
//        for (SList_Iterator<int> it = l1.begin() ; it != l1.end(); ++it) {
//            std::cout << ' ' << *it << ' ' << *li2b;
//            li2b++;
//        }       
        //TS_ASSERT_EQUALS(l1.begin(), l1.begin());
        l1.pop_front();
        TS_ASSERT_EQUALS(l1.front(), 2);
        l1.push_front(3);
        li1b = l1.begin();
        li1b++;
        l1.insert_after(li1b, 5);
        TS_ASSERT_EQUALS(*li1b, 2);
        li1b++;
        TS_ASSERT_EQUALS(*li1b, 5);
        
    }

};
