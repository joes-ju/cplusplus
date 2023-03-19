#include<iostream>
#include<stack>
#include<vector>
#include<string>
using namespace std;

namespace joes{
 class solution
 {
   public:
     int evalRPN(vector<string>& tokens)
     {
       std::stack<int> st;
       for(auto& str : tokens)
       {
         if(str=="+"||str=="-"||str=="*"||str=="/")
         {
           int right = st.top();
           st.pop();
           int left = st.top();
           st.pop();
           switch(str[0])
           {
             case '+':
               st.push(left+right);
               break;
             case '-':
               st.push(left-right);
               break;
             case '*':
               st.push(left * right);
               break;
             case '/':
               st.push(left / right);
               break;
           }
         }
         else 
         {
           st.push(stoi(str));
         }
       }
       return st.top();
     }

 };

  void test_solution(){
    vector<string> tokens;
    tokens.push_back("1");
    tokens.push_back("2");
    tokens.push_back("3");
    tokens.push_back("*");
    tokens.push_back("+");
    tokens.push_back("4");
    tokens.push_back("-");

    solution s1;
    cout<<(s1.evalRPN(tokens))<<endl;
  }

}
