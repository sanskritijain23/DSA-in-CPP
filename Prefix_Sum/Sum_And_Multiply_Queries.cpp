/*
Problem: Sum And Multiply (Queries)
Platform: LeetCode (3756)
Topic: Prefix Sum, Binary Search, Modular Arithmetic

Approach:
- Store the positions and values of all non-zero digits.
- Precompute:
  • Prefix values to reconstruct concatenated numbers.
  • Prefix sums of digits.
  • Powers of 10 modulo MOD.
- For each query:
  • Use binary search to locate non-zero digits within the range.
  • Reconstruct the concatenated number using prefix values.
  • Compute the digit sum using prefix sums.
  • Return (concatenated number × digit sum) modulo MOD.

Time Complexity: O(n + q log n)
Space Complexity: O(n)
*/

class Solution {
public:
    static const int MOD=1000000007;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n=s.size();
        vector<int> pos;
        vector<int> digit;

        for(int i=0;i<n;i++){
            if(s[i]!='0'){
                pos.push_back(i);
                digit.push_back(s[i]-'0');
            }
        }
        int k=digit.size();

        vector<long long> pw(k+1,1);
        for(int i=1;i<=k;i++)
            pw[i]=(pw[i-1]*10)%MOD;
        vector<long long> prefval(k+1,0);
        vector<long long> prefsum(k+1,0);

        for(int i=1;i<=k;i++){
            prefval[i]=(prefval[i-1]*10+digit[i-1])%MOD;
            prefsum[i]=prefsum[i-1]+digit[i-1];

        }
        vector<int> ans;
        for(auto &q:queries){
            int l=q[0],r=q[1];

            int L=lower_bound(pos.begin(),pos.end(),l)-pos.begin();
            int R=upper_bound(pos.begin(),pos.end(),r)-pos.begin()-1;

            if(L>R){
                ans.push_back(0);
                continue;
            }

            int len=R-L+1;
            long long x=(prefval[R+1]-prefval[L]*pw[len])%MOD;
            if(x<0)    x+=MOD;
            long long sum=prefsum[R+1]-prefsum[L];
            ans.push_back((x*(sum%MOD))%MOD);

        }
        return ans;
    }
};