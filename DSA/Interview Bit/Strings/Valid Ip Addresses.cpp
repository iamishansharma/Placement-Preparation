//https://www.interviewbit.com/problems/valid-ip-addresses/

string generateit(string A, int i, int j, int k){
    string temp = "";
    for(int x=0; x<A.length(); x++){
        temp = temp + A[x];
        if(x==i || x==j || x==k)
        temp = temp + '.';
    }
    return temp;
}
void tokenize(string const &str, const char delim,
            vector<string> &out)
{
    size_t start;
    size_t end = 0;

    while ((start = str.find_first_not_of(delim, end)) != std::string::npos)
    {
        end = str.find(delim, start);
        out.push_back(str.substr(start, end - start));
    }
}
bool isvalid(string IP, int i, int j, int k, unordered_map <string, int> &s){
    int cnt=0;
    for(int y=0; y<IP.length(); y++){
        if(IP[y]=='.')
        cnt++;
    }
    if(cnt!=3)
    return 0;
    string ss = IP;
    const char delim = '.';
    vector<string> out;
    tokenize(ss, delim, out);
    if(out.size()!=4)
    return 0;
    for(int i=0; i<4; i++){
        if(s.find(out[i])==s.end())
        return 0;
    }
    
    return 1;
}

vector<string> Solution::restoreIpAddresses(string A) {
    int len = A.length();
    unordered_map <string,int> s;
    for(int i=0; i<=255; i++){
        s[to_string(i)]=i;
    }
    vector<string> res;
    for(int i=0; i<len; i++){
        for(int j=i+1; j<len; j++){
            for(int k=j+1; k<len; k++){
                string IP = generateit(A,i,j,k);
                if(isvalid(IP,i,j,k,s)){
                    res.push_back(IP);
                }
            }
        }
    }
    return res;
}