
//min
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
            curr->next[bit] = new Trie();
        
        curr = curr->next[bit];
    }
}

int get(Trie* head,int val){
    int curr_xor = 0;
        Trie* curr = head;
        for(int i=31;i>=0;i--){
            int bit = (val>>i)&1;
            if(curr->next[bit])
                curr = curr->next[bit];
            else
                curr_xor |= 1<<i,curr = curr->next[!bit];
        }
        return curr_xor;
}

int findMaxXorPair(Trie* head,int arr[],int n);
class Solution{   
public:
    int minxorpair(int n, int arr[]){
        Trie* head = new Trie();
        
        int min_xor = INT_MAX;
        insert(head,arr[0]);
        for(int i=1;i<n;i++){
            int curr_xor = get(head,arr[i]);
            min_xor = min(min_xor,curr_xor);
            insert(head,arr[i]);
        }
        return min_xor;
    }
};










//max
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
            curr->next[bit] = new Trie();
        
        curr = curr->next[bit];
    }
}

int findMaxXorPair(Trie* head,int arr[],int n){
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
    int maxxorpair(int n, int arr[]){
        Trie* head = new Trie();
       
        to find max
         for(int i=0;i<n;i++){
            insert(head,arr[i]);
        }
        return findMaxXorPair(head,arr,n);
    }
};
