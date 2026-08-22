class Solution {
public:
    bool checkDivisibility(int n) {

        int original=n;
        int sum=0;
        int product=1;

        while (n!=0){

            sum=sum+(n%10);
            product=product*(n%10);
            n=n/10;

        }
        int S=sum +product;
        if (original%S==0){
            return 1;

        }
        else{
            return 0;
        }
    }
};