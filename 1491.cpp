class Solution {
public:
    double average(vector<int>& salary) {
        int max_sal=salary[0],min_sal=salary[0];
        double n=salary.size();
        int sum=0;
        for(int s:salary){
            max_sal=max(s,max_sal);
            min_sal=min(s,min_sal);
            sum+=s;
        }
        double average=(sum-max_sal-min_sal)/(n-2);
        return average;
    }
};