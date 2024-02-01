class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // step 1
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<pair<int,int>> v;
        for(int i=0;i<rows ;i++)
        {
            for(int j= 0 ;j<cols;j++)
            {
                if(matrix[i][j] == 0)
                {
                    pair<int,int> p = make_pair(i,j);
                    v.push_back(p);
                }
            }
        }
        for(int i=0;i<v.size();i++)
        {
            pair<int,int> p = v[i];
            int Row = p.first ;
            int Col = p.second;
            for(int j=0;j<cols;j++)
            {
                matrix[Row][j]= 0;
            }
            for(int k=0;k<rows;k++)
            {
                matrix[k][Col] = 0;
            }
        }
    }
};