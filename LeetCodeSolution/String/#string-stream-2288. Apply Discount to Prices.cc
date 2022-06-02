
class Solution {
public:
    string discountPrices(string sentence, int discount) {
        auto fun = [&](string &word){
            if(word.size()==1 or word[0]!='$') return word;
            
            long long cost = 0;
            for(int i=1;i<word.size();i++){
                if(!isdigit(word[i])) return word;
                cost = cost*10 + word[i]-'0';
            }
            
            double price = cost*1.0*(100-discount)/100;
            
            // string s = to_string(price);   cout<<s<<" ";
            // s = s.substr(0,s.size()-4);
            // stringstream w; w << s;
            // return "$" + w.str();
            stringstream w; w << fixed << setprecision(2) << price; return "$" + w.str();
        };
        
        stringstream ss(sentence);
        string ans; string word;
        while(ss >> word){
            ans += fun(word)+" ";
        }
        ans.pop_back();
        return ans;
    }
};


Input: sentence = "1 2 $3 4 $5 $6 7 8$ $9 $10$", discount = 100
Output: "1 2 $0.00 4 $0.00 $0.00 7 8$ $0.00 $10$"
Explanation: 
Applying a 100% discount on any price will result in 0.
The words representing prices are "$3", "$5", "$6", and "$9".
Each of them is replaced by "$0.00".
