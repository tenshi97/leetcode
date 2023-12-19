#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        string str;
        for(int i=0;i<words.size();i++)
        {
            str+=words[i].at(0);
        }
        cout<<str<<endl;
        return str==s;
    }
};
int main(void)
{
    Solution s = Solution();
    int n;
    cin>>n;
    vector<string> input_words;
    string input_s;
    for(int i=1;i<=n;i++)
    {
        string str;
        cin>>str;
        input_words.push_back(str);
    }
    cin>>input_s;
    cout<<s.isAcronym(input_words,input_s)<<endl;
}