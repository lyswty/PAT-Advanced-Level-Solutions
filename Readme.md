浙江大学PAT甲级的C++解答
审题是第一位，例如一些模拟题，一定要看清楚截止条件，是否包括截止时间。
用cin和cout输入输出会比printf和scanf慢，可以用cin.tie(0);和ios::sync_with_stdio(false);来关闭cin与cout的同步，cin与scanf的同步解决，但是如果使用了iomanip来格式化输出，即使关闭了上面的同步速度也比printf慢了太多。
不要把题目中给的用例数据想当然地带入到自己写的代码中。
时刻注意数的最大值，特别是第一道20分题，很容易出现必须用long long来表示的情况。
活用STL容器和algorithm库。unordered_map和unordered_set用hash表实现，时间复杂度为O(1)；map和set底层用红黑树实现，时间复杂度为O(logn)。因此在不需要排序的情况下，用unordered_map的速度会快很多。algorithm库中有二分查找、集合运算、反转等各种函数，可以大大节省时间。
sstream库可以很方便地进行字符串切割和类型转换。
做题时需要考虑所给数据量为0的情况。
