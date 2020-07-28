class Solution 
{
        public:
                vector<string> commonChars(vector<string>& A) 
                {
                    vector<string> commonChars;
                    int MAX_CHAR = 26;
                    int MAX_STRING = 100;
                    int count[MAX_CHAR][MAX_STRING];
                    memset(count,0,sizeof(count));
                    for(int stringIndex = 0; stringIndex<A.size();++stringIndex){
                        for(int charIndex = 0 ; charIndex < A[stringIndex].size(); ++charIndex){
                            count[A[stringIndex][charIndex]-'a'][stringIndex]++;
                        }
                    }

                    for(int charIndex = 0; charIndex <MAX_CHAR;++charIndex){
                        int min = INT_MAX;
                        for(int stringIndex = 0;stringIndex<A.size();++stringIndex){

                            if(count[charIndex][stringIndex]<min){
                                min = count[charIndex][stringIndex];
                            }
                        }

                        commonChars.insert(commonChars.end(),min, string(1,'a'+charIndex));
                    }

                    return commonChars;
                }
};