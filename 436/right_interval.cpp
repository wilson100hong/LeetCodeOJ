/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    bool comparePair(const pair<int, int>& p1, const pair<int,int>& p2) {
        // compre start
        return p1.first < p2.first;
    }

    int findRightIndex(
            const vector<Interval>& intervals,
            const vector<pair<int, int>>& pairs,
            int target) {
        // find index of interval with smallest start >= target
        int left = 0, right = intervals.size()-1;
        while (left < right) {
            int med = (left + right) / 2;
            int start = pairs[med].first;
            if (start < target) {
                left = med + 1;
            } else {
                right = med;
            }
        }
        if (pairs[left].first < target) return -1;
        return pairs[right].second;
    }

    vector<int> findRightInterval(vector<Interval>& intervals) {
        vector<pair<int, int>> pairs;
        int index =0;
        for (const Interval& i : intervals) {
            pairs.emplace_back(i.start, index++);
        }
        sort(pairs.begin(), pairs.end());
        vector<int> result;
        for (int i=0;i<intervals.size();++i) {
            int end = intervals[i].end;
            int right = findRightIndex(intervals, pairs, end);
            result.push_back(right);
        }
        return result;
    }
};
