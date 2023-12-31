# 图的应用 -- Floyd 算法(插点法)
这个算法的目的是求`最短路径`.


## 算法分析

假设有如下`网结构`:
![](图的应用_Floyd算法_images/Floyd算法使用的图结构.png)

对于这个`网`, 它的邻接矩阵构造规则如下: 
- 节点i -> 节点i (自到自己)在邻接矩阵中的值为0.
  - 即: `Edge[i][i] = 0`
- 有邻接边的位置填入边的`权值`
  - 即: `Edge[i][j] = 权值`
- 无邻接边的位置, 填入`无穷大`
  - 即: `Edge[i][j] = inf`, i, j无邻接边

算法需要借助如下"工具"
1. 最短路径矩阵 `dist`
    ```txt
    最短路径矩阵的每一个值是这个路径对应的最短距离.
    ```
2. 插入点
    ```txt
    插入点的定义:
        定义1:
            比如 a,b 两个节点没有路径可以直接抵达, 他们可以通过节点c来构成一条通路, 此时c就是 ab之间的 "插入点".

        定义2: 
            现在有节点i 和 节点j, 如果 
                dist[i][j] > dist[i][k] + dist[k][j]
            则 k节点 就是 i和j 之间的插入点.

            定义2 与 定义1其实是等价的, 定义1中无直接路径的两个点, 对应 disk[a][b] = inf, 为无穷大, 故一定有 dist[a][b] > dist[a][k] + dist[k][b]
        
        简单描述就是: 插入点可以让 "原有路径" 的距离变短.
    ```
3. 前趋点矩阵 `p`
    ```txt
    前趋点 在这里指的是路径的起始位置(也是箭头的"尾").

    前趋点矩阵的初始化构造规则:
        i -> i (自己指向自己): 矩阵的对应位置填 -1

        i -> j (有路径/有边): 矩阵的对应位置填 "尾结点编号"
            尾和头的定义是: 尾 -> 头  
    
        i -> j (无路径/无边): 矩阵的对应位置填 0
    
    算法开始时, 前趋点矩阵里的值是 "当前路径的尾结点".
        如 c->b 这个路径, 矩阵中对应 p[2][1] 的值就应该为 2 (对应节点c)

    算法结束时, 前趋点矩阵里的值是 "使得这个路径最短" 的插入点或尾结点.
        如 c,b 这两个节点之间的所有路径中, 通过计算可以知道, 走 c->a->b 比 c->b 的距离要短, 
        因此 前趋点矩阵在算法结束时有 p[2][1] = 0(对应a节点), 而不是2(对应c节点).
    ```

Floyd算法的过程是:
```txt
遍历每一个节点, 判断它是是否可以成为某个路径的插入点, 如果能作为插入点, 则更新前趋点矩阵和最短路径矩阵, 直到所有节点遍历结束.
    此时通过查询最短路径矩阵就能知道从 节点i 出发到 j节点 在图结构的最短路径是多长.
```

算法在执行时, 判断 `某个节点是否可作为插入点` 并 `更新最短路径矩阵`和`前趋点矩阵` 的过程(下面只展示遍历 a节点 的过程):
```txt
使用插入点的定义2: dist[i][j] > dist[i][k] + dist[k][j]

以前面的图结构为例, 寻找a节点是插入点的路径, 有如下过程:
k = 0: 
    此时寻找a节点的 "入边", 发现是 c->a, 因此c必定是"箭头尾", 所以此时需要观察的路径是 c->b 和 c->d (在代码中为遍历所有节点.)
使用插入点的定义进行比较(假设当前dist矩阵被初始化为邻接矩阵):
    对于路径 c->b:
        dist[2][1] = 5;  
        dist[2][0] + dist[0][1] = 3 + 1 = 4;
        故: dist[2][1] > dist[2][0] + dist[0][1]
        
        因此 a 是 c->b 路径的插入点 ===> 此时路径 c->b 的 "前趋点" 将更新为 "a->b的前趋点", 最短路径矩阵中 dist[2][1] 也应更新为 4
    
    对于路径 c->d:
        dist[2][3] = 8
        dist[2][0] + dist[0][3] = 3 + 4 = 7
        故: dist[2][3] > dist[2][0] + dist[0][3]

        因此 a 也是 c->d 路径的插入点 ====> 此时路径 c->d 的 "前趋点" 将更新为 "a->d的前趋点", 最短路径矩阵中 dist[2][3] 也应更新为 7
```
- 上述过程图示为:
    ![](图的应用_Floyd算法_images/Floyd执行过程分析_图示.png)

- 遍历完所有的节点之后, dist矩阵和p矩阵都会被迭代更新, 此时dist矩阵中inf的部分有相应的路径值(从没有路径 => 找到最短路径).


## 代码实现:
```c
#include <math.h>           // 表示无穷大的 INFINITY 需要使用这个库
#include <stdio.h>
#include <stdlib.h>

#define MAX 100
// =============== 结构体定义 ================

struct AMG_Graph      // Adjacency Matrix Graph
{
    int vex_num, edge_num;

    char Vex[MAX];
    int Edge[MAX][MAX];
};

// =============== 函数声明 ================
struct AMG_Graph * create_AMG(void);
void Show_AMG_dist_p(struct AMG_Graph * graph);
int search_vex(struct AMG_Graph * graph, char ch);
void Floyd(struct AMG_Graph *graph);

// =============== 辅助数组 ================
double dist[MAX][MAX];         // 最短路径数组
int p[MAX][MAX];               // 前趋点数组

// =============== main ===================
int main(void)
{
    struct AMG_Graph * d_graph;      // 有向图指针
    char start, end;                 // 需要查询的最短路径起始点和终止点
    int s,e;                         // 最短路径的起始和终止节点编号

    d_graph = create_AMG();
    Show_AMG_dist_p(d_graph);

    // 使用 Floyd 算法求最短距离
    Floyd(d_graph);
    printf("\n\nNow show the shortest distance matrix:\n");
    Show_AMG_dist_p(d_graph);

    printf("Please enter the start and end point:\n");
    scanf("%c %c", &start, &end);
    s = search_vex(d_graph, start);
    e = search_vex(d_graph, end);
    printf("The shortest distance between %c and %c is %.1f.\n", start, end, dist[s][e]);

    return 0;
}

// ================== 函数实现 =================
struct AMG_Graph * create_AMG(void)
{
    struct AMG_Graph * graph = NULL;
    int i = 0, j = 0;
    char u,v;
    double l = 0.0;     // 存放网结构的权重

    graph = (struct AMG_Graph *)malloc(sizeof(struct AMG_Graph));

    printf("Please enter the number of vertex: ");
    scanf("%d", &graph->vex_num);

    printf("Please enter the number of edges: ");
    scanf("%d", &graph->edge_num);

    while(getchar() != '\n');           // 清掉回车
    printf("Please enter the vertex:\n");
    for(i = 0; i < graph->vex_num; i++){
        graph->Vex[i] = getchar();
        while(getchar() != '\n');       // 清掉回车
    }

    // 初始化二维数组, 防止垃圾信息影响结果
    for(i = 0; i < graph->vex_num; i++){
        for(j = 0; j < graph->vex_num; j++){
            graph->Edge[i][j] = 0;

            // ============ 初始化辅助数组 ==========
            if(i == j){
                dist[i][j] = 0;
            }
            else{
                dist[i][j] = INFINITY;
            }
            p[i][j] = -1;      // i->i 的前趋点初始化为-1
        }
    }

    while(graph->edge_num--){           // 图有几条边, 就录入几次
        printf("Please enter the vex that connect each other by edge:\n");
        u = getchar();
        while(getchar() != '\n');
        v = getchar();
        while(getchar() != '\n');

        printf("Please enter the distance between the two vex:\n");
        scanf("%lf", &l);
        while(getchar() != '\n');

        // 确认输入字符的节点编号
        i = search_vex(graph, u);
        j = search_vex(graph, v); 

        if(i != -1 && j != -1){
            graph->Edge[i][j] = 1;   // 无向图和有向图邻接矩阵代码的唯一区别
            dist[i][j] = l;          // 最短路径数组赋值
            p[i][j] = i;             // 初始化时如果 i,j 之间有边的话, 前趋点此时就是i 
        }
        else{
            printf("You've enter a wrong vex, please enter again.");
            graph->edge_num++;      // 重置一下当前减掉的次数
        }
    }
    return graph;
}

void Show_AMG_dist_p(struct AMG_Graph * graph)
{
    int i,j;
    printf("Show the vex: ");
    for(i = 0; i < graph->vex_num; i++){
        printf("%c", graph->Vex[i]);
    }
    printf("\n");

    printf("Show the Adjacency matrices:\n");
    for(i = 0; i < graph->vex_num; i++){
        for(j = 0; j < graph->vex_num; j++){
            printf("%d\t", graph->Edge[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // 显式最短路径矩阵
    printf("show the distance matrix:\n");
    for(i = 0; i < graph->vex_num; i++){
        for(j = 0; j < graph->vex_num; j++){
            printf("%0.1f\t", dist[i][j]);            // %0.1f 表示显式一位小数
        }
        printf("\n");
    }
    printf("\n");

    // 显式前趋点矩阵
    printf("show the p matrix:\n");
    for(i = 0; i < graph->vex_num; i++){
        for(j = 0; j < graph->vex_num; j++){
            printf("%d\t", p[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int search_vex(struct AMG_Graph * graph, char ch)
{
    int i;
    for(i = 0; i < graph->vex_num; i++){
        if (ch == graph->Vex[i]){
            return i;
        }
    }
    return -1;
}


void Floyd(struct AMG_Graph *graph)
{
    /*
        遍历每一个顶点, 分别将他们作为插入点, 更新 dist矩阵 和 p矩阵.
    */

    int k;
    int i,j;
    // 遍历每一个顶点
    for(k = 0; k < graph->vex_num; k++){       
        // 遍历dist矩阵的每一个元素, 判断节点k是否能作为插入点, 如果可以, 则更新 dist矩阵 和 p矩阵
        for (i = 0; i < graph->vex_num; i++){
            for (j = 0; j < graph->vex_num; j++){
                if( dist[i][j] > dist[i][k] + dist[k][j] ){
                    dist[i][j] = dist[i][k] + dist[k][j];       // k节点可作为插入点, i,j 路径的最短距离应更新
                    p[i][j] = p[k][j];                          // 前趋点矩阵更新: 路径 i->j 的前趋点替换为 k->j 的前趋点
                }
            }
        }
    }
}
```

测试使用的图结构:
![](图的应用_Floyd算法_images/Floyd算法使用的图结构.png)

程序输出:
![](图的应用_Floyd算法_images/Floyd算法代码实现_程序输出.png)





