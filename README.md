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






