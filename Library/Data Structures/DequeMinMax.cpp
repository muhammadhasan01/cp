template<typename T>
struct DequeMin {
    deque<T> dq;

    bool isEmpty() {
        return dq.empty();
    }

    void add(T x) {
        while (!dq.empty() && dq.back() > x) {
            dq.pop_back();
        }
        dq.emplace_back(x);
    }

    void remove(T x) {
        if (dq.empty() || dq.front() != x) {
            return;
        }
        dq.pop_front();
    }

    T getMin() {
        return dq.front();
    }
};

template<typename T>
struct DequeMax {
    deque<T> dq;

    bool isEmpty() {
        return dq.empty();
    }

    void add(T x) {
        while (!dq.empty() && dq.back() < x) {
            dq.pop_back();
        }
        dq.emplace_back(x);
    }

    void remove(T x) {
        if (dq.empty() || dq.front() != x) {
            return;
        }
        dq.pop_front();
    }

    T getMax() {
        return dq.front();
    }
};