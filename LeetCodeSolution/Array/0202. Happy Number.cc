class Solution {
    int squares(int n){
        int sum=0;
        while(n){
            int ld = n%10;
            sum += ld*ld;
            n /= 10;
        }
        return sum;
    }        
public:
     bool isHappy(int n) {
        if(n<=0) return false;
    
     int slow = n;
     int fast = squares(n);
     if(slow==1 or fast==1) 
            return true;
      while(slow != fast){
         slow = squares(slow);
         fast = squares(squares(fast));
         if(slow==1 or fast==1) 
                return true;
        }
         return false;
    }
};


class Solution2 {
    int squares(int n){
        int sum=0;
        while(n){
            int ld = n%10;
            sum += ld*ld;
            n /= 10;
        }
        return sum;
    }
public:
    bool isHappy(int n) {
       if(n<=0) return false;
    
        unordered_map<int,int> m;
        while(n!=1){
            if(m.count(n)>0) return false;
            m[n]++;
            n = squares(n);
        }
        return true;
    }
};
