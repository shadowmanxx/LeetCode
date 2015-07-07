 unordered_set<int> m;
        unsigned int i = 0;
        
        if(k <= 0) return 0;
        if(k > nums.size()) k = nums.size() -1;
        
        for(i = 0;i < nums.size();i++)
        {
            if(i > k) m.erase(nums[i - k - 1]);
            if(m.find(nums[i]) != m.end()) 
                return 1;
            else
                m.insert(nums[i]);
            
        }
