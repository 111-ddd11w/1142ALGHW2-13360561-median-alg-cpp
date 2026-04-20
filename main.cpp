// ------------------------------
// 1. 求中位數
// ------------------------------
double findMedian(vector<int> values) {
    // 1. 排序
    sort(values.begin(), values.end());

    // 2. 取得筆數
    int n = values.size();

    // 3 & 4. 判斷奇偶
    if (n % 2 == 1) {
        return values[n / 2]; // 奇數
    } else {
        return (values[n / 2 - 1] + values[n / 2]) / 2.0; // 偶數
    }
}

// ------------------------------
// 2. 求加權中位數
// ------------------------------
int findWeightedMedian(vector<Item> items) {
    // 1. 依 x 排序
    sort(items.begin(), items.end(), [](Item a, Item b) {
        return a.x < b.x;
    });

    // 2. 印排序結果
    printSortedValues(items);

    // 3. 累積權重
    double cumulativeWeight = 0.0;

    cout << "\nStep-by-step cumulative weights:\n";

    // 4. 逐一累加
    for (const auto& item : items) {
        cumulativeWeight += item.w;

        cout << "x=" << item.x 
             << ", w=" << fixed << setprecision(2) << item.w
             << ", cumulative=" << cumulativeWeight << "\n";

        // 找到第一個 >= 0.5
        if (cumulativeWeight >= 0.5) {
            return item.x;
        }
    }

    // 5. 防呆
    return -1;
}
