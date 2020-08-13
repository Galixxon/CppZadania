#ifndef _LIST_HPP
#define _LIST_HPP
#include<initializer_list>
#include<iostream>
template<typename T>
class list
{
    private:
    class node
    {
        public: 
        T val;
        node* next;
        node(T);
    };

    private:
    node *begin;
    
    public:
    list();
    list(const list&);
    list(list&&);
    list(std::initializer_list<T>);
    const list& operator=(list&);
    const list& operator=(list&&);
    ~list();

    public:
    void addElem(T, int );
    void delElem(T);
    int findElem(T);
    int countElems();

    template<typename U>
    friend std::ostream& operator<<(std::ostream&, const list<U>&);
};

template<typename T>
list<T>::node::node(T v) : val(v), next(nullptr) {}

template<typename T>
list<T>::list() : begin(nullptr) {}


template<typename T>
list<T>::list(const list& copy) : begin(new node(copy.begin->val))
{
    node *beg_ptr = begin;
    node *copy_ptr = copy.begin->next;
    while(copy_ptr)
    {
        beg_ptr->next = new node(copy_ptr->val);
        beg_ptr = beg_ptr->next;
        copy_ptr=copy_ptr->next;
    }
}

template<typename T>
list<T>::list(list&& move) : begin(move.begin)
{
    move.begin = nullptr;
}

template<typename T>
const list<T>& list<T>::operator=(list<T>& copy_list)
{
    node *beg_ptr = begin;
        node *copy_ptr = copy_list.begin->next;
        while(copy_ptr)
        {
            beg_ptr->next = new node(copy_ptr->val);
            beg_ptr = beg_ptr->next;
            copy_ptr=copy_ptr->next;
        }
        return *this;
}

template<typename T>
const list<T>& list<T>::operator=(list&& move_list)
{
    this->begin = move_list.begin;
    move_list.begin = nullptr;
    return *this;
}


template<typename T>
list<T>::list(std::initializer_list<T> l)
{
    auto it = std::begin(l);
    begin = new node(*it);
    node *ptr = begin;
    for(++it; it != std::end(l); ++it)
    {
        ptr->next = new node(*it);
        ptr = ptr->next;
    }
}


template<typename T>
list<T>::~list()
{
    node *tmp = begin;
    while(begin != nullptr)
    {
        begin = begin->next;
        delete tmp;
        tmp = begin;
    }
}

template<typename T>
void list<T>::addElem(T elem, int pos)
{
    if(pos == 0)
    {
        node *newptr = new node(elem);
        newptr->next = begin;
        begin = newptr;
    }
    else if(pos > 0)
    {
        int counter = 1;
        node *p = begin;
        while(counter < pos && p->next)
        {
            p=p->next;
            counter++;
        }
        node *q = p->next;
        p->next = new node(elem);
        p->next->next = q;
    }
}


template<typename T>
void list<T>::delElem(T val)
{
    node *ptr = begin;
    if(begin->val == val)
    {
        begin = begin->next;
        delete ptr;
    }
    else
    {
        while(ptr->next->val != val)
        {
            if(ptr->next == nullptr)
            {
                return;
            }
            ptr = ptr->next;
        }            
        node *temp = ptr->next;
        ptr->next = temp->next;
        delete temp;
    }
}

template<typename T>
int list<T>::findElem(T val)
{
    int index = 0;
    node *ptr = begin;
    while(ptr != nullptr && ptr->val != val)
    {
        index++;
        ptr = ptr->next;
    }
    return index;
}

template<typename T>
int list<T>::countElems()
{
    int counter = 0;
    node *ptr = begin;
    while(ptr != nullptr)
    {
        counter++;
        ptr = ptr->next;
    }
    return counter;
}


void TempFun()
{
    list<int> i;
    list<float> j;
}

template<typename T>
std::ostream& operator<<(std::ostream& wy, const list<T> &lista)
{
    auto p = lista.begin;
    while(p)
    {
        wy<<p->val<<" ";
        p = p->next;
    }
    return wy;
}
#endif