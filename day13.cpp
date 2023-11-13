class Solution {
public:
    std::vector<int> sortArray( std::vector<int>& nums )
    {
        quickSort( nums, 0, static_cast<int>( nums.size() ) - 1 );

        return nums;
    }
private:
    void quickSort( std::vector<int>& nums, int l, int r )
    {
        if( l >= r )
            return;

        swap_nums( nums[ l + rand() % ( r - l + 1 ) ], nums[ l ] );

        int mid{ partition( nums, l, r ) };
        quickSort( nums, l, mid - 1 );
        quickSort( nums, mid, r );
    }

    int partition( std::vector<int>& nums, int l, int r )
    {
        int pivot{ nums[ ( l + r ) / 2 ] };

        while( l <= r )
        {
            while( l <= r && nums[ l ] < pivot )
                ++l;

            while( l <= r && nums[ r ] > pivot )
                --r;

            if( l <= r )
                swap_nums( nums[ l++ ], nums[ r-- ] );
        }

        return l;
    }

    inline void swap_nums( int& num1, int& num2 )
    {
        int temp{ num1};
        
        num1 = num2;
        num2 = temp;
    }
};