```c++

vector<Node> result; // 结果集

vector<Node> visited; // 已访问集

vector<Node> path; // 路径集


void DFS(Node& node) {
    
    if node已经被访问 {
        // 表明路径中有环， 进一步排查 path即可确定形成
        // 环的是那几个节点
        return;
    }
    visited.push_back(node);
    path.push_back(node);
    if 当前节点 node 符合条件 {
        result.push_back(node);
    }
    for childNode of node {
        DFS(childNode);
    }
    path.pop(node);
}
```
> DFS的空间复杂度较小，但是时间复杂度较大，因为要遍历所有的路径
> 可以检测路径中是否有环；
> 后序遍历算法下的DFS可以解决拓扑排序问题；

```c++
// 拓扑排序

vector<Node> result; // 结果集

vector<Node> visited; // 已访问集

void typosort(Node& node) {
    if node 已经访问 || node == NULL {
        return;
    }
    visited.push_back(node);

    for childNode of node {
        typosort(childNode);
    }

    result.push_back(node);
}
// 将 result reverse后就是拓扑排序结果
```