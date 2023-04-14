class Solution
{
public:
    // n cars going to target
    // input:pos[], speed[] of ith car
    // faster car will slow down to slower car infront
    // output: return number groups of cars going at the same speed

    int carFleet(int target, vector<int> &position, vector<int> &speed)
    {
        // int time = (target-pos)/speed;

        vector<pair<int, int>> combined;
        combined.reserve(speed.size());
        transform(position.begin(), position.end(), speed.begin(), back_inserter(combined), [](int a, int b)
                  { return make_pair(a, b); });
        sort(combined.begin(), combined.end(), [](auto &a, auto &b)
             { return a.first > b.first; });

        for (auto it = combined.begin(); it != combined.end(); it++)
        {
            cout << it->first << "," << it->second << endl;
        }

        // NOTE: slower cars with a greater pos -> more cars in a single car fleet
        //  faster cars in greater pos -> less cars in a single car fleet
        // so, first check the positions, then the calculated time to end

        int num_fleets = combined.size();
        stack<double> st;
        st.push((double)(target - combined[0].first) / (combined[0].second));
        for (int i = 1; i < combined.size(); i++)
        {
            //(target-pos)/speed. check if time on stack is lt current time
            //-> pop and reduce num_fleets by one
            double time = (double)(target - combined[i].first) / (combined[i].second);
            // cout<<"TOP: "<<st.top()<<", "<<"TIME: "<<time<<endl;
            double jam = 0;
            if (!st.empty() && time <= st.top())
            {
                num_fleets--;
                jam = st.top();
                st.pop();
            }

            // push speed of car *infront
            jam == 0 ? st.push(time) : st.push(jam);
        }
        return num_fleets;

        return 0;
    }
};