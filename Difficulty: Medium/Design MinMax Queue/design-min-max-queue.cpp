class SpecialQueue {
    queue<int> q;
    deque<int> minQ, maxQ;
public:
    void enqueue(int x) {
        q.push(x);

        while (!minQ.empty() && minQ.back() > x) minQ.pop_back();
        minQ.push_back(x);

        while (!maxQ.empty() && maxQ.back() < x) maxQ.pop_back();
        maxQ.push_back(x);
    }

    void dequeue() {
        if (q.empty()) return;
        int val = q.front();
        q.pop();
        if (!minQ.empty() && minQ.front() == val) minQ.pop_front();
        if (!maxQ.empty() && maxQ.front() == val) maxQ.pop_front();
    }

    int getFront() {
        return q.front();
    }

    int getMin() {
        return minQ.front();
    }

    int getMax() {
        return maxQ.front();
    }
};
