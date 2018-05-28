/*questions:
There are a total of n courses you have to take, labeled from 0 to n-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

Example 1:

Input: 2, [[1,0]] 
Output: true
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: 2, [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0, and to take course 0 you should
             also have finished course 1. So it is impossible.
             */
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        int s = prerequisites.size();
        // initializing the array
        int **a = new int* [numCourses];
        for(int i=0;i<numCourses;i++) a[i] = new int [numCourses];
        for(int i=0;i<numCourses;i++)
            for(int j=0;j<numCourses;j++)
                a[i][j]=0;
        
        for(int i=0;i<s;i++){
            int first = prerequisites[i].first;
            int second = prerequisites[i].second;
            if(a[first][second] == -1 || a[second][first] == 1) return false;
            a[first][second] = 1;
            a[second][first] = -1;
            for(int j=0;j<numCourses;j++){
                if(j!=second && a[first][j] == -1){
                    if(a[j][second] == -1 || a[second][j] == 1) return false;
                    a[j][second] = 1;
                    a[second][j] = -1;
                }
            }
        }
        return true;

    }
};