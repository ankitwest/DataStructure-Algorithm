class Solution {
    int n = 0;
    Node* construct(int pre[],int &start,int mini,int maxi){
        if(start >= n) return NULL;
        if(pre[start] < mini or pre[start] > maxi) return NULL;
        
        int val = pre[start++];
        Node* root = newNode(val);
        
        root->left = construct(pre,start,mini,val);
        root->right = construct(pre,start,val,maxi);
        
        return root;
    }
public:
    Node* post_order(int pre[], int size)
    {
        int start = 0; n = size;
        int mini = 0;int maxi = INT_MAX;
        return construct(pre,start,mini,maxi);
    }
};


use 
pass by refernce for start;



class Solution2 {
public:

unordered_map<int,int> m;    
    Node* construct(int pre[],int ind[],int &start,int inS,int inE){
        if(inS > inE) return NULL;
        
        int val = pre[start++];
        Node* root = newNode(val);
        
        if(inS == inE) return root;
        int mid = m[val];
        
        root->left = construct(pre,ind,start,inS,mid-1);
        root->right = construct(pre,ind,start,mid+1,inE);
        
        return root;
    }
    Node* post_order(int pre[], int size)
    {
       int n = size;
       int ind[n];
       for(int i=0;i<n;i++){
           ind[i] = pre[i];
       }
       sort(ind,ind+n);
       
       for(int i=0;i<n;i++) m[ind[i]] = i;
       int start = 0;
       return construct(pre,ind,start,0,n-1);
    }
};
