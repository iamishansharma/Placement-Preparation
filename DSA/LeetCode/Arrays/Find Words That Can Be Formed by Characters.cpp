class Solution 
{
    public:
            bool canForm(string word, unordered_map<char, int> m)
            {
                for(int i=0; i<word.size(); i++)
                {
                    if(m[word[i]] == 0)
                        return false;
                    else
                        m[word[i]]--;
                }
                return true;
            }
    
            int countCharacters(vector<string>& words, string chars) 
            {
                unordered_map<char,int> m;
                
                for(int i=0; i<chars.size(); i++)
                    m[chars[i]]++;
                
                int sum = 0;
                
                for(int i=0; i<words.size(); i++)
                {
                    if(canForm(words[i], m))
                        sum += words[i].size();
                }
                return sum;
            }
};