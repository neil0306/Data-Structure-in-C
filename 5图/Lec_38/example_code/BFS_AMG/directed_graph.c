#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

#define MAX 100

struct AMG_Graph      // Adjacency Matrix Graph
{
    int vex_num, edge_num;

    char Vex[MAX];
    int Edge[MAX][MAX];
};

struct AMG_Graph * create_AMG(void);
void Show_AMG(struct AMG_Graph * graph);
int search_vex(struct AMG_Graph * graph, char ch);
void BFS_AMG(struct AMG_Graph * graph);             // 广度优先遍历

int main(void)
{
    struct AMG_Graph * d_graph;      // 无向图指针
    d_graph = create_AMG();
    Show_AMG(d_graph);

    printf("Traverse the graph through BFS:\n");
    BFS_AMG(d_graph);

    return 0;
}

struct AMG_Graph * create_AMG(void)
{
    struct AMG_Graph * graph = NULL;
    int i = 0, j = 0;
    char u,v;

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
        }
    }

    while(graph->edge_num--){           // 图有几条边, 就录入几次
        printf("Please enter the vex that connect each other by edge:\n");
        u = getchar();
        while(getchar() != '\n');
        v = getchar();
        while(getchar() != '\n');

        // 确认输入字符的节点编号
        i = search_vex(graph, u);
        j = search_vex(graph, v); 

        if(i != -1 && j != -1){
            graph->Edge[i][j] = 1;       // 无向图和有向图邻接矩阵代码的唯一区别
        }
        else{
            printf("You've enter a wrong vex, please enter again.");
            graph->edge_num++;      // 重置一下当前减掉的次数
        }
    }

    return graph;
}

void Show_AMG(struct AMG_Graph * graph)
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

void BFS_AMG(struct AMG_Graph * graph)
{
    int visited[MAX] = {0};             // 辅助数组, 标记当前节点是否被访问过: 0未访问, 1已访问
    int u;                              // 出队列的节点编号
    int i;                              // 控制循环的变量i

    printf("%c ", graph->Vex[0]);       // 图的起始节点
    visited[0] = 1;                     // 标记起点已访问

    enqueue(0);                         // 将起点入队列

    while(!isEmpty()){
        u = dequeue();                          // 将队列第一个元素出队
        for(i = 0; i < graph->vex_num; i++){    // 遍历邻接矩阵中的第u行(其实等价于查询一次所有顶点), 找到该元素的"未被访问的邻接点", 并将他们入队
            if((graph->Edge[u][i] == 1) && (visited[i] == 0)){  // i是邻接点, 并且i没有被访问过时
                visited[i] = 1;                 // 标记为已访问
                enqueue(i);                     // 将该邻接点入队列
                printf("%c ", graph->Vex[i]);   // 输出当前节点
            }
        }
    }

    printf("\n");
}
