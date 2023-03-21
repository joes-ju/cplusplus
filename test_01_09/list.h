#include"test.cpp"

namespace joes
{
  template<class T>
  struct list_node
  {
    list_node<T>* _prev;
    list_node<T>* _next;
    T _data;

    list_node(const T& x)
      :_prev(nullptr)
       ,_next(nullptr)
       ,_data(x)
    {}
  };

  template<class T,class Ref,class Ptr>
  struct __list_iterator
  {
    typedef list_node<T> node;
    typedef __list_iterator<T,T&,T*> self;

    node* _node;

    //构造函数
    __list_iterator(node* n)
      :_node(n)
    {}

    Ptr operator->()
    {
      return &_node->_data;
    }

    Ref operator*()
    {
      return _node->_data;
    }

    self& operator++()
    {
      _node = _node->_next;
      return *this;
    }

    //后置++
    self operator++(int)
    {
      self tmp(*this);
      _node = _node->_next;

      return tmp;
    }

    self& operator--()
    {
      _node = _node->_prev;
      return *this;
    }

    self operator--(int)
    {
      self tmp(*this);
      _node = _node->_prev;

      return tmp;
    }

    bool operator!=(const self& s)
    {
      return this->_node!=s._node;
    }

    bool operator==(const self& s)
    {
      return this->_node==s._node;
    }

  };

  template<class T>
  class list 
  {
      typedef list_node<T> node;
    public:
      typedef __list_iterator<T,T&,T*> iterator;
      typedef __list_iterator<T,const T&,const T*> const_iterator;

      void empty_init()
      {
        _head = new node;
        _head->_prev = _head;
        _head->_next = _head;
      }

      list()
      {
        empty_init();
      }

      template<class Iterator>
      list(class first,class last)
      {
        empty_init();

        while(first != last)
        {
          push_back(*first);
          ++first;
        }
      }

      void swap(list<T>& tmp)
      {
        std::swap(_head,tmp._head);
      }

      list(const list<T>& lt)
      {
        empty_init();

        list<T> tmp(lt.begin(),lt.end());
        swap(tmp);
      }

      list<T>& operator=(list<T> lt)
      {
        swap(lt);
        return *this;
      }

      void push_back(const T& x)
      {
        /*node* new_node = new node(x);
        node* tail = _head->_prev;
        
        tail->_next = new_node;
        new_node->_prev = tail;
        new_node->_next = _head;
        _head->_prev = new_node;*/ 

        insert(end(),x);
      }

      void push_front(const T& x)
      {
        insert(begin(),x);
      }
      iterator begin()
      {
        return iterator(_head->_next);
      }

      iterator end()
      {
        return iterator(_head);
      }

      const_iterator begin() const 
      {
        return const_iterator(_head->_next);
      }

      const_iterator end() const 
      {
        return const_iterator(_head);
      }


      void insert(iterator pos,const T& x)
      {
        node* new_node = new node(x);
        node* cur = pos._node;
        node* prev = cur->_prev;
        
        prev->_next = new_node;
        new_node = prev;
        new_node->_next = cur;
        cur->_prev = new_node;
      }

      void push_front(const T& x)
      {
        insert(begin(),x);
      }

      iterator erase(iterator pos)
      {
        assert(pos != end());

        node* cur = pos._node;
        node* prev = cur->_prev;
        node* next = cur->_next;

        prev->_next = next;
        next->_prev = prev;
        delete pos._node;

        return iterator(next);
      }

      void pop_back()
      {
        erase(--end());
      }

      void pop_front()
      {
        erase(begin());
      }

      void clear()
      {
        iterator it = begin();
        while(it!=end())
        {
          erase(*it);
          ++it;
        }
      }

      ~list()
      {
        clear();
        delete _head;
        _head = nullptr;
      }

    private:
      node* _haed;
  };

  void print_list(const list<int>& lt )
  {
    list<int>::const_iterator cit = lt.begin();
    while(cit != lt.end())
    {
      cout<<*cit<<" ";
      ++cit;
    }
    cout<<endl;
  }


  void test_list01()
  {
    list<int> lt;
    lt.push_back(1);
    lt.push_back(2);
    lt.push_back(3);
    lt.push_back(4);
    lt.push_back(5);

    list<int>::iterator it = lt.begin();
    while(it != lt.end())
    {
      cout<<*it<<" ";
      ++it;
    }
    cout<<endl;

    print_list(lt);
  }
}
