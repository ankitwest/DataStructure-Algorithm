public:
    //Function to evaluate a postfix expression.
    // static bool isOperator(char ch){
    //     return ch == '*' or ch == '+' or ch == '+' or ch == '-';
    // }
    // int fun(int b,int a,char c){
    //     int res = 0;
    //     switch (c){
    //         case '*' : res = b * a; break;
    //         case '/' : res = b / a; break;
    //         case '+' : res = b + a; break;
    //         case '-' : res = b - a; break;
    //     }
    //     return res;
    // }
    // int evaluatePostfix(string s)
    // {
    //     stack<int> st;  int n = s.size();

    //     for(int i=0;i<n;i++){
    //         if(isOperator( s[i] ))  {
    //             int a = st.top(); st.pop();
    //             int b = st.top(); st.pop();
                
    //             int res = fun(b,a,s[i]);
    //             cout<<res<<" a";
    //             st.push(res);
    //         }else if(isdigit(s[i])) {
    //             st.push(s[i]-'0');
    //         }
    //     }
    //     return st.top();
    // }
    
    //  08/   tcase
    
    
    
    
    int evaluatePostfix(string S)
   {
       stack <int> s;
       for(int i=0;i<S.length();i++)
       {
           if(S[i]>='0'&&S[i]<='9')
           {
               s.push(S[i]-'0');
           }
           else
           {
               int op1=s.top();
               s.pop();
               int op2=s.top();
               s.pop();
               switch(S[i])
               {
                   case '+':
                   s.push(op2+op1);
                   break;
                   case '-':
                   s.push(op2-op1);
                   break;
                   case '*':
                   s.push(op2*op1);
                   break;
                   case '/':
                   s.push(op2/op1);
                   break;
                   case '^':
                   s.push(op2^op1);
                   break;
               }
           }
       }
       
       return s.top();
   }
