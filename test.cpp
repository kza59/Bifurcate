#include <iostream>
#include <vector>
#include <string>
using namespace std;
    void disp(vector<string> v) {
        for(auto& item : v) {
            cout << item << endl;
        }
    }
vector<string> chars(string s) {
            vector<string> v;
        int a{0},b{0};
    for (int i = 0; i < s.length(); ++i) {
        if (i < s.length() - 1 && s[i] == s[i + 1]) {
            int a = i;
            int b = i + 1;
            while (b < s.length() && s[a] == s[b]) {
                ++b;
            }
            v.push_back(s.substr(a, b - a));
            i = b - 1;  
        } else {
            v.push_back(s.substr(i, 1)); 
        }
    }
    return v;
    }
bool matcher(const std::vector<std::string>& v1, const std::vector<std::string>& v2) {
    // Check if sizes are different
    if (v1.size() != v2.size()) {
        return false;
    }
    for (size_t i = 0; i < v1.size(); ++i) {
        if (v1[i][0] != v2[i][0]) {
            return false;
        }

        if (v1[i].length() > v2[i].length()) {
            return false;
        }
    }

    return true;
}
int main() {
    // string s = "saeedd";
    // string t = "ssaaedd";
    string s = "alex";
    string t = "aaleex";

        vector<string> v1 = chars(s);
        vector<string> v2 = chars(t);
        disp(v1);
        cout << "   " << endl;
        disp(v2);
        if(matcher(v1,v2)) {
            cout << "TRUE\n";
        }
        else {
            cout << "FALSE\n";
        }

    
}