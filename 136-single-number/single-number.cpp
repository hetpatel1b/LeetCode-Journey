#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
   int singleNumber(vector<int>& nums)
   {
       int n = nums.size();
       int xorResult = 0;


       // XOR all elements: duplicates cancel out, single remains
       for (int i = 0; i < n; i++) {
           xorResult ^= nums[i];
       }
       return xorResult;
   }
};