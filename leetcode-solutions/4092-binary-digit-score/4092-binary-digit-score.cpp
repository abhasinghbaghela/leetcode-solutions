class Solution {
public:
    int setbits(int a){
        int t=a;
        int ans=0;
        while(t){
            if(t%2==1){
                ans++;
            }
            t=t/2;
        }
        return ans;
    }
    int calculateScore(int a, int b) {
        int s1=setbits(a);
        int s2=setbits(b);
        if(s1>=s2){
            return s1*s2;
        }else{
            return s2/s1;
        }
    }
};