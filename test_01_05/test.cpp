#include<iostream>
#include<stack>

using namespace std;

void test_stack03()
{
  stack<int> st;
  st.push(11);
  st.push(22);
  st.push(33);
  st.push(44);
  st.push(55);

  cout<<"stack is empty?"<<st.empty()<<endl;
  while(!st.empty())
  {
    cout<<st.top()<<" ";
    st.pop();
  }
  cout<<endl;

  cout<<"stack's size is:"<<st.size()<<endl;
  st.push(11);
  st.emplace(2211010);
  st.emplace(20198180);
  while(!st.empty())
  {
    cout<<st.top()<<" ";
    st.pop();
  }
  cout<<endl;
}

int main()
{
  test_stack03();
  return 0;
}
