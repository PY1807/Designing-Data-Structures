#include<bits/stdc++.h>
#include<iostream>
using namespace std;
class Tweet {
public:
    int userId;
    string tweet;
    Tweet* next;//stores the next tweet in the Feed(Containing tweets for all users ,not a single user)
    Tweet(int userId, string tweet) {
        this->userId = userId;
        this->tweet = tweet;
        this->next = NULL;
    }
};
class Twitter {
    map<int, set<int>> f;// This will store the mapping of follower's id and followee's id
    Tweet* head = NULL;
    Tweet* tail = NULL;

public:
    Twitter() {}

    void postTweet(int userId, string tweet) {
        if (this->head == NULL)
        //if there is no tweet in the feed till now
        {
            this->head = this->tail = new Tweet(userId, tweet);
        } else {
            Tweet* newTweet = new Tweet(userId, tweet);
            newTweet->next = head;//Updating pointers
            head = newTweet;//The newest tweet is added at the beginning that is at the head of the Linked List
        }
    }

    vector<string> getNewsFeed(int userId) {
        Tweet* temp = this->head;
        vector<string> ans;
        int count = 10;
        while (count && temp)
        //checks if the most recent 5 tweets are covered and also checks if there are enough tweets in the field to check
        {
            if (f[userId].count(temp->userId) != 0 || temp->userId == userId) 
            // If user_id is equal to the user_id user demands for or if the user follows someone then that tweet would also appear in his/her feed
            {
                count--;
                ans.push_back(temp->tweet);
            }
            temp = temp->next;
        }
        return ans;
    }

    void follow(int followerId, int followeeId) {
        f[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        f[followerId].erase(followeeId);
    }
};
   void Preparation_Of_Feed(Twitter* obj)
{
    cout<<"Enter the user_id and twitter_id that you want to insert into the Feed .Press y for yes or n for no"<<endl;
  char ch;
  cin>>ch;
  
  while(ch=='y')
  {
      int user_id;
      string tweet;
      cin>>user_id>>tweet;
      obj->postTweet(user_id,tweet);
      cout<<" Press y for yes or n for no"<<endl;
      cin>>ch;
  }
  
  cout<<"Feed Prepared Successfully!!!"<<endl<<endl;
}

void Display_Feed_Of_user(Twitter* obj)
{
      int user_input;
      cout<<"Enter the user_id of the user whose feed you want to access :-"<<endl;
  cin>>user_input;
  
  vector<string> ans=obj->getNewsFeed(user_input);
 cout<<"Feed of User "<<user_input<<" : "<<endl;
 for(auto it:ans)
 {
     cout<<it<<endl;
 }
 
}

void follow_unfollow(Twitter* obj,bool flag)
{
    int follower_id,followee_id;
    if(flag)
    {
        cout<<"Enter the follower's id and followee's id for the purpose of Following"<<endl;
        cin>>follower_id>>followee_id;
        obj->follow(follower_id,followee_id);
    }
    else
    {
        cout<<"Enter the follower's id and followee's id for the purpose of Unfollowing"<<endl;
        cin>>follower_id>>followee_id;
        obj->unfollow(follower_id,followee_id);
    }
}


  int main()
  {
      Twitter* obj = new Twitter();
      
      Preparation_Of_Feed( obj);
      
      follow_unfollow( obj,true);
      
      Display_Feed_Of_user( obj);
       
       follow_unfollow( obj,false);
       
       Display_Feed_Of_user( obj);
  }
