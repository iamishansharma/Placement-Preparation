// https://www.interviewbit.com/problems/shortest-unique-prefix/

struct Trie
{
    int prefix;
    Trie* child[26];
    
}*head;

void init()
{
    head = new Trie();
}

void add(string word)
{
    Trie* ptr = head;
    for(int i=0; i<word.length(); i++)
    {
        int pos = word[i]-'a';
        
        if(ptr->child[pos]==NULL)
            ptr->child[pos] = new Trie();
            
        ptr = ptr->child[pos];
        ptr->prefix++;
    }
}

string search(string word)
{
    Trie* ptr = head;
    string sol = "";
    for(int i=0;i<word.length();i++)
    {
        int pos = word[i]-'a';
        sol+=word[i];
        ptr = ptr->child[pos];
        
        if(ptr->prefix == 1)
            return sol;
    }
    return sol;
}

vector<string> Solution::prefix(vector<string> &A) 
{
    init();
    int n = A.size();
    vector<string> ans;
    
    for(int i=0;i<n;i++)
    {
        add(A[i]);
    }
    for(int i=0;i<n;i++)
    {
        ans.push_back(search(A[i]));
    }
    return ans;
}