class Solution {
public:
    bool cook(const string& food, unordered_map<string, vector<string>>& food_ingredients, unordered_set<string>& haved, unordered_map<string, bool>& food_visited) {
        if (haved.count(food)) {
            return true;
        }
        if (food_ingredients.count(food) == 0 || (food_ingredients.count(food) && food_visited[food])) {
            return false;
        }
        food_visited[food] = true;

        bool cancook = true;
        for (string& ingredient : food_ingredients[food]) {
            cancook &= (haved.count(ingredient) || cook(ingredient, food_ingredients, haved, food_visited));
        }
        if (cancook) {
            haved.insert(food);
        }
        return cancook;
    }
    vector<string> findAllRecipes(vector<string> recipes, vector<vector<string>> ingredients, vector<string> supplies) {
        unordered_map<string, vector<string>>food_ingredients;
        unordered_map<string, bool>food_visited;
        for (int i = 0; i < recipes.size(); ++i) {
            food_ingredients[recipes[i]] = ingredients[i];
            food_visited[recipes[i]] = false;
        }
        unordered_set<string>sup(supplies.begin(), supplies.end());
        vector<string>ret;
        for (string& food : recipes) {
            bool cancook = true;
            for (string& need : food_ingredients[food]) {
                if ((cancook &= (sup.count(need) || cook(need, food_ingredients, sup, food_visited))) == false) {
                    break;
                }
            }
            if (cancook) {
                ret.push_back(food);
            }
        }
        return ret;
    }
};

