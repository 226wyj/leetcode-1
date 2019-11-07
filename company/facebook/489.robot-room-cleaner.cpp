/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the
 * cell.
 *     // Returns false if the cell in front is blocked and robot stays in the
 * current cell. bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */
class Solution {
public:
    vector<vector<int>> dirs = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };
    void cleanRoom(Robot& robot)
    {
        unordered_set<string> visited;
        dfs(robot, 0, 0, 0, visited);
    }

    void dfs(
        Robot& robot, int x, int y, int dir, unordered_set<string>& visited)
    {
        robot.clean();
        visited.insert(to_string(x) + "-" + to_string(y));
        for (int i = 0; i < 4; ++i) {
            int curr = (i + dir) % 4, newX = x + dirs[curr][0],
                newY = y + dirs[curr][1];
            if (!visited.count(to_string(newX) + "-" + to_string(newY))
                && robot.move()) {
                dfs(robot, newX, newY, curr, visited);
                robot.turnRight();
                robot.turnRight();
                robot.move();
                robot.turnLeft();
                robot.turnLeft();
            }
            robot.turnRight();
        }
    }
};
