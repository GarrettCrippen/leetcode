class Solution
{
public:
    long long dividePlayers(vector<int> &skill)
    {
        // n/2 teams of two
        //  largest, smallest

        sort(skill.begin(), skill.end());

        int p1 = 0;
        int p2 = skill.size() - 1;

        long long sum = 0;
        long last = skill.at(p1) + skill.at(p2);
        while (p1 < p2)
        {
            if (last != skill.at(p1) + skill.at(p2))
                return -1;
            sum += skill.at(p1) * skill.at(p2);
            last = skill.at(p1) + skill.at(p2);

            p1++;
            p2--;
        }
        return sum;
    }
};