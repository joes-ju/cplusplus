#include<iostream>
#include<vector>
using namespace std;

namespace joes
{
  template<class T,class Container>
  class stack 
  {
    public:
      void push(const T& x)
      {
        return _con.push_back(x);
      }

      void pop()
      {
        return _con.pop_back();
      }

      size_t size()
      {
        return _con.size();
      }

      T& top()
      {
        return _con.back();
      }

      bool empty()
      {
        return _con.empty();
      }
    private:
      Container _con;
  };

  void test_stack01()
  {
    joes::stack<int,std::vector<int>> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    cout<<"st's size: "<<st.size()<<endl;
    while(!st.empty())
    {
      cout<<st.top()<<" ";
      st.pop();
    }
    cout<<endl;


  }
}
