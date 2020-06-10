// https://www.interviewbit.com/problems/distribute-candy/

int Solution::candy(vector<int> &rates) 
{
    int result = 0;
    
    int candles = 0;
    int previousRate = INT_MIN;
    int lastTopPosition = 0;
    int lastTopCandles = 0;
    
    for(int i = 0; i < rates.size(); i++)
    {
        
        int currentRate = rates[i];
        int currentIncrement = INT_MIN;
        
        if(currentRate >= previousRate)
        {   
            candles = currentRate == previousRate ? 1 : candles + 1;
            currentIncrement = candles;
            
            lastTopPosition = i;
            lastTopCandles = candles;
        }
        else 
        {
            
            currentIncrement  = i - lastTopPosition;
            
            if(lastTopCandles <= currentIncrement)
            {
                lastTopCandles++;
                currentIncrement++;
            }
            
            candles = 1;
        }
        
        result += currentIncrement;
        previousRate = currentRate;
    }
    
    return result;
}