
class Solution{
public:
    string previousNumber(string S){
        int largest = -1; int n = S.size();
        for(int i=n-2;i>=0;i--){
            if(S[i]>S[i+1]) {
                largest = i; break;
            }
        }
        if(largest==-1) return "-1";
        
        int smallest = largest+1;
        for(int i=n-1;i>=0;i--){
            if(S[i]<S[largest]) {
                smallest = i; break;
            }
        }
        for(int i=smallest-1;i>=0;i--){
            if(S[i]!=S[smallest])
              {  smallest = i+1; break;}
        }
        swap(S[smallest],S[largest]);
        if(S[0]=='0') return "-1";
        
        return S;
    }
};
