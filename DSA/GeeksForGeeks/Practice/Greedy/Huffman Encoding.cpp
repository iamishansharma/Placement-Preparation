#include <bits/stdc++.h>
using namespace std;
#define fastIO 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define debug(x)		{	cerr << #x << " = " << x <<endl;	}
#define ll	 			long long int

typedef struct node Node;

struct node
{
	//bool isused;
	char ch;
	int freq;
	Node *left;
	Node *right;

	node(char ch, int freq)
	{
		//isused = 0;
		this->ch = ch;
		this->freq = freq;
		left = NULL;
		right = NULL;
	}
};

struct compare 
{
	bool operator()(Node *a,Node *b)
	{
		return a->freq>b->freq;		
	}
};

void printHuffTree(Node *root, string s)
{
	if(root == NULL)
		return;

	if(root->left == NULL && root->right == NULL)
		cout<<s<<" ";

	printHuffTree(root->left, s + "0");
	printHuffTree(root->right, s + "1");
}

void solve()
{
	string s;
	cin>>s;

	int n = s.length();

	vector<int> f(n);
	
	for(int i=0; i<n; i++)
		cin>>f[i];

	if(n == 1)
		return;

	priority_queue <Node *, vector<Node*>, compare> q;

	for(int i=0; i<n; i++)
	{
		Node *temp = new Node(s[i], f[i]);
		//temp->isused = 1; // denotes that node is useful as character
		q.push(temp);
	}

	while(q.size() > 1)
	{
		Node *left = q.top();
		q.pop();
		Node *right = q.top();
		q.pop();

		Node *root = new Node('$', left->freq + right->freq);
		root->left = left;
		root->right = right;
		//root->isused = 0; // denotes that the root is not useful

		q.push(root);
	}

	printHuffTree(q.top(), "");

	cout<<endl;
}

int main()
{
	fastIO;
	
	int tc=0;
	cin>>tc;
	while(tc--)
	{
		solve();
	}
	return 0;
}