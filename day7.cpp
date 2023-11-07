class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=n;
        for(int i =0;i<n-1;i++)
        {
            for(int j=i+1;j<m;j++)
            {
                int temp=matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i]=temp;
            }
        }
        for(int i=0;i<m/2;i++)
        {
            for(int j=0;j<n;j++)
            {
                int temp=matrix[j][i];
                matrix[j][i]=matrix[j][m-i-1];
                matrix[j][m-i-1]=temp;
            }
        }
    }
};