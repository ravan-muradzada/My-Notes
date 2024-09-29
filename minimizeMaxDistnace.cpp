#include <bits/stdc++.h>
using namespace std;

double minimiseMaxDistance(vector<int> &arr, int k){
    int n = arr.size();
    vector<int> countOfSections(n-1, 0);
    
    for (int i = 1; i <= k; ++i){
        double maxSection = -1;
        int maxSectionIndx = -1;
        
        for (int j = 0; j < n-1; ++j){
            double currDistance = arr[j+1] - arr[j];
            double currSectionDistance = currDistance / (1 + countOfSections[j]);
            
            if (currSectionDistance > maxSection){
                maxSection = currSectionDistance;
                maxSectionIndx = j;
            }
        }
        
        countOfSections[maxSectionIndx]++;
    }
    
    
    double maxSection = -1;
    
    for (int i = 0; i < n-1; ++i){
        double currDistance = (double)(arr[i+1] - arr[i]);
        double currSection = currDistance / (1 + countOfSections[i]);
        maxSection = max(maxSection, currSection);
    }
    
    return maxSection;
}


int main(){
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 4;
    long double ans = minimiseMaxDistance(arr, k);
    cout << "The answer is: " << ans << "\n";
    
    
    
    return 0;
}
