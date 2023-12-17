#include <iostream>
#include <string.h>
using namespace std;
class Solution {
public:
    bool bucket[256];
    int maxans = 0;
    int lengthOfLongestSubstring(string s) {
        clearbucket();
        if(s.length()==0)   return 0;
        for(int i=0;i<s.length();i++)
        {
            int ans = 0;
            for(int j=i;j<s.length();j++)
            {
                if(!bucket[s[j]])
                {
                    ans++;
                    bucket[s[j]]=true;
                    if(j==s.length()-1)
                    {
                        clearbucket();
                        if(ans>maxans)
                        {
                            maxans=ans;
                        }
                    }
                }
                else
                {
                    clearbucket();
                    if(ans>maxans)
                    {
                        maxans=ans;
                    }
                    break;
                }
            }
        }
        return maxans;
    }
    void clearbucket()
    {
        memset(bucket,false,sizeof(bucket));
    }
};
int main(void)
{
    Solution a = Solution();
    cout<<a.lengthOfLongestSubstring("au")<<endl;
}