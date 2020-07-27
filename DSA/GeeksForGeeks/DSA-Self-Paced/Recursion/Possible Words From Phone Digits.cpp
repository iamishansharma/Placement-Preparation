// { Driver Code Starts
#include <bits/stdc++.h>
#include <string>

using namespace std;

vector <string> possibleWords(int a[],int n);


int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	  vector <string> res = possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}// } Driver Code Ends


//Complete this function

void pos(string str[], vector<string> &ans, string cur, int a[], int n, int i)
{
    if(cur.length() == n)
    {
        ans.push_back(cur);
        return;
    }
    string pad = str[a[i]];
    
    for(int j=0; j<pad.length(); j++)
        pos(str, ans, cur + pad[j], a, n, i + 1);
}

vector <string> possibleWords(int a[], int N)
{
    vector<string> ans;
    string str[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    pos(str, ans, "", a, N, 0);
    sort(ans.begin(), ans.end());
    
    //for(int i=0; i<ans.size(); i++)
        //cout<<ans[i]<<" ";
        
    return ans;
}