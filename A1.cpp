#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <sstream>
#include <algorithm>

using namespace std;

struct Recipe {
    vector<string> ingredients;
    int orbs_needed;
};

map<string, vector<Recipe>> recipes;
map<string, int> memo;
map<string, bool> is_potion;

int minOrbs(const string& potion) {
    if (memo.count(potion)) {
        return memo[potion];
    }

    if (!is_potion[potion]) {
        return 0;
    }

    int min_total_orbs = 1e9;

    for (const auto& recipe : recipes[potion]) {
        int current_recipe_orbs = 0;
        
        current_recipe_orbs += recipe.orbs_needed;

        for (const auto& ingredient : recipe.ingredients) {
            current_recipe_orbs += minOrbs(ingredient);
        }

        min_total_orbs = min(min_total_orbs, current_recipe_orbs);
    }

    return memo[potion] = min_total_orbs;
}

int main() {
    int N;
    cin >> N;
    cin.ignore();

    for (int i = 0; i < N; ++i) {
        string line;
        getline(cin, line);

        size_t eq_pos = line.find('=');
        string potion_name = line.substr(0, eq_pos);
        string ingredients_str = line.substr(eq_pos + 1);

        is_potion[potion_name] = true;

        stringstream ss(ingredients_str);
        string ingredient;
        Recipe current_recipe;
        current_recipe.orbs_needed = 0;

        while (getline(ss, ingredient, '+')) {
            current_recipe.ingredients.push_back(ingredient);
        }
        
        current_recipe.orbs_needed = current_recipe.ingredients.size() - 1;
        recipes[potion_name].push_back(current_recipe);
    }

    string target_potion;
    cin >> target_potion;

    cout << minOrbs(target_potion) << endl;

    return 0;
}