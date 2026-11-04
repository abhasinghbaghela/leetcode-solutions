class Solution {
public:
    int convert(string date){
        vector<int>days={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int month=stoi(date.substr(0,2));
        int day=stoi(date.substr(3,2));
        for(int i=0;i<month-1;i++){
            day+=days[i];
        }
        return day;
    }
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int aa=convert(arriveAlice);
        int al=convert(leaveAlice);
        int bl=convert(leaveBob);
        int ba=convert(arriveBob);
        int arr=max(aa,ba);
        int lev=min(al,bl);
        if(arr>lev){
            return 0;
        }else{
            return lev-arr+1;
        }
    }
};