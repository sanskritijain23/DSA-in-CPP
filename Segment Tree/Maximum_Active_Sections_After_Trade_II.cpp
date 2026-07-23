/*
Problem: Maximum Active Sections After Trade II
Platform: LeetCode
Topic: Segment Tree, Binary Search, Greedy, Strings

Approach:
- Count the total number of active ('1') sections.
- Traverse the string to identify every consecutive inactive ('0') block.
- Store the starting and ending indices of each zero block.
- Build an array containing the sum of every pair of adjacent zero blocks.
- Construct a Segment Tree over this array to answer range maximum queries.
- For each query:
  - Locate the affected zero blocks using binary search.
  - Compute the best possible merge involving the boundary blocks.
  - Query the Segment Tree for the best merge completely inside the range.
  - The maximum of these values gives the optimal gain.
- Add the gain to the initial active count.

Time Complexity:
- Preprocessing: O(n)
- Segment Tree Build: O(n)
- Each Query: O(log n)

Overall: O(n + q log n)

Space Complexity: O(n)
*/


class Solution {
    class SegmentTree {
    private:
        int n;
        vector<int> arr;
        vector<int> seg;

        void build(int p, int l, int r) {
            if (l == r) {
                seg[p] = arr[l];
                return;
            }

            int mid = (l + r) >> 1;

            build(p << 1, l, mid);
            build(p << 1 | 1, mid + 1, r);

            seg[p] = max(seg[p << 1], seg[p << 1 | 1]);
        }

        int queryUtil(int p, int l, int r, int L, int R) {
            if (L <= l && r <= R) {
                return seg[p];
            }

            int mid = (l + r) >> 1;
            int res = 0;

            if (L <= mid) {
                res = max(res, queryUtil(p << 1, l, mid, L, R));
            }

            if (R > mid) {
                res = max(res, queryUtil(p << 1 | 1, mid + 1, r, L, R));
            }

            return res;
        }

    public:
        SegmentTree(vector<int>& a) {
            arr = a;
            n = arr.size();

            seg.assign(4 * n, 0);
            build(1, 0, n - 1);
        }

        int query(int L, int R) {
            if (L > R) return 0;

            return queryUtil(1, 0, n - 1, L, R);
        }
    };


public:
    vector<int> maxActiveSectionsAfterTrade(string s,
                                            vector<vector<int>>& queries) {

        int n = s.length();

        int cnt1 = count(s.begin(), s.end(), '1');

        vector<int> zeroBlocks;
        vector<int> blockLeft;
        vector<int> blockRight;


        int i = 0;

        while (i < n) {
            int st = i;

            while (i < n && s[i] == s[st]) {
                i++;
            }

            if (s[st] == '0') {
                zeroBlocks.push_back(i - st);
                blockLeft.push_back(st);
                blockRight.push_back(i - 1);
            }
        }


        int m = zeroBlocks.size();

        if (m < 2) {
            return vector<int>(queries.size(), cnt1);
        }


        vector<int> tmpSum(m - 1);

        for (int i = 0; i < m - 1; i++) {
            tmpSum[i] = zeroBlocks[i] + zeroBlocks[i + 1];
        }


        SegmentTree seg(tmpSum);

        vector<int> ans;


        for (auto &q : queries) {

            int l = q[0];
            int r = q[1];


            int leftBlock = lower_bound(blockRight.begin(),
                                        blockRight.end(),
                                        l) - blockRight.begin();


            int rightBlock = upper_bound(blockLeft.begin(),
                                         blockLeft.end(),
                                         r) - blockLeft.begin() - 1;



            if (leftBlock >= m || rightBlock < 0 || leftBlock >= rightBlock) {
                ans.push_back(cnt1);
                continue;
            }


            int firstLen = blockRight[leftBlock] -
                           max(blockLeft[leftBlock], l) + 1;


            int lastLen = min(blockRight[rightBlock], r) -
                          blockLeft[rightBlock] + 1;



            if (leftBlock + 1 == rightBlock) {

                int gain = firstLen + lastLen;

                ans.push_back(cnt1 + gain);

                continue;
            }



            int val1 = firstLen + zeroBlocks[leftBlock + 1];

            int val2 = zeroBlocks[rightBlock - 1] + lastLen;

            int val3 = seg.query(leftBlock + 1, rightBlock - 2);


            int bestGain = max({val1, val2, val3});


            ans.push_back(cnt1 + bestGain);
        }


        return ans;
    }
};