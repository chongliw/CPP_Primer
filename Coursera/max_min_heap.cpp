//
// Created by Chongli Wang on 10/29/15.
//

#include <iostream>
#include <fstream>
#include <queue>
#include <deque>

int factor(int n) {
    int num = 0;
    int tmp = n;
    for (int i = 2; i <= n; ++i) {
        bool first = true;
        while (!(tmp % i)) {
            if (first) {
                ++num;
                first = false;
            }
            tmp /= i;
        }
        if (tmp == 1)
            break;
    }
    return num;
}


template<typename _Tp>
bool less(_Tp i, _Tp j) {
    return (factor(i) < factor(j)) || (factor(i) == factor(j) && i < j);
};

template<typename _Tp>
class isLess {
public:
    bool operator()(_Tp i, _Tp j) {
        return less(i, j);
    }
};

template<typename _Tp>
class isGreater {
public:
    bool operator()(_Tp i, _Tp j) {
        return (i != j) && (!less(i, j));
    }
};

class Max_Min_heap {
    friend std::ostream &operator<<(std::ostream &os, Max_Min_heap &rhs);

public:
    void add(int x) {
        if (!minhp.empty() && less(x, max_in_minhp)) {
            minhp.push(x);
            resize();
            return;
        }
        if (!maxhp.empty() && less(min_in_maxhp, x)) {
            maxhp.push(x);
            resize();
            return;
        }
        if (maxhp.size() < minhp.size()) {
            maxhp.push(x);
            min_in_maxhp = x;
        }
        else {
            minhp.push(x);
            max_in_minhp = x;
        }
        resize();
    }

    const int &max() const {
        if (maxhp.empty())
            return max_in_minhp;
        else
            return maxhp.top();
    }

    const int &min() const {
        if (minhp.empty())
            return min_in_maxhp;
        else
            return minhp.top();
    }

    void delMinMax() {
        if (!maxhp.empty()) maxhp.pop();
        if (!minhp.empty()) minhp.pop();
        resize();
    }

private:
    int min_in_maxhp = 0;
    int max_in_minhp = 0;
    std::priority_queue<int, std::vector<int>, isLess<int>> maxhp;
    std::priority_queue<int, std::vector<int>, isGreater<int>> minhp;

    void resize() {
        std::deque<int> tmp;
        if (!minhp.empty() && !maxhp.empty()) return;
        if (minhp.size() + maxhp.size() < 2) return;
        if (minhp.empty()) {
            while (!maxhp.empty()) {
                tmp.push_front(maxhp.top());
                maxhp.pop();
            }
        }
        else {
            while (!minhp.empty()) {
                tmppush_back(minhp.top());
                minhp.pop();
            }
        }
        int i;
        for (i = 0; i < tmp.size() / 2; ++i){
            int num = tmp[i];
            maxhp.push(num);
        }
        minhp.push(tmp[i]);
        max_in_minhp = tmp[i - 1];
        min_in_maxhp = (tmp.size() > 1 ? tmp[i] : 0);
        for (; i < tmp.size(); ++i) {
            int num = tmp[i];
            maxhp.push(num);
        }
    }
};

std::ostream &operator<<(std::ostream &os, Max_Min_heap &rhs) {
    std::deque<int> tmp;
    while (!rhs.maxhp.empty()) {
        tmp.push_front(rhs.maxhp.top());
        rhs.maxhp.pop();
    }
    while (!rhs.minhp.empty()) {
        tmp.push_back(rhs.minhp.top());
        rhs.minhp.pop();
    }
    int i;
    for (i = 0; i < tmp.size() / 2; ++i) {
        rhs.minhp.push(tmp[i]);
        os << tmp[i] << " ";
    }
    for (; i < tmp.size(); ++i) {
        rhs.maxhp.push(tmp[i]);
        os << tmp[i] << " ";
    }
    return os;
}

int main() {
    std::ifstream fin("Coursera/heap.in");
    Max_Min_heap data;
    int num, sz = 10;
    fin >> num;
    for (int i = 0; i < num; ++i) {
        int cell;
        for (int j = 0; j < sz; ++j) {
            fin >> cell;
            data.add(cell);
        }
        std::cout << data.max() << " " << data.min() << std::endl;
        data.delMinMax();
    }
    fin.close();
    std::cout << data.min() << std::endl;
    return 0;
}