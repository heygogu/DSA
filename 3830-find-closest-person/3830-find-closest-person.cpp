class Solution {
public:
    int findClosest(int x, int y, int z) {
        int first=abs(z-x);
        int second=abs(z-y);

        // if(first<second){
        //     return 1;
        // }
        // else if(second<first){
        //     return 2;
        // }else{
        //     return 0;
        // }

        return (first<second) ? 1 : (second<first) ? 2 : 0 ;

        // return -1;
    }
};