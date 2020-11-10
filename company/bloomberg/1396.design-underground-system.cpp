/*
 * @lc app=leetcode id=1396 lang=cpp
 *
 * [1396] Design Underground System
 */

// @lc code=start
class UndergroundSystem {
private:
  map<int, pair<string, int>> checkin; // id (startstation, checkin time)
  map<string, pair<int, int>>
      checkout; // route -> (total time, total passenger cnt)
public:
  UndergroundSystem() {}

  void checkIn(int id, string stationName, int t) {
    checkin[id] = {stationName, t};
  }

  void checkOut(int id, string stationName, int t) {
    string route = checkin[id].first + "-" + stationName;
    checkout[route].first += (t - checkin[id].second);
    checkout[route].second++;
  }

  double getAverageTime(string startStation, string endStation) {
    string route = startStation + "-" + endStation;
    return (double)checkout[route].first / checkout[route].second;
  }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
// @lc code=end
