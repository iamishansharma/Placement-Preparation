// https://www.interviewbit.com/problems/hotel-reviews/

struct node
{
    node *arr[26];
    bool isword;
    
    node()
    {
        isword = false;
        
        for(int i=0; i<26; i++) 
            arr[i] = NULL;
    }
};

struct trie
{
    node *root;

    trie()
    {
        root = new node();
    }
    
    void insert(string s)
    {
        node *temp = root;
        
        for(char c : s)
        {
            if(temp->arr[c-'a'] == NULL)
            {
                temp->arr[c-'a'] = new node();
            }
            temp = temp->arr[c-'a'];
        }
        temp->isword = true;
    }
    
    bool search(string s)
    {
        node *temp = root;
        
        for(char c : s)
        {
            if(temp->arr[c-'a'] == NULL)
            {
                return false;
            }
            temp = temp->arr[c-'a'];
        }
        return temp->isword;
    }
};

bool cmp(pair<int,int> p1,pair<int,int> p2)
{
    if(p1.second == p2.second)
    {
        return p1.first < p2.first;
    }
    return p1.second > p2.second;
}

vector<int> Solution::solve(string a, vector<string> &b) 
{
    a += '_';
    string temp;
    trie t;

    for(char c : a)
    {
        if(c == '_')
        {
            t.insert(temp);
            temp = "";
        }
        else
        {
            temp += c;
        }
    }
    
    vector<pair<int,int>> vec;
    int i=0;
    
    for(string s : b)
    {
        temp = "";
        s += "_";
        
        int count = 0;
        
        for(char c : s)
        {
            if(c == '_')
            {
                if(t.search(temp))
                {
                    count++;
                }
                temp = "";
            }
            else
            {
                temp += c;
            }
        }
        
        vec.emplace_back(i,count);
        
        i++;
    }
    
    sort(vec.begin(),vec.end(),cmp);
    
    vector<int> ans;
    
    for(auto p : vec)
    {
        auto[u,v] = p;
        ans.push_back(u);
    }
    return ans;
}