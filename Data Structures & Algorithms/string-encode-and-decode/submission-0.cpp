class Solution {
public:

    string encode(vector<string>& strs) {
        string encode_string;
        for(string s : strs){
            encode_string.append(to_string(s.size()));
            encode_string.push_back('#');
            encode_string.append(s);
        }
        return encode_string;
    }

    vector<string> decode(string s) {
        vector<string> result;
        int i=0;
        while(i<s.size()){
            int j=i;
            while(s[j]!='#')
                j++;
            int len = stoi(s.substr(i,j-i));
            i=j+1;
            j=i+len;
            result.push_back(s.substr(i,len));
            i=j;
        }
        return result;
    }
};
