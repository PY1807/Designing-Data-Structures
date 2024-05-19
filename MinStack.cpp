#include<bits/stdc++.h>
using namespace std;
class MinStack {
public:
   vector< pair<int,int> > st; //make vector pair in which we will store curr value for returning the element at the top of the stack and minimum value to return the minimum till that point of the Stack
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()) {
            pair<int,int> p = make_pair(val, val);
            st.push_back(p);// I am inserting the value as it is if the Stack is empty
        }
        else{
            pair<int,int> p;
            p.first = val;
            p.second = min(val, st.back().second);//taking out the minimum value from the current top of the stack and then comparing it with current element 
            st.push_back(p);// after performing above comparison we are inserting it in the Stack
        }
    }
    
    void pop() {
      cout<<" Popping element from the MinStack "<<endl;
        st.pop_back();// Here we are popping the element at the top of the Stack
    }
    
    int top() {
        return st.back().first;//Returning element at the top of the Stack
    }
    
    int getMin() {
        return st.back().second;// Returning Minimum element of the Stack
    }
};


int main()
{
  char ch;
   MinStack* obj = new MinStack();
  cout<<"Do you want to enter the number ? y/n"<<endl;
  cin>>ch;
  while(ch=='y')
  {
    int value;
    cin>>value;
    obj->push(value);
    cout<<"Do you want to enter the number ? y/n"<<endl;
     cin>>ch;
  }
  
  obj->pop();
  cout<<"The element that is at the top of the Min Stack ="<<obj->top()<<endl<<endl;
  cout<<"The minimum element in the Min Stack = "<<obj->getMin()<<endl;
 }