class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> cars;
        for(int i=0;i<position.size();i++){
            cars.push_back({position[i],speed[i]});
        }
        sort(cars.begin(),cars.end(),comp);

        stack<double> stack;
        for(int i=0;i<cars.size();i++){
            double curTime = getTime(target,cars[i].first,cars[i].second);
            if(stack.empty() || curTime > stack.top())
                stack.push(curTime);
        }

        return stack.size();

    }
    double getTime(int target,int pos,int speed){
        return (double)(target-pos)/speed;
    }
    static bool comp(pair<int,int>p1,pair<int,int>p2){
        if(p1.first!=p2.first)
            return p1.first>p2.first;
        return p1.second>p2.second;
    }
};
