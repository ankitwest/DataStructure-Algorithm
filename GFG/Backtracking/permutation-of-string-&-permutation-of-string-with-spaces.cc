
//Permutation of String

void permute(int start, int len, string &currstr, set<string> &permutations){
    if(start == len-1){
        permutations.insert(currstr);
        return;
    }
    for(int i=start;i<len;i++){
        swap(currstr[start],currstr[i]);
        permute(start+1,len,currstr,permutations);
        swap(currstr[start],currstr[i]);
    }
}




//Permutation of String with Spaces

void permutations(int start,int len, string &str, set<string> &strings){
    if(start == len-1){
        strings.insert(str);
        return;
    }
    permutations(start+1,len,str,strings);
    str.insert(start+1," ");
    permutations(start+2,len+1,str,strings);
    str.erase(start+1,1);
}
