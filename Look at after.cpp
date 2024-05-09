#include <bits/stdc++.h>
using namespace std;

set<vector<int>> allComb;

void func(vector<int>& curr, int target, int indx, int& size, vector<int>& candidates){
    if (indx == size){
        if (target == 0){
            sort(curr.begin(), curr.end());
            allComb.insert(curr);
        }
        return;
    }
    if (target >= candidates[indx]){
        curr.push_back(candidates[indx]);
        func(curr, target - candidates[indx], indx + 1, size, candidates);
        curr.pop_back();
    }
    func(curr, target, indx + 1, size, candidates);
}



int main(){
    vector<int> candidates = {2,5,2,1,2};
    int target = 5;
    int size = candidates.size();
    vector<int> curr;
    func(curr, target, 0, size, candidates);
    for (auto i: allComb){
        for (int j: i){
            cout << j << " ";
        }cout << endl;
    }
    
    
    return 0;
}
