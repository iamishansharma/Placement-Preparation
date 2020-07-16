// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

long long toh(int n, int from, int to, int aux);

int main() {

    int T;
    cin >> T;
    while (T--) {
        long long moves = 0;
        int N;
        cin >> N;
        moves = toh(N, 1, 3, 2);
        cout << moves << endl;
    }
    return 0;
}



 // } Driver Code Ends


// You need to complete this function

// avoid space at the starting of the string in "move disk....."
long long toh(int N, int from, int to, int aux) 
{
    int move = 0;
    
    if(N == 1)
    {
        cout<<"move disk "<<N<<" from rod "<<from<<" to rod "<<to<<endl;
        move++;
        return move;
    }
    
    move += toh(N-1, from, aux, to);
    cout<<"move disk "<<N<<" from rod "<<from<<" to rod "<<to<<endl;
    move++;
    move += toh(N-1, aux, to, from);
}


// { Driver Code Starts.  // } Driver Code Ends