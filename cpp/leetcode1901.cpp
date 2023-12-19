#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int findMaxinColumn(vector<vector<int>>& mat,int column)
    {
        int Max_Pos = 0;
        int Max_Num = -1;
        for(int i=0;i<mat[column].size();i++)
        {
            if(mat[column][i]>Max_Num)
            {
                Max_Num = mat[column][i];
                Max_Pos = i;
            }
        }
        return Max_Pos;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int st_column,ed_column,mid_column;
        st_column = 0;
        ed_column = mat.size()-1;
        int peak_prev,peak_next,peak,peak_pos;
        vector<int> ans={0,0};
        while(true)
        {
            mid_column = (st_column+ed_column)/2;
            peak_prev = 0;
            peak_next = 0;
            peak_pos = findMaxinColumn(mat,mid_column);
            peak = mat[mid_column][peak_pos];
            if(mid_column==0)
            {
                peak_prev = -1;
                
            }
            if(mid_column==mat.size()-1)
            {
                peak_next = -1;
            }
            if(peak_prev!=-1)
            {
                peak_prev = mat[mid_column-1][peak_pos];
            }
            if(peak_next!=-1)
            {
                peak_next = mat[mid_column+1][peak_pos];
            }
            if(peak<peak_prev)
            {
                ed_column-=1;
                continue;
            }
            if(peak<peak_next)
            {
                st_column+=1;
                continue;
            }
            ans[0]=mid_column;
            ans[1]=peak_pos;
            return ans;
        }
        return ans;
    }
};
int main(void)
{
    int n,m;
    int num;
    cin>>n>>m;
    vector<int> column;
    vector<vector<int>> matrix;
    vector<int> ans;
    for(int i=1;i<=n;i++)
    {
        column.clear();
        for(int j=1;j<=m;j++)
        {
            cin>>num;
            column.push_back(num);
        }
        matrix.push_back(column);
    }
    Solution s = Solution();
    ans = s.findPeakGrid(matrix);
    cout<<ans[0]<<" "<<ans[1]<<endl;
}