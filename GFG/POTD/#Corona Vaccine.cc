class Solution{
public:
    // string solve2(Node* root,int &ans){
    //     if(!root)
    //         return "no need";
        
    //     string l = solve(root->left,ans);
    //     string r = solve(root->right,ans);
        
    //     if(l=="plz vaccinate me" or r=="plz vaccinate me"){
    //         ans++;
    //         return "has vaccine";
    //     }
        
    //     if(l=="has vaccine" or r=="has vaccine"){
    //         return "no need";
    //     }
    
    //     return "plz vaccinate me";
            
    // }
        
// state -1 = need vaccine;
// state 0 = vaccinated;
// state 1 = has extra vaccine;


    int ans=0;
    int solve(Node* root){
        if(!root)
            return 0;
        
        int l = solve(root->left);
        int r = solve(root->right);
        
        if(l==-1 or r==-1){
            ans++;
            return 1;
        }
        if(l==1 or r==1){
            return 0;
        }
        return -1;
    }
    int supplyVaccine(Node* root){
        if(!root) return 0;
        if(!root->left and !root->right) return 1;

        if(solve(root)==-1)
            ans++;
        return ans;
    }
};

nput:
    1
   / \
  2   3 
        \
         4
          \
           5
            \
             6

Output:
2
Explanation:
The vaccine kits should be 
supplied to house numbers 1 and 5. 
