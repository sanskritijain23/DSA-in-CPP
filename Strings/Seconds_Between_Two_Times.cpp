/*
Problem: Seconds Between Times
Platform: LeetCode Weekly Contest
Topic: Strings, Time Conversion

Approach:
- Convert both time strings (HH:MM:SS) into total seconds.
- Calculate total seconds as:
      hours × 3600 + minutes × 60 + seconds.
- Return the difference between end time and start time.

Time Complexity: O(1)
Space Complexity: O(1)
*/

class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {
        auto toSeconds = [](string t) {
            int h = stoi(t.substr(0, 2));
            int m = stoi(t.substr(3, 2));
            int s = stoi(t.substr(6, 2));
            return h * 3600 + m * 60 + s;
        };

        return toSeconds(endTime) - toSeconds(startTime);
    }
};