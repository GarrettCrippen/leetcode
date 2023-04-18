class Solution
{
public:
    // s and k, return length of longest substring of 1 letter

    // input: string (uppercase letters) l=[1,10^5] , k =[0,length]
    // output:integer

    // to find longest substring: iterate through s

    // we can iterate and color one at a time
    int characterReplacement(string s, int k)
    {

        int left = 0, right = 0;

        // let's count the occurrance of each character
        vector<int> count(26);
        int max_f = 0;
        int my_max = 0;
        // we want to find the maximum number of any letters
        while (right < s.size())
        {
            // increment count
            count[s[right] - 'A']++;
            max_f = max(max_f, count[s[right] - 'A']);

            // see if size of our window - count of right
            if (right - left + 1 - max_f > k)
            {
                count[s[left] - 'A']--;
                left++;
            }

            if (right - left + 1 > my_max)
                my_max = right - left + 1;

            right++;
        }
        return my_max;

        // //char and streak
        // vector<pair<char,int>>window(s.length()+1);
        // window[0]={s[0],1};
        // for(int i = 1; i<s.length(); i++){
        //     if(s[i] ==window[i-1].first){
        //         window[i]={s[i],window[i-1].second+1};
        //     }
        //     else
        //         window[i]={s[i],1};
        // }
        // if(s.length()>1)
        //     window[s.length()]={s[s.length()-2],0};

        // int my_max=0;
        // //now it is a sliding window problem of size k

        // //Consider case where we want to change I to i-1 => so extend window size

        // //note changes does not need to be in sequence, just needs to be on the otherside of the window
        // for(int i =window.size()-1;i>=0;i--){
        //     //cout<<"I="<<i<<endl;
        //     int temp = window[i].second;
        //     int changes = 0;
        //     int j = i-1;

        //     if(my_max>i)break;

        //     //check if windows are the same otherwise change and add
        //     while(j>=0){
        //         if(window[j].first==window[i].first){
        //             //see if it already is part of a sequence, then do nothing
        //             //if its a new sequence then add it
        //             if(window[j+1].first != window[j].first)
        //                 { temp+=window[j].second;
        //                 }
        //         }
        //         //need to change, but if we use all changes, we don't want to neccessarily stop
        //         //only stop when we are at changes+1
        //         else{
        //             changes++;
        //             if(changes>k) break;
        //             temp+=1;
        //         }
        //         j--;
        //     }
        //     if(temp > my_max){
        //         my_max = temp;
        //     }
        // }

        // return my_max;
    }
};