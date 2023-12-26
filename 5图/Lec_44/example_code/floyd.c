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
int p[MAX][MAX];            // 前趋点数组

// =============== main ===================
int main(void)
{
    struct AMG_Graph * d_graph;      // 有向图指针
    char start, end;
    int s,e;

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
            p[i][j] = -1;

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
        // 遍历dist矩阵的每一元素, 判断节点k是否能作为插入点, 如果可以, 则更新 dist矩阵 和 p矩阵
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