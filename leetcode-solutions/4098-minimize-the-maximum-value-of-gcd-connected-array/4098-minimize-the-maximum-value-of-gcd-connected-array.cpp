class Solution {
public:
    long long minimumMaxValue(int n, int index, int value) {
        if(value == 1) return -1;
        int p = value;
        for(int i = 2; i * i <= value; i++) {
            if(value % i == 0) {
                p = i;
                break;
            }
        }
        long long left = index;
        long long right = n - index - 1;
        if(left > 0) {
            long long x = value - p - 2LL * (left - 1);
            if(x <= 0) return -1;
        }
        return value + (right > 0 ? p + 2LL * (right - 1) : 0);
    }
};