class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {

        int low =0;
        int high=letters.size()-1;
        int ans =0;

        while (low<=high){

            int mid =low +(high-low)/2;

            if (letters[mid] >target){
                high=mid-1;
                ans=mid;
            }
            else {
                low =mid +1;
            }

        }
        return letters[ans];
        
    }
};