class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int l = 0;
        int r = people.size() - 1;
        int boats = 0;
        while(l < r)
        {
            if(people[l] + people[r] > limit)
            {
                ++boats;
                --r;
            }  else {
                ++boats;
                ++l;
                --r;
            }
        }
        cout << l << endl;
        cout << r << endl;
        if(l == r && people[l] <= limit)
        {
            ++boats;
        }
        return boats;
    }
};