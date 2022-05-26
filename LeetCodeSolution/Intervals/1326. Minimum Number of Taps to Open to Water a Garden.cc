

class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
       for(int i=1;i<ranges.size();i++){
           if(ranges[i]==0) ranges[i] = i;
           else{
               int left = max(0,i-ranges[i]);
               ranges[left] = max(i+ranges[i],ranges[left]);
           }
       }
        for(int i=0;i<=n;i++) cout<<ranges[i]<<" "; cout<<endl;
        
        int maxIndex = 0; int pos = 0 ; int tap = 0;
        for(int i=0;i<n;i++){
            if(maxIndex<i) return -1;
            maxIndex = max(maxIndex,ranges[i]);
            if(i==pos){
                tap++;
                pos = maxIndex;
            }
        }
        return maxIndex>=n?tap:-1;
    }
};

class Solution2 {
public:
    int minTaps(int n, vector<int>& ranges) {
        int min=0; int max=0;
        int open=0;
        while(max<n){
            for(int i=0;i<ranges.size();i++)
                if(i-ranges[i]<=min and i+ranges[i]>max) 
                    max = i+ranges[i];
            
            if(min==max) 
                return -1;
            open++;
            min=max;
        }
        return open;
    }
};


// optimize

// class Solution3 {
// public:
//     int minTaps(int n, vector<int>& ranges) {
//         int min=0; int max=0;
//         int open=0; int index=0;
//         while(max<n){
//             for(int i=index;i<ranges.size();i++)
//                 if(i-ranges[i]<=min and i+ranges[i]>max) 
//                     max = i+ranges[i],index=i;
            
//             if(min==max) 
//                 return -1;
//             open++;
//             min=max;
//         }
//         return open;
//     }
// };
