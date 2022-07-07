class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size(); int cnt = 0;
        vector<int> pre(n+1,0),suff(n+1,0);
        for(int i=0;i<n;i++)
        {
            if(s[i]=='1') cnt++;
                pre[i+1] = cnt;
        }
        cnt=0;
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]=='0') cnt++;
                suff[i] = cnt;
        }
        
        int mini = INT_MAX;
        for(int i=0;i<=n;i++)
        {
            mini = min(mini, pre[i] + suff[i]);
        }   
        return mini;
    }
};


class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size(); 
        int flips = 0;int counter = 0;
        for(int i=0;i<n;i++){
            if(s[i]=='1') counter++;
            else flips++;
            
            flips = min(flips, counter);
        }
        return flips;
    }
};

/*
This is simple dynamic programming.
We loop through the string.
If we got a 1, go on. No need to flip. We just increment the 1 counter.
If we got a 0, we increment the flips counter.
Now, we have two options. Either to flip the new zero to one or to flip all previous ones to zeros.
So we take the min between flips and counter.
*/



/*
"10011111110010111011"
"0101100011"
*/
