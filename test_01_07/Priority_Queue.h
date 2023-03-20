#pragma once
//#include"test.cpp"
//#ifndef __PRIORITY_QUEUE_H__
//#define __PRIORITY_QUEUE_H__ 

#include"Test.cpp"
namespace joes
{
  template<class T>
  struct less
  {
    bool operator()(const T& x,const T& y)
    {
      return x < y;
    }
  };

  template<class T>
  struct greater 
  {
    bool operator()(const T& x,const T& y)
    {
      return x > y;
    }
  };

  template<class T,class Container = vector<T>,class Compare = less<T>>
  class priority_queue
  {
    public:
      void adjust_up(size_t child)
      {
        Compare com;
        size_t parent = (child-1)/2;
        while(child > 0)
        {
          if(com(_con[parent],_con[child]))
          {
            swap(_con[parent],_con[child]);
            child = parent;
            parent = (child-1)/2;
          }
          else 
          {
            break;
          }
        }
      }

      void push(const T& x)
      {
        _con.push_back(x);
        adjust_up(_con.size()-1);
      }

      void adjust_down(size_t parent)
      {
        Compare com;

        size_t child = parent*2+1;
        while(child < _con.size())
        {
          if(com(child+1,_con.size())&&com(_con[child],_con[child+1]))
          {
            ++child;
          }

          if(com(_con[parent],_con[child]))
          {
            swap(_con[parent],_con[child]);
              parent = child;
              child = parent*2+1;
          }
          else 
          {
            break;
          }
        }
      }

      void pop()
      {
        swap(_con[0],_con[_con.size()-1]);
        _con.size()--;
        adjust_down(0);
      }

      size_t size()
      {
        return _con.size();
      }

      bool empty()
      {
        return _con.empty();
      }

      const T& top()
      {
        return _con[0];
      }

    private:
      Container _con;
  };

  void test_priority01()
  {
    priority_queue<int,vector<int>> pq;
    pq.push(1);
    pq.push(0);
    pq.push(5);
    pq.push(2);
    pq.push(1);
    pq.push(7);

    while(!pq.empty())
    {
      cout<<pq.top()<<" ";
      pq.pop();
    }
    cout<<endl;

  }
}
//#endif
