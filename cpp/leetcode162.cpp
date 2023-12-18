#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int isPeak(vector<int>& v,int pos)
    {
        if(pos==0)
        {
            return v[pos]>v[pos+1]?pos:-1;
        }
        if(pos==v.size()-1)
        {
            return v[pos]>v[pos-1]?pos:-1;
        }
        return (v[pos]>v[pos+1]&&v[pos]>v[pos-1])?pos:-1;

    }
    int solve(vector<int>& v,int st,int ed)
    {
        int mid = (st+ed)/2;
        int peakpos = isPeak(v,mid);
        int ans;
        if(peakpos!=-1)
        {
            return peakpos;
        }
        else
        {
            if(st!=ed)
            {
                ans = solve(v,st,mid);
                if(ans==-1)
                {
                    ans = solve(v,mid+1,ed);
                }
                return ans;
            }
            else
            {
                return -1;
            }
        }
    }
    int findPeakElement(vector<int>& nums) {
        int start = 0;
        int end = nums.size()-1;
        if(nums.size()==1)  return 0;
        return solve(nums,start,end);
    }
};
int main(void)
{
    Solution s = Solution();
    vector<int> test = {1};
    cout<<s.findPeakElement(test)<<endl;
    return 0;
}