#ifndef _SLIST_HPP_
#define _SLIST_HPP_
#include <cstddef>
/*
* Singly-linked list container and related utility classes.
*/
// Utility struct for linked list nodes.
// Not intended for direct use outside SList.
template< typename T >
struct SList_Node
{
    T data;
    SList_Node * next;
    SList_Node(const T & v, SList_Node * n):
    data(v),
    next(n)
    {
    }
};

// Utility struct for list iterator.
// Not intended for direct use outside SList.
template< typename T >
struct SList_Iterator
{
    SList_Node<T> * node;
    SList_Iterator(SList_Node<T> * n): node(n) { }
    SList_Iterator & operator++()
    {
        node = node->next;
        return *this;
    }
    SList_Iterator operator++(int)
    {
        SList_Iterator tmp = *this;
        node = node->next;
        return tmp;
    }
    T & operator*()
    {
        return node->data;
    }
    const T & operator*() const
    {
        return node->data;
    }
};

template< typename T >
bool operator==(const SList_Iterator<T> & lhs, const SList_Iterator<T> & rhs)
{
    SList_Node<T> * pl = lhs.node;
    SList_Node<T> * pr = rhs.node;
    while(pl != NULL || pl != NULL) {
        if(pl->data != pr->data) {
            return false;
        }
        pl = pl->next;
        pr = pr->next;
    }
    return pl == pr;
}

template< typename T >
bool operator!=(const SList_Iterator<T> & lhs, const SList_Iterator<T> & rhs)
{
    return !(lhs == rhs);
}

// Utility struct for list const iterator.
// Not intended for direct use outside SList.
template< typename T >
struct SList_ConstIterator
{
    const SList_Node<T> * node;
    SList_ConstIterator(const SList_Node<T> * n): node(n) { }
    SList_ConstIterator(const SList_Iterator<T> & it): node(it.node) { }
    SList_ConstIterator & operator++()
    {
        node = node->next;
        return *this;
    }
    
    SList_ConstIterator operator++(int)
    {
        SList_ConstIterator tmp = *this;
        node = node->next;
        return tmp;
    }
    
    const T & operator*() const
    {
        return node->data;
    }
};

template< typename T >
bool operator==(const SList_ConstIterator<T> & lhs, const SList_ConstIterator<T> & rhs)
{   
    return SList_Iterator<T>(lhs.node) == SList_Iterator<T>(rhs.iterator);
}

template< typename T >
bool operator!=(const SList_ConstIterator<T> & lhs, const SList_ConstIterator<T> & rhs)
{
    return !(lhs == rhs);
}

// Additional iterator operators.
template< typename T >
bool operator==(const SList_Iterator<T> & lhs, const SList_ConstIterator<T> & rhs)
{
    return lhs == SList_Iterator<T>(rhs.node);
}

template< typename T >
bool operator!=(const SList_Iterator<T> & lhs, const SList_ConstIterator<T> & rhs)
{
    return !(lhs == rhs);
}

template< typename T >
bool operator==(const SList_ConstIterator<T> & lhs, const SList_Iterator<T> & rhs)
{
    return rhs == lhs;
}

template< typename T >
bool operator!=(const SList_ConstIterator<T> & lhs, const SList_Iterator<T> & rhs)
{
    return !(lhs == rhs);
}

// Class for the list itself.
template< typename T >
class SList
{
    public:
        typedef SList_Iterator<T> iterator;
        typedef SList_ConstIterator<T> const_iterator;
        SList() { 
            m_head = NULL;
        }
        SList(const SList & o)
        {
            copy_from(o);
        }
        ~SList()
        {
            clear();
        }
        SList & operator=(const SList & o)
        {
            clear();
            copy_from(o);
            return *this;
        }
        iterator begin()
        {
            return SList_Iterator<T>(m_head);
        }
        iterator end()
        {  
            return SList_Iterator<T>(NULL);
        }
        const_iterator begin() const
        {
            return SList_ConstIterator<T>(m_head);
        }
        const_iterator end() const
        {
            return SList_ConstIterator<T>(NULL);
        }
        bool empty() const
        {
            return m_head == NULL;
        }
        void clear()
        {
            while(!(this->empty())) {
                pop_front();
            }
        }
        T & front()
        {
            return m_head->data;
        }
        const T & front() const
        {
            return m_head->data;
        }
        void push_front(const T & v)
        {
            m_head = new SList_Node<T>(v, m_head);
        }
        void pop_front()
        {
            SList_Node<T> * tmp = m_head;
            m_head = m_head->next;
            delete tmp;
        }
        iterator insert_after(iterator it, const T & v)
        {
            it.node->next = new SList_Node<T>(v, it.node->next);
            return SList_Iterator<T>(it.node->next);
        }
        iterator erase_after(iterator it)
        {
            SList_Node<T> * next = it.node->next;
            SList_Node<T> * next_next = next->next;
            it.node->next = next_next;
            delete next;
            return SList_Iterator<T>(next_next);
        }
    private:
        void copy_from(const SList & o)
        {
            SList_Node<T> ** node_hlpr = &m_head;
            SList_Node<T> * o_node = o.m_head;
            while (o_node != NULL)
            {
                SList_Node<T> * new_node = new SList_Node<T>(o_node->data, NULL);
                *node_hlpr = new_node;
                node_hlpr = &(new_node->next);
                o_node = o_node->next;
            }
        }
        SList_Node<T> * m_head;
};

#endif