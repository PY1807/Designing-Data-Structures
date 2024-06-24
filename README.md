# Designing-Data-Structures
These small projects demonstrate my understanding in Data Structures and Algorithms.


1)MagicDictionary

I have designed a data structure that is initialized with a list of different words. When provided with a string, it determines if it is possible to change exactly one character in this string to match any word in the data structure.

I have implemented a MagicDictiionary class that has the following functions:

MagicDictionary(): Initializes the object(non-parametrised constructor).
void buildDict(vector<string> dictionary): Sets the data structure with an array of distinct strings dictionary.
pair<bool,string> search(String searchWord): Returns true and the string on which applying the conversion of changing only 1 character(then checking if it matches a word in the Dictionary), otherwise returns false and an empty string.

I have used an unordered_set data structure to implement this code.


2)MinStack
I have designed a stack that supports pushing and popping an element and retrieving the top element and minimum element.

I have created a MinStack class that has the following functions:

MinStack(): initializes the MinStack object(non-parametrised constructor).
void push(int val): pushes the element val onto the stack.
void pop(): removes the element on the top of the stack.
int top(): gets the top element of the stack.
int getMin(): retrieves the minimum element in the stack.

All these functions have a time complexity of O(1).

3)UndergroundSystem

An underground railway system keeps track of customer travel times between different stations. They use this data to calculate the average time it takes to travel from one station to another.

I have implemented an UndergroundSystem 
class.
UndergroundSystem()  A constructor is also present though it does not initialize anything. It just behaves like a default constructor.

void checkIn(int id, string stationName, int t)
A customer with a card ID equal to id, checks in at the station stationName at time t.
A customer can only be checked into one place at a time.

void checkOut(int id, string stationName, int t)
A customer with a card ID equal to id, checks out from the station stationName at time t.

double getAverageTime(string startStation, string endStation)
Returns the average time it takes to travel from startStation to endStation.

Process of Calculation of Average Time:
The average time is computed from all the previous traveling times from startStation to endStation that happened directly, meaning a check in at startStation followed by a check out from endStation.
The time it takes to travel from startStation to endStation may be different from the time it takes to travel from endStation to startStation.

4)Twitter

Here I have designed a Twitter like App where users can post tweets, follow/unfollow another user, and is able to see the 5 most recent tweets in the user's news feed.

I have implemented a Twitter Class:

Twitter(): Initializes your twitter object (Non-parametrised Constructor).

void postTweet(int userId, int tweetId) Composes a new tweet by the user userId. Each call to this function will be made with a unique tweet.
vector<string> getNewsFeed(int userId): Retrieves the 5 most recent tweets in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user themself. Tweets are ordered here from most recent to least recent.

void follow(int followerId, int followeeId) The user with ID followerId started following the user with ID followeeId.

void unfollow(int followerId, int followeeId) The user with ID followerId started unfollowing the user with ID followeeId.

I have used a Linked List to store all tweets where the class 'Tweet' has attributes like user_id,tweet and pointer to the next Tweet.

There is a map to store all the followee's ids of the people that a follower is following (follower id acts as the key here in the map).

5)Food Ratings

I have designed a food rating system that performs a lot of tasks:

Modifes the rating of a food item listed in the system.
Returns the highest-rated food item for a type of cuisine in the system.

Here I have implemented a FoodRatings Class:

FoodRatings(vector<string> foods, vector<string> cuisines, vector<int> ratings): Initializes the system. The food items are described by foods, cuisines and ratings, all of which have a length of n.

foods[i] is the name of the ith food,
cuisines[i] is the type of cuisine of the ith food, and
ratings[i] is the initial rating of the ith food.

void changeRating(String food, int newRating): Changes the rating of the food item with the name food.
String highestRated(String cuisine): Returns the name of the food item that has the highest rating for the given type of cuisine. If there is a tie, the item comes first in alphabetical order is returned.

Basic Overview:
Here I am using 3 maps, first one stores the cuisine with their fooditems and their ratings, second one stores the food-cuisine pairs and the third one stores the food-rating pairs.
In the set<pair<int,string>> of the first map, we store the negative value of the rating in the map because set data structure sorts in increasing order but we want the highest rated food, so we perform the specified operation as stated above.

6)Browser History

I have designed a browser of one tab where I am starting on the homepage and then we can visit another url, get back in the history number of steps or move forward in the history number of steps.

I have implemented a BrowserHistory class:

BrowserHistory(string homepage) Initializes the object with the homepage of the browser.
void visit(string url) Visits url from the current page. It wil clear up all the forward history.
string back(int steps) Move steps back in history. If steps > x, we will return the oldest url that we visited.
string forward(int steps) Move steps forward in history. If  steps > x, we will return the url that we had visited most recently.

Here,I have used 2 stacks one that maintains the track of urls that we visit and the other one for keeping track of the urls visited when we are going back to previous urls for the purpose of forwarding(that is when we want to move forward from some url that was visited in the past) .

7)Median Finder

I have designed a data structure that can find the median in a running stream.

I have implemented a MedianFinder class:

MedianFinder(): It just initializes number of elements in stream as 0
void addNum(int num): Here the new number in the stream is added.
double findMedian():It finds the median of the numbers arrived till that moment in the stream.

I have used 2 heaps- one is a max-heap and the other is a min-heap to find out the median.
