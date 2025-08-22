#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

class Solution 
{
public:
    string revword(string s)
    {
        stringstream ss(s);
        string word;
        vector<string> words;

        while (ss >> word) 
        {
            words.push_back(word);
        }

        if (words.empty()) 
        {
            return "";
        }
        
        string result = "";
        for (int i = words.size() - 1; i >= 0; --i) 
        {
            result += words[i];
            if (i > 0) {
                result += " ";
            }
        }

        return result;
    }
};

int main() 
{
    Solution sol;
    string test1 = "the sky is blue";
    string test2 = "  hello world  ";
    string test3 = "a good   example";
    string test4 = " ";
    string test5 = "word";

    cout << "Input: \"" << test1 << "\"" << endl;
    cout << "Output: \"" << sol.revword(test1) << "\"" << endl<<endl;

    cout << "Input: \"" << test2 << "\"" << endl;
    cout << "Output: \"" << sol.revword(test2) << "\"" << endl<<endl;

    cout << "Input: \"" << test3 << "\"" << endl;
    cout << "Output: \"" << sol.revword(test3) << "\"" << endl<<endl;

    cout << "Input: \"" << test4 << "\"" << endl;
    cout << "Output: \"" << sol.revword(test4) << "\"" << endl<<endl;

    cout << "Input: \"" << test5 << "\"" << endl;
    cout << "Output: \"" << sol.revword(test5) << "\"" << endl<<endl;
    return 0;
}
