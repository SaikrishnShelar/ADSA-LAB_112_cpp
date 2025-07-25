#include<iostream>
#include<vector>
using namespace std;
int count(vector<int>  &arr){
	int low=0;
	int high= arr.size()-1;
	int index =-1;
	while(low<=high){
	 	int mid = (high + low)/2;
	 	
	 	if (arr[mid]==0){
	 		index= mid;
	 	high=mid -1;
	 	}else{
	 	
	 	low = mid+1;
	}
	}
	 
	 if(index==-1){
	 	return 0;
	 }
	 
	  return arr.size() - index;
}
	



int main(){
	vector<int> arr={1,1,1,0,0,0,0,0};
	int c=count(arr);
	cout<<"no. of zero's is "<<c;
}
