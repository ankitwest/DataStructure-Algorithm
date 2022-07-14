// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    public:
    vector<int> smallestSubsegment(int a[], int n)
    {
    	unordered_map<int,int> m;
    	unordered_map<int,int> freq;
    	m[0] = -1;
    	freq[0] = 1;
    	
    	int max_len = 0; int max_freq = 0;
    	int start = 0; int end = 0;
    	
    	for(int i=0;i<n;i++){
    	    freq[a[i]]++;
    	    if(!m.count(a[i]))
    	     m[a[i]] = i;
    	    
    	    if(freq[a[i]] >= max_freq){
    	        if(freq[a[i]] == max_freq){
        	            if(max_len > i - m[a[i]]){
            	            max_len = i - m[a[i]];
                	        start = m[a[i]];
                	        end = i;
        	            }
    	        }else if(freq[a[i]] > max_freq){
    	            max_len = i - m[a[i]];
        	        max_freq = freq[a[i]];
        	        start = m[a[i]];
        	        end = i;
    	        }
    	    }
    	}
    	
    	vector<int> v;
    	for(int i=start;i<=end;i++)
    	    v.push_back(a[i]);
    	    
    	return v;
    }
};




