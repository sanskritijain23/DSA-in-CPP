/*
Problem: Maximum Distance After Moves
Platform: LeetCode Weekly Contest
Topic: Math, Simulation

Approach:
- Track the horizontal and vertical displacement after processing all moves.
- Count the number of wildcard ('_') moves separately.
- The maximum Manhattan distance is obtained by using every wildcard move
  in the direction that increases the current distance.
- Hence, answer = |horizontal| + |vertical| + wildcardCount.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int maxDistance(string moves) {
        int h=0,v=0,u=0;
        for(char s : moves){
            if(s=='U')    v--;
            if(s=='L')    h--;
            if(s=='D')    v++;
            if(s=='R')    h++;
            if(s=='_')    u++;

        }
        return abs(v)+abs(h)+u;

    }
};