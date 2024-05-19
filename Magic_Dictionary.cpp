#include <bits/stdc++.h>
using namespace std;
class MagicDictionary
{
public:
  unordered_set<string> st; // To keep track of all the unique words present in the Dictionary and a set is used beacuse searching in a set is very efficient
  MagicDictionary()
  {
    st.clear(); // clearing any data if present previously beacuse a new dictionary has to be created
  }

  void buildDict(vector<string> arr)
  {
    for (int i = 0; i < arr.size(); i++)
    {
      st.insert(arr[i]); // Inserting all the unique words in the set data structure
    }
  }

  pair<bool, string> search(string s)
  {
    for (int i = 0; i < s.length(); i++)
    {
      string temp = s;
      for (int k = 0; k < 26; k++)
      {
        char curr_char = char(k + 'a');
        if (curr_char != s[i])
        {
          temp[i] = curr_char;           // changing one of the characters of the word given by the user
          if (st.find(temp) != st.end()) // checking if there is a word that can be obtained from the dictionary just by changing one character of the given word
          {
            return {true, temp};
          }
        }
      }
    }
    return {false, " "}; // This means no word can be obtained like the given word from the dictionary.
  }
};

void Dictionary_Buliding(MagicDictionary *obj)
{
  vector<string> dictionary;
  cout << "Enter the words that you want to enter into the dictionary , type no when you want to stop entering words" << endl;
  string word;
  cin >> word;

  while (word != "no")
  {
    dictionary.push_back(word);
    cin >> word;
  }

  obj->buildDict(dictionary);

  cout << " Dictionary built successfully !!!" << endl
       << endl;
}

void ask_user_then_display(MagicDictionary *obj)
{
  string user_input;
  cout << "Enter the word that you want to check for the given condition :-" << endl;
  cin >> user_input;

  pair<bool, string> value_user_input = obj->search(user_input);
  if (!value_user_input.first)
  {
    cout << "The word cannot be built just by changing only one of the characters of any word already present in the Dictionary." << endl;
  }
  else
  {
    cout << "Yes, the word can be built just by changing only one of the characters of any word already present in the Dictionary and the word that was in the dictionary was =     " << value_user_input.second << endl;
  }
}

int main()
{
  MagicDictionary *obj = new MagicDictionary();

  Dictionary_Buliding(obj);

  ask_user_then_display(obj);
}