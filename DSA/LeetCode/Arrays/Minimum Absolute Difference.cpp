sort(arr.begin(),arr.end());
        int mindif=INT_MAX,dif=0;
        vector<vector<int>> res;
		
        for(int i=0;i<arr.size()-1;i++)
        {
            dif = arr[i+1] - arr[i];
            mindif = min(mindif,dif);
        }
        for(int i=0;i<arr.size()-1;i++)
        {
            if(arr[i+1] - arr[i] == mindif)
                res.push_back({arr[i],arr[i+1]});
        }
        return res;