class Solution {
private:
    bool valid_code(string& s){
        if(s.empty())return false;
        for(char c:s){
            if(!isalnum(c) &&c!='_')return false;
        }
        return true;
    }
    bool valid_category(string& s){
        return (s=="electronics" ||s=="grocery" ||s=="pharmacy" ||s=="restaurant");
    }
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<pair<string,string>> coupons;
        for(int i=0;i<code.size();i++){
            if(isActive[i] &&valid_code(code[i]) &&valid_category(businessLine[i]))coupons.push_back({businessLine[i],code[i]});
        }
        sort(coupons.begin(),coupons.end());
        vector<string> answer;
        for(auto& [_,c]:coupons)answer.push_back(c);
        return answer;
    }
};