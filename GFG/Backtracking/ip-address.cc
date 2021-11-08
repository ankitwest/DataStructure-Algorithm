class Solution{
    public:
  bool check(int i,int j,string &s){
      int len = j-i+1;
      if(len>3) return false;
      
      if(s[i] == '0'){
        if(len == 1) return true;
        return false;
     }
      
      int num = stoi(s.substr(i,len));
      if(num>=0 and num<=255) return true;
      return false;
  }
  bool valid_ip(int i,int j,int k,string &s){
      int l = s.size();
      if(check(0,i,s) and check(i+1,j,s) and check(j+1,k,s) and check(k+1,l-1,s))
        return true;
      return false;
  }
    void make_it(int i,int j,int k,string &s,int l,vector<string> &str){
        string temp;
        
    temp.append(s.substr(0,i+1));
    temp.push_back('.');
    temp.append(s.substr(i+1,j-i));
    temp.push_back('.');
    temp.append(s.substr(j+1,k-j));
    temp.push_back('.');
    temp.append(s.substr(k+1,l-k-1));
    
    str.push_back(temp);
        
        
    }
    vector<string> genIp(string &s) {
        vector<string> str;
        int l = s.size();
        for(int i=0;i<l-3;i++){
            for(int j=i+1;j<l-2;j++){
                for(int k=j+1;k<l-1;k++){
                    if(valid_ip(i,j,k,s))
                        make_it(i,j,k,s,l,str);
                }
            }
        }
        return str;
    }
};
Expected Time Complexity: O(N * N * N * N)
