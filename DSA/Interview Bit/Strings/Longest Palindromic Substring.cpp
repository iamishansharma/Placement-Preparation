// https://www.interviewbit.com/problems/longest-palindromic-substring/

int lenPal(string s, int &l, int r)
{
	int n = s.length();
	int ans=0;
	if(l==r){
	l--;r++;ans++;
	}
	while(l>=0 && r<n && s[l]==s[r])
	l--,r++, ans+=2;
	l++;
	return ans;
}

string Solution::longestPalindrome(string A) 
{
	int n = A.length();
	if(n==0 || n==1)
	return A;
	int ans = 0,start=-1;
	for(int i=0;i<n-1;i++){
	int st = i;
	int a1 = lenPal(A, st, i);
	int st2 =i;
	int a2 = lenPal(A, st2, i+1);
	if(a1>a2 && a1>ans) {ans = a1; start=st;}
	if(a2>a1 && a2>ans) {ans = a2; start=st2;}
	}
	return A.substr(start, ans);
}