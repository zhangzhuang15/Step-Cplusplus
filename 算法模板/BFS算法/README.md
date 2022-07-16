```c++

vector<T> result; // 结果集

vector<Node> visited; // 已访问节点集


queue<Node> queue; // 节点队列

int step = 0; // 深度

int BFS(Node start, Node end) {
    // 其实节点入队
    queue.push(start);

    while(queue.size() > 0) {
        int size = queue.size();
        for(int i = 0; i < size; i++) {
            Node node = queue.font();
            queue.pop();
            if node没有被访问过 {
                visited.push(node);
            } 
            else {
                continue;
            }
            if node == end {  
                return step;
            }
            // 如果事先无法知道目标节点，只知道目标条件，
            // 则代码要修正为
            // if node 符合目标条件 { return step; }
            把 node 的相邻节点加入 queue中;
        }
        // 上一层节点遍历完了，该遍历下一层节点啦
        step++;
    }
    return -1; // 没有找到end
}
```
> BFS用于解决一节点到另一节点的最小问题，空间复杂度较大;
> 广度优先算法主要利用队列，不涉及到递归；



```c++
// 环形检测

queue<Node> queue;

vector<Node> nodelist; // 节点集

vector<Node> visited; // 已访问集

bool hasCircle() {
    从nodelist中取出 入度为 0 的节点，加入 queue中;

    while(queue.size() > 0) {
        Node node = queue.front();
        queue.pop();
        if node 没有被访问 {
            visited.push_back(node);
        } 
        else {
            continue;
        }
        // 如果这一步是将 node 加入结果集 result，
        // 那么最终 result 就是拓扑排序结果；
        // Amazing🎉🎉🎉
        访问 node; 
        将 node 节点的相邻节点入度 -1，将入度变成 0 的相邻节点
        加入到 queue中；
    }
    
    // 如果是没有环的，那么所有的节点都会被遍历到
    return visited.size() == nodelist.size();

    // nodelist 和 visited 差集，就是构成环形的节点
}
```