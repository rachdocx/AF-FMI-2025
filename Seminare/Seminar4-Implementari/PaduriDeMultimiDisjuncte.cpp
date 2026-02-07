#include <iostream>
#include <fstream>
using namespace std;
class Solution {
public:
    static int lengthOfLIS(vector<int>& nums) {
        vector<int> sol(10005, 0);
        sol[nums[(int)nums.size() - 1]] = 1;
        for(int i = (int)nums.size() - 1; i >= 0; --i){
            for(int j = i - 1; j >= 0; --j){
                if(nums[i] > nums[j]){
                    sol[i] = max(sol[i] + 1, sol[j]);
                }

            }
        }
        int ma = - 10005;
        for(auto x : sol){
            if(x > ma)
                ma= x;
        }
        for (auto x:sol)
            cout<<x<<" ";
        return ma;
    }
};
int main() {
    Solution o;
    vector<int> nums ={10,9,2,5,3,7,101,18};
    o.lengthOfLIS(nums);
    return 0;
}
