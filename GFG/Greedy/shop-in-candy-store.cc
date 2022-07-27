class Solution{
public:
 vector<int> candyStore(int candies[], int N, int K)
   {
       int mini=0,maxi=0;
       int i=0;int j=N-1;
       int n = N;
       sort(candies,candies+N);
       while(i<n){
           mini+=candies[i];
           n-=K;
           i++;
       }
      i=0;
      while(j>=i){
          maxi+=candies[j];
          i+=K;
          j--;
      }
 
       return {mini,maxi};
   }
};

Q?
 
Now you have to answer two questions. Firstly, you have to find what is the minimum amount of money you have to spend to buy all the N different candies. Secondly, you have to find what is the maximum amount of money you have to spend to buy all the N different candies.
In both the cases you must utilize the offer i.e. you buy one candy and get K other candies for free.
 
 
Input:
N = 4
K = 2
candies[] = {3 2 1 4}

Output:
3 7

Explanation:
As according to the offer if you buy 
one candy you can take at most two 
more for free. So in the first case, 
you buy the candy which costs 1 and 
takes candies worth 3 and 4 for free, 
also you buy candy worth 2 as well.
So min cost : 1+2 =3.
In the second case, you can buy the 
candy which costs 4 and takes candies 
worth 1 and 2 for free, also you need 
to buy candy worth 3 as well. 
So max cost : 3+4 =7.
 
 
Input: 
N = 5
K = 4
candies[] = {3 2 1 4 5}

Output: 
1 5

Explanation:
For minimimum cost buy the candy with
the cost 1 and get all the other candies
for free.
For maximum cost buy the candy with
the cost 5 and get all other candies
for free.
