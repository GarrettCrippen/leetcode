class Solution {
public:
    //new character map to other character
    //keep checking character key and map works
    //Important: lengths are the same
    bool isIsomorphic(string s, string t) {
        map<char,char>mymap;
        map<char,int> used;
        //check if character is already mapped, otherwise map it
        for(int i =0; i<s.length();i++){
            if(mymap.count(s[i])>0){
                if(mymap[s[i]]!=t[i]){ 
                    return false;
                }
            }
            else{
                if(used.count(t[i])){
                    return false;
                }
                mymap[s[i]]=t[i];
                used[t[i]]=1;
            }
        } //p->t a->i e->l r->e
        return true;
    }
};