class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
       long xorr = 0;

       for(auto& it:nums) xorr^=it;

       xorr=xorr^(xorr-1&xorr);

        //I know that there is atleast one bit that is different among two unique numbers 
        // Otherwise they would have been same and have cancelled out
        // suppose the numbers were 14 and 4
        // 14-> 1110
        // 4 -> 0100
        // Final XOR 1010 (as all other cancel out)
        // Either of the set bits are different -> lets choose the righmost one

        // how would I differentiate these two numbers now ? 
        // 1110 & 1010 -> 1010 
        // 0100 & 1010 -> 0000 
        //seems like ok that one can become zero and other is not 0 .
        // but dry run on 1st test case and 5 and 3 both will be non zero

        //What if I get something where if I keep just one set bit intact then I can differentiate between them by comparing on that bit only.

        /*
            That is why I am choosing the rightmost bit only i.e if xorr is 1010 then the last set bit 1 is the position 
            using which I will compare 
            0100 & 0010 -> 0000
            1110 & 0010 -> 0010 
              ^ this bit was different
            
            Now, If I do xorr with every number in nums with 0010 then I know the distinct ones will be different .
            So we put them in separate groups 

            Any other number which results in 0000 or non zero by doing xor with xorr will be filtered accordingly.
            Same result ones will go in same pile (as they repeat) and non repeating are definitely in separate buckets

            QUESTION how to get this 0010 , or say target last set bit

            1010 is the XORR of distinct ones I need 0010 
            1010 ^ 1010 is 0000 
                             ^ need 1 here
            I need 1010 ^ 1000   (****)

            1010 -> 1000 
            if 1010 is n then 1001 is definitely n-1 as per binary rules
            1010 & 1001 => 1000  now look at the **** line above

            xorr & (xorr-1) = 1000 
            xorr ^ 1000 = 0010 which is required -> from **** line

            XORR^(XORR&(XORR-1)) will give us 0010. 

        */

        int b1=0;
        int b2=0;

        for(auto& it:nums){
            if(xorr & it){
                b1^=it;
            }else{
                b2^=it;
            }
        } 

        return {b1,b2};

    }
};