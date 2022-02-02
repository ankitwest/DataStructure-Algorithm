class Solution {
public:
    int minNumberOfFrogs(string str) {
        string s="croak"; int cnt[5]={0};
        int frog = 0,max_frog = 0;
        for(auto c:str){
            int pos = s.find(c);
            cnt[pos]++;
            if(pos==0){
                max_frog = max(max_frog,++frog);
            }else if(cnt[4]>cnt[3] or cnt[3]>cnt[2] or cnt[2]>cnt[1] or cnt[1]>cnt[0])
                return -1;
            else if(pos==4){
                --frog;
            }
        }
        return frog==0?max_frog:-1;
    }
};
