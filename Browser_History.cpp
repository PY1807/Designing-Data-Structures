#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class BrowserHistory {
public:
    stack<string>history;//to manage websites when moving forward to visit an already visited website or when visiting a new website
    stack<string>future;//to manage websites when moving backwards to visit an already visited website
    BrowserHistory(string homepage) {
        history.push(homepage);
        future=stack<string>();
    }
    
    void visit(string url) {
        history.push(url);
        future=stack<string>();
    }
    
    string back(int steps) {
        while(steps>0 && history.size()>1)
        //history.size()>1 because a website is definitely returned even if number of steps exceeds that of the number of websites
        {
            future.push(history.top());//adding them for future if we move forward from a website
            history.pop();//going backwards
            steps--;
        }
        return history.top();
    }
    
    string forward(int steps) {
        while(steps>0 && future.size()>0)
        {
            history.push(future.top());//removing from future
            future.pop();//and putting it back in current feed
            steps--;
        }
        return history.top();
    }
};
 void visit_planner( BrowserHistory* obj)
 {
     string site_to_visit;
     cout<<"Enter the site that you want to visit next , enter 'no' when you do not want to enter"<<endl;
     cin>>site_to_visit;
     while(site_to_visit!="no")
     {
         obj->visit(site_to_visit);
         cin>>site_to_visit;
     }
     
 }
 void back_steps(BrowserHistory* obj)
 {
     int steps;
     cout<<"Enter the number of steps you want to move back from the current website."<<endl;
     cin>>steps;
     cout<<"You reached "<<obj->back(steps)<<" !!!"<<endl;
 }
 void forward_steps(BrowserHistory* obj)
 {
     int steps;
     cout<<"Enter the number of steps you want to move forward from the current website."<<endl;
     cin>>steps;
     cout<<"You reached "<<obj->forward(steps)<<" !!!"<<endl;
 }
 
 int main()
 {
  string homepage;
  cout<<"Enter the Homepage that you would visit at the start"<<endl;
  cin>>homepage;
  
  BrowserHistory* obj = new BrowserHistory(homepage);
  
  char ch;
  cout<<"Enter v to visit a website, b to move back from a website and f to move forward from a website and n if you do not want to do anything."<<endl;
  cin>>ch;
  while(ch!='n')
  {
      if(ch=='v')
      {
          visit_planner(obj);
      }
      else if(ch=='b')
      {
          back_steps(obj);
      }
      else if(ch=='f')
      {
           forward_steps(obj);
      }
      else
      {
          cout<<"Invalid choice !!! Try Again"<<endl;
      }
      cin>>ch;
  }
  
  
 }
