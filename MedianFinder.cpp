#include<bits/stdc++.h>
using namespace std;

class MedianFinder {
    int n;//keeps track of number of elements in the stream of numbers
    double median;
    // We are creating 2 heaps using priority queues
    //What we are doing to is that we are going to fill both heaps simultaneously so that either the number of elements are same in both heaps or one heap has 1 element more than the other !
    priority_queue<int> left;// This is a max-heap
    priority_queue<int, vector<int>, greater<int>> right;// This is a min-heap
// For even number of elements we are going to take top elements of both heaps and then calculate the median and for odd number of elements we are going to take the top of that heap that has 1 more element than the other.
    public:
    MedianFinder() {
        n = 0;
    }
    
    void addNum(int num) {
        
        if (!left.empty() && left.top() > num) {
            left.push(num);

            if (left.size() > right.size() + 1)
            //Adjusting the size of the heap(Max-heap) that has a size difference of more than 1 with the other heap
            {
                right.push(left.top()); left.pop();
            }

        }
        else {
            right.push(num);

            if (right.size() > left.size() + 1)
             //Adjusting the size of the heap(Min-heap) that has a size difference of more than 1 with the other heap
            {
                left.push(right.top()); right.pop();
            }
        }

        n++;        
    }
    
    double findMedian()
    
    {
        if (n & 1) {
            median = left.size() > right.size() ? left.top() : right.top();
        }
        else{
            median = left.top() + right.top();
            median /= 2;
        }
        return median;
    }
};

  
void Addition_Of_Data(MedianFinder* obj)
{
    cout<<"Enter the data(number) that you want to insert into the Stream press y for yes or n for no"<<endl;
  char ch;
  cin>>ch;
  
  while(ch=='y')
  {
      int value;
      cin>>value;
      obj->addNum(value);
      cout<<" Press y for yes or n for no"<<endl;
      cin>>ch;
  }
  cout<<"Data entered successfully !!!"<<endl<<endl;
}

  int main()
  {

   MedianFinder* obj = new MedianFinder();
  
   Addition_Of_Data( obj);
   
   double median = obj->findMedian();
   cout<<"The Median of the Data stream = "<<median<<endl;
  
  }
