class Solution{
unordered_map<int,int>m;
    Node* build(int in[],int pre[],int &start,int inS,int inE){
        if(inS>inE) return NULL;
        Node* root = new Node(pre[start++]);
        if (inS==inE)  return root;
           
        int mid = m[root->data];
        
        root->left = build(in,pre,start,inS,mid-1);
        root->right = build(in,pre,start,mid+1,inE);
        
        return root;
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        m.clear();
        for(int i=0;i<n;i++) m[in[i]]=i;
        int start=0; 
        Node* root = build(in,pre,start,0,n-1);
        return root;
    }
};

// class Solution{
//     int search(int in[],int inS,int inE,int x){
//         for(int i=inS;i<=inE;i++){
//             if(in[i]==x) return i;
//         }
//     }
// Node* build(int in[],int pre[],int &start,int inS,int inE){
//         if(inS>inE) return NULL;
//         Node* root = new Node(pre[start++]);
//         if (inS==inE)  return root;
           
//         int mid = search(in,inS,inE,root->data); 
        
//         root->left = build(in,pre,start,inS,mid-1);
//         root->right = build(in,pre,start,mid+1,inE);
        
//         return root;
//     }
//  Node* buildTree(int in[],int pre[], int n)
//     {
//         int start=0; 
//         Node* root = build(in,pre,start,0,n-1);
//         return root;
//     }
// };
