```c++

vector<T> result; // 结果集

void backtrack(...) {
    if 当前问题解决 {
        result.push_back(解)；
        return;
    }
    for 选择 of 选择列表 {
        做出选择
        backtrack(...)
        撤销选择
    }
}
```
> 该模板会求解出所有的目标解，存储于结果集中


```c++
vector<T> result; // 结果集

bool backtrack(...) {
    if 当前问题解决 {
        result.push_back(解);
        return true;
    }
    for 选择 of 选择列表 {
        做出选择
        if backtrack(...) {
            return true;
        }
        撤销选择
    }
}
```
> 该模板返回第一个符合条件的解