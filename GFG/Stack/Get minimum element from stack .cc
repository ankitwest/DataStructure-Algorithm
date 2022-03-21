
class Solution{
int mini;
    stack<int> s;
    public:
    
       /*returns min element from stack*/
       int getMin(){
            return s.empty()?-1:mini;
       }
       
       /*returns poped element from stack*/
       int pop(){
           if(s.empty())
            return -1;
            
           int x = s.top(); s.pop();
           if(x>=mini){
               return x;
           }
           else if(x<mini){
               int ele = mini;
               mini = 2*mini-x;
               return ele;
           }
           return -1;
       }
       
       /*push element x into the stack*/
       void push(int x){
          if(s.empty()){
              s.push(x);
              mini = x;
          }else if(x>=mini){
              s.push(x);
          }else if(x<mini){
              s.push(2*x-mini);
              mini = x;
          }
       }
       };
