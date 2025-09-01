class Solution {
public:
    struct Class {
        int pass, total;
        double gain() const {
            return (double)(pass + 1) / (total + 1) - (double)pass / total;
        }
    };

    struct Compare {
        bool operator()(const Class& a, const Class& b) {
            return a.gain() < b.gain(); 
        }
    };

    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<Class, vector<Class>, Compare> pq;

        for (auto& c : classes) {
            pq.push({c[0], c[1]});
        }

        while (extraStudents--) {
            auto cur = pq.top(); pq.pop();
            cur.pass++;
            cur.total++;
            pq.push(cur);
        }

        double result = 0.0;
        while (!pq.empty()) {
            auto cur = pq.top(); pq.pop();
            result += (double)cur.pass / cur.total;
        }

        return result / classes.size();
    }
};
