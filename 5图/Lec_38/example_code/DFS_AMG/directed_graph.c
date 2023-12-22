#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

#define MAX 100

// =============== 定义结构体 ===============
struct AMG_Graph      // Adjacency Matrix Graph
{
    int vex_num, edge_num;

    char Vex[MAX];
    int Edge[MAX][MAX];
};

// ================ 函数声明 ================
struct AMG_Graph * create_AMG(void);
void Show_AMG(struct AMG_Graph * graph);
int search_vex(struct AMG_Graph * graph, char ch);
void DFS_AMG(struct AMG_Graph * graph);

// ================ main ==================
int main(void)
{
    struct AMG_Graph * d;      // 无向图指针
    d = create_AMG();
    Show_AMG(d);

    printf("Traverse the graph through DFS:\n");
    DFS_AMG(d);


    return 0;
}

// ================ 函数实现 ===================
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

void DFS_AMG(struct AMG_Graph * graph)
{
    int visited[MAX] = {0};         // 初始化辅助数组, 用于标记节点是否已经访问
    int i,j;                        // i用于遍历所有节点; j用于遍历邻接矩阵的某一行
    int u;                          // 存放栈顶元素(节点编号)

    // 考虑非连通情况: 遍历一次所有节点
    for (i = 0; i < graph->vex_num; i++){
        if(visited[i] == 0){
            // 处理第一个节点
            printf("%c ", graph->Vex[i]);
            visited[i] = 1;         // 标记为已访问
            push(i);

            // 循环处理后续节点
            while(!isEmpty()){
                // 检查栈顶元素对应的节点(只是检查, 并没有出栈!)
                u = stack[top -1];  // top -1 是因为 "top指向栈顶的下一个位置"

                // 遍历邻接矩阵中节点编号为 u 的那行, 找出 "第一个值为1 且 没有访问过的节点"
                for (j = 0; j < graph->vex_num; j++){
                    if((graph->Edge[u][j] == 1) && (visited[j] == 0)){
                        visited[j] = 1;     // 标记访问过
                        push(j);            // 入栈
                        printf("%c ", graph->Vex[j]);
                        break;              // 结束遍历邻接矩阵中当前行
                    }
                }

                // 访问到最深处时, 开始往回退 (关键代码!!!)
                if(j == graph->vex_num){    // j一定要走完邻接矩阵的一行才出栈, 这意味着: 如果节点 u 仍有未访问的邻接点时, u 不会出栈.
                    pop(); 
                }
            }
        }
    }
    printf("\n");
}
