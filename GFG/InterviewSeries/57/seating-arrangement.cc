
bool can_place(int index,int n,vector<int>& seats){
        if((index>=1 and seats[index-1]==1) or (index<=n-2 and seats[index+1]==1)) return false;
        return true;
    }
    public:
    bool is_possible_to_get_seats(int k, int n, vector<int>& seats){
        if(k==1 and n==1 and seats[0]==0) return 1;
        if(k==0) return 1;

        for(int i=0;i<n;i++){
            if(seats[i]==1) i++;
            else {
                if(can_place(i,n,seats)) k--,i++;
                else continue;
            }
        }
        
        if(k>0) return false;
    }



Input:
n = 2
m = 7
seats[] = {0, 0, 1, 0, 0, 0, 1}
Output:
Yes
Explanation:
The two people can sit at index 0 and 4.
