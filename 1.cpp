#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int>nums={1, 1, 1, 1,0,0};
    int low=0,high=nums.size()-1,mid;
    if(nums[nums.size()-1]==1)
    {
        cout<<"No.of 0's : 0"<<endl;
    }else if(nums[0]==0){
        cout<<"No.of 0's : "<<nums.size();
    }else{
        while(low<=high)
        {
            mid=(low+high)/2;
            if(nums[mid]==0)
            {
                if(nums[mid-1]==1)
                {
                    break;
                }else{
                    high=mid;
                }
            }else{
                if(nums[mid+1]==0)
                {
                    mid=mid+1;
                    break;
                }else{
                    low=mid;
                }
            }
        }
        cout<<"No.of 0's : "<<nums.size()-mid<<endl;
        
    }
}
