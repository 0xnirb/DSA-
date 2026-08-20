class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {

        vector<int>arr1;
        vector<int>arr2;

        int n=nums.size();
        

        

        for (int i=0;i<n;i++){

            if(i==0){

                arr1.push_back(nums[i]);
               
            }
            else if(i==1){
                 arr2.push_back(nums[i]);
            }
            else if ( arr1.back()>arr2.back()){

                arr1.push_back(nums[i]);
            }
             else {

                arr2.push_back(nums[i]);
            }


        
            

           
             



            
        }
        vector<int> result = arr1;
         result.insert(result.end(), arr2.begin(), arr2.end());

           

         return result;
 
        
    }
};