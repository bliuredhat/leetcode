/*
Given an unsorted array of integers, find the length of the longest consecutive 
elements sequence.
Your algorithm should run in O(n) complexity.
Example:
Input: [100, 4, 200, 1, 3, 2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4].
 Therefore its length is 4.
*/
#include <vector>

class Solution 
{ 
    public: int longestConsecutive(vector<int> &num) 
    { 
        int size=num.size(); 
        if(size<2)
        { 
            return size; 
        } 
        unordered_set<int> number(num.begin(),num.end()); 
        int length=1; 
        for(auto it:num)
        { 
            if(number.find(it)!=number.end())
            { 
                number.erase(it); 
                int left=it-1; 
                int right=it+1; 
                while(number.find(left)!=number.end())
                { 
                    number.erase(left); --left; 
                } 
                while(number.find(right)!=number.end())
                { 
                    number.erase(right); ++right; 
                } 
                length=max(length,right-left-1); 
            } 
        } 
        return length; 
    }
};
