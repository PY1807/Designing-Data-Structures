#include<bits/stdc++.h>
using namespace std;
class FoodRatings {
    
public:
    
    unordered_map<string,set<pair<int,string>>>cuisineRatings;//This mapping stores cuisine to a pair of rating and the food item
    unordered_map<string,string>foodtocuisine;//This mapping stores food-cuisine pairs
    unordered_map<string,int> foodRatings;//This mapping stores the food-rating pairs
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i=0;i<foods.size();i++)
        {
            cuisineRatings[cuisines[i]].insert({-ratings[i],foods[i]});
            foodtocuisine[foods[i]]=cuisines[i];
            foodRatings[foods[i]]=ratings[i];//preparartion of all mappings
        }
    }
    
    void changeRating(string food, int newRating) {
       int oldRating=foodRatings[food];
       string cuisine=foodtocuisine[food];
       cuisineRatings[cuisine].erase({-oldRating,food});//deleting the old mapping that had the old rating
       cuisineRatings[cuisine].insert({-newRating,food});//updating and inserting it with the newRating
       foodRatings[food]=newRating;
    }
    
    string highestRated(string cuisine) {
        return (*cuisineRatings[cuisine].begin()).second;
    }
};
void change_Rating(FoodRatings* obj)
{
    string food;
    int rating;
    cout<<"Enter the food and its updated rating, enter 'N' when you do not want to enter "<<endl;
    while(food!="N")
    {
    obj->changeRating(food,rating);
    cin>>food>>rating;
    }
}
void highest_Rated(FoodRatings* obj)
{
    string cuisine;
    cout<<"Enter the cuisine for which you want to know about the highest rated food"<<endl;
    cin>>cuisine;
    cout<<"The highest rated food in the "<<cuisine<<" = "<<obj->highestRated(cuisine)<<endl;
}
int main()
{
    vector<string> foods, cuisines;
    vector<int> ratings;
    string food,cuisine;
    int rating;
    cout<<"Enter the food , its corresponding cuisine and rating of the food,enter 'N' in food when you do not want to enter anything."<<endl;
    cin>>food>>cuisine>>rating;
    while(food!="N")
    {
        foods.push_back(food);
        cuisines.push_back(cuisine);
        ratings.push_back(rating);
        cin>>food>>cuisine>>rating;
    }
    
    cout<<"List of food,cuisine with their corresponding ratings prepared successfully!!"<<endl<<endl;
    
  FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
  change_Rating(obj);
  highest_Rated(obj);
}
