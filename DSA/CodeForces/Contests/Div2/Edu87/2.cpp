#include <bits/stdc++.h>
#define fastIO 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define debug(x)		{	cerr << #x << " = " << x <<endl;	}
#define ll	 			long long int
using namespace std;

const int no_of_chars = 300000;

string findSubString(string str, string pat) 
{ 
	int len1 = str.length(); 
	int len2 = pat.length(); 
  
	if (len1 < len2) 
	{ 
		cout << "No such window exists"; 
		return ""; 
	} 
  
	int hash_pat[no_of_chars] = {0}; 
	int hash_str[no_of_chars] = {0}; 
  
	for (int i = 0; i < len2; i++)
		hash_pat[pat[i]]++; 
  
	int start = 0, start_index = -1, min_len = INT_MAX; 
  
	int count = 0; 
	for (int j = 0; j < len1 ; j++) 
	{ 
		hash_str[str[j]]++; 
  
		if (hash_pat[str[j]] != 0 && 
			hash_str[str[j]] <= hash_pat[str[j]] ) 
			count++; 
  
		if (count == len2) 
		{ 
			while ( hash_str[str[start]] > hash_pat[str[start]] 
				|| hash_pat[str[start]] == 0) 
			{ 
  
				if (hash_str[str[start]] > hash_pat[str[start]]) 
					hash_str[str[start]]--; 
				start++; 
			} 
  
			// update window size 
			int len_window = j - start + 1; 
			if (min_len > len_window) 
			{ 
				min_len = len_window; 
				start_index = start; 
			} 
		} 
	} 

	if(start_index == -1) 
		return "";
  
	return str.substr(start_index, min_len); 
}

void solve()
{
	string s;
	cin>>s;

	int n=s.length();

	map<char,int> m;
	m.clear();

	for(int i=0; i<s.length(); i++)
		m[s[i]]++;

	if(m['1'] == 0 || m['2'] == 0 || m['3'] == 0)
		cout<<"0"<<endl;
	else
	{
		string answer = findSubString(s, "123");
		cout<<answer.length()<<endl;
	}
}

int main()
{
	fastIO;

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin); 
		freopen("output.txt", "w", stdout); 
	#endif
	
	int tc=0;
	cin>>tc;
	while(tc--)
	{
		//cerr<<endl;
		//debug(tc);
		solve();
	}
	return 0;
}