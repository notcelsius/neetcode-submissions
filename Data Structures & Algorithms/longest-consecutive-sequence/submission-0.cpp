class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> seq;
        int longestSeq = 0;
        for (int num: nums) {
            seq.insert(num);
        }
        for (int num: seq) {
            
            
            // start of a seq
            if (seq.count(num-1) == 0) {
                int seqLength = 1;
                while (seq.count(num+1) > 0) {
                    seqLength++;
                    num++;
                }
                longestSeq = max(seqLength, longestSeq);
            }
        }
        return longestSeq;
    }
};
