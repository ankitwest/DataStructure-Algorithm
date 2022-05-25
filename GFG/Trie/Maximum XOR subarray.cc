

class Trie{
public:
    Trie* next[2];
    Trie(){
        next[0] = next[1] = NULL;
    }
};

void insert(Trie* head,int val){
    Trie* curr = head;
    for(int i=31;i>=0;i--){
        int bit = (val>>i)&1;
        if(!curr->next[bit])
            curr->next[bit] = new Trie;
        curr = curr->next[bit];
    }
}

int get(Trie* head,int val){
    Trie* curr = head;
    int curr_xor = 0;
    for(int i=31;i>=0;i--){
        int bit = (val>>i)&1;
        if(curr->next[1-bit])
            curr_xor |= 1<<i,
            curr = curr->next[1-bit];
        else if(curr->next[bit])
            curr = curr->next[bit];
    }
    return curr_xor;
}




class Solution{   
public:
    int maxSubarrayXOR(int n, int arr[]){    
        Trie* head = new Trie();
        int ans = 0 ; int prefixXor = 0;
        insert(head,0);
        for(int i=0;i<n;i++){
            prefixXor = prefixXor^arr[i];
            insert(head,prefixXor);
            ans = max(ans,get(head,prefixXor));
        }
        return ans;
    }
};






// M-2
class Trie{
public:
    Trie* next[2];
    Trie(){
        next[0] = next[1] = NULL;
    }
};

void insert(Trie* head,int val){
    Trie* curr = head;
    for(int i=31;i>=0;i--){
        int bit = (val>>i)&1;
        if(!curr->next[bit])
            curr->next[bit] = new Trie;
        curr = curr->next[bit];
    }
}

int findMaxXorSubarray(Trie* head,int arr[],int n){
    int max_xor = INT_MIN;
    for(int j=0;j<n;j++){
        int val = arr[j];
        int curr_xor = 0;
        Trie* curr = head;
        for(int i=31;i>=0;i--){
            int bit = (val>>i)&1;
            int oppo = !bit;
            if(curr->next[oppo])
                curr_xor |= 1<<i,curr = curr->next[oppo];
            else
                curr = curr->next[!oppo];
        }
        max_xor = max(max_xor,curr_xor);
    }
    return max_xor;
}

class Solution{   
public:
    int maxSubarrayXOR(int n, int arr[]){
        Trie* head = new Trie();
       int v[n+1] = {0};
       v[1] = arr[0];
       insert(head,v[0]);
         for(int i=1;i<n;i++){
             v[i+1] = v[i]^arr[i];
             insert(head,v[i]);
        }
        return findMaxXorSubarray(head,v,n+1);
    }
};





