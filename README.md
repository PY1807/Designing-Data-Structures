# Designing-Data-Structures
These small projects demonstrate my understanding in Data Structures and Algorithms.


MagicDictionary

I have designed a data structure that is initialized with a list of different words. When provided with a string, it determines if it is possible to change exactly one character in this string to match any word in the data structure.

I have implemented a MagicDictiionary class that has the following functions:

MagicDictionary(): Initializes the object(non-parametrised constructor).
void buildDict(vector<string> dictionary): Sets the data structure with an array of distinct strings dictionary.
pair<bool,string> search(String searchWord): Returns true and the string on which applying the conversion of changing only 1 character(then checking if it matches a word in the Dictionary), otherwise returns false and an empty string.

I have used an unordered_set data structure to implement this code.


MinStack
I have designed a stack that supports pushing and popping an element and retrieving the top element and minimum element.

I have created a MinStack class that has the following functions:

MinStack(): initializes the MinStack object(non-parametrised constructor).
void push(int val): pushes the element val onto the stack.
void pop(): removes the element on the top of the stack.
int top(): gets the top element of the stack.
int getMin(): retrieves the minimum element in the stack.

All these functions have a time complexity of O(1).







