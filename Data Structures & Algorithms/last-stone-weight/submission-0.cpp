class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int stone: stones) pq.push(stone);
        while(pq.size()>1){
            int a,b;
            a=pq.top();
            pq.pop();
            b=pq.top();
            pq.pop();
            if(a==b) continue;
            else pq.push(abs(a-b));
        }
        return (pq.empty()? 0: pq.top());
    }
};
