
static bool comp(val p1,val p2){
    if(p1.second == p2.second) return p1.first < p2.first;
    return p1.second < p2.second;
}

int maxChainLen(struct val p[],int n)
{
    sort(p,p+n,comp);
    
    int start = p[0].first;
    int end = p[0].second;
    int cnt = 1;
    for(int i=1;i<n;i++){
        if(p[i].first>end){
            cnt++;
            end = p[i].second;
        }
    }

    return cnt;
}
