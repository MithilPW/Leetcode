struct Cmp {
    bool operator()(const pair<int,string>& a, const pair<int,string>& b) const {
        if (a.first != b.first) return a.first > b.first; // higher rating first
        return a.second < b.second; // lexicographically smaller
    }
};

class FoodRatings {
public:
    // food -> {cuisine, rating}
    unordered_map<string, pair<string, int>> foodMap;
    
    // cuisine -> set of {rating, food} with custom comparator
    unordered_map<string, set<pair<int,string>, Cmp>> cuisineMap;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); i++) {
            string food = foods[i];
            string cuisine = cuisines[i];
            int rating = ratings[i];

            foodMap[food] = {cuisine, rating};
            cuisineMap[cuisine].insert({rating, food}); // no need for emplace anymore
        }
    }
    
    void changeRating(string food, int newRating) {
        auto& [cuisine, oldRating] = foodMap[food];
        
        cuisineMap[cuisine].erase({oldRating, food});
        foodMap[food].second = newRating;
        cuisineMap[cuisine].insert({newRating, food});
    }
    
    string highestRated(string cuisine) {
        return cuisineMap[cuisine].begin()->second;
    }
};
