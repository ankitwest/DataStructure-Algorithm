class Solution{
  public:
      Node* merge(Node* a,Node* b)
    {
        if(a==NULL)return b;
        if(b==NULL)return a;
        if(a->data<b->data)
        {
            a->next=merge(a->next,b);
            return a;
        }
        else
        {
            b->next=merge(a,b->next);
            return b;
        }
    }
    Node * mergeKLists(Node *arr[], int k)
    {
        Node* v=NULL;
        for(int i=0;i<k;i++){
            v = merge(v,arr[i]);
        }
         return v;
    }
};

Expected Time Complexity: O(nk Logk)
Expected Auxiliary Space: O(k)
  
  
 
 class Solution{
    public:
map<int,int>mp;
void helper(Node* list){
    while(list){
        mp[list->data]++;
        list = list->next;
    }
}

    Node * mergeKLists(Node *arr[], int k)
    {
      Node* res = arr[0];
      Node* temp = arr[0];
      for(int i=0;i<k;i++){
          helper(arr[i]);
      }
      int j=1;
      for(auto i:mp){
              while(i.second--){
                  temp->data = i.first;
                  if(temp->next==NULL and j!=k){
                      temp->next = arr[j];
                      j++;
                  }
                  temp = temp->next;
              }
      }
      return res;
    }
 };
