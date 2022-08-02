class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
       int req_petrol=0,curr_petrol=0,start=0;
        for(int i=0;i<n;i++){
        curr_petrol += p[i].petrol-p[i].distance;
        if(curr_petrol<0){
            req_petrol += curr_petrol;
            curr_petrol=0;
            start=i+1;
            }
        }
    return (req_petrol+curr_petrol>=0?start:-1);
    }
};
