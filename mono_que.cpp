// 单调队列（monotonic queue）是求解「滑动窗口最小、最大值」（sliding window minimum/maximum）等一类优化问题的数据结构
// 采用 std::deque 实现「滑动窗口最小值」
/*
deque 的常用接口（member function)
front, back
push_back, pop_back, push_front, pop_front
size, empty
*/

deque<pair<int, int>> que;
/*
n：序列长度
k：窗口长度
对于序列 a[0..n-1]，a[i] 的滑动滑动窗口最小值 window_min[i] 定义为 min{a[j] | max(0,i-k+1) <= j <= i}
mono_que 返回 max{window_min[i] | 0 <= i < n}
*/

int mono_que(int n, int k){
    int _max = INT_MIN;
    for(int i = 0; i < n; i++){
        int x = get(i); // get(i) 返回第 i 个元素，依问题而定
        while(que.size() && que.back().second >= x){    // 队列中元素严格递增
            que.pop_back();
        }
        que.push_back({i, x});
        while(que.front().first <= i - k){
            que.pop_front();
        }
        _max = max(_max, que.front().first);
    }
    return max;
}
