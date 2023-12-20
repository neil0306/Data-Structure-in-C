#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// ====================== 结构体定义 =======================
struct AdjNode                  // Adjacency Node, 邻接点表里的节点
{
    int index;
    struct AdjNode * next;      // 指向下一个邻接点
};

struct VexNode
{
    char node;                   // 存放顶点信息(数据部分)
    struct AdjNode * first;      // 指向下一个邻接点的指针(邻接点表里的东西)
};

struct ALG_Graph      // Adjacency List Graph
{
    int vex_num, edge_num;      // 顶点个数, 边的数量

    struct VexNode Vex[MAX];    // 顶点表, 这是一个结构体数组, 每一个元素都是一个单链表
};


// ====================== 函数声明 ======================
struct ALG_Graph * Create_ALG(void);                                    // 创建邻接表
int search_vex(struct ALG_Graph * graph, char ch);                      // 在顶点表中索引直接节点编号
void create_adj_node_list(struct ALG_Graph * graph, int i, int j);      // 创建邻接点表
void Show_ALG(struct ALG_Graph *graph);

int main(void)
{
    struct ALG_Graph * d_graph;
    d_graph = Create_ALG();

    Show_ALG(d_graph);
    return 0;
}

struct ALG_Graph * Create_ALG(void)
{
    struct ALG_Graph *graph;
    int i, j;
    char u, v;

    graph = (struct ALG_Graph*) malloc(sizeof(struct ALG_Graph));       // 分配空间, 创建邻接表

    // --------------- 创建 & 初始化 "节点表" 部分 --------------------------
    printf("Please enter the number of vertex: ");
    scanf("%d", &graph->vex_num);

    printf("Please enter the number of edges: ");
    scanf("%d", &graph->edge_num);

    while(getchar() != '\n');           // 清掉回车
    printf("Please enter the vertex:\n");
    for(i = 0; i < graph->vex_num; i++){
        graph->Vex[i].node = getchar();
        while(getchar() != '\n');       // 清掉回车
    }

    // 初始化graph的邻接点指针为NULL, 方便后续赋值
    for(i = 0; i < graph->vex_num; i++){
        graph->Vex[i].first = NULL;
    }

    // ---------------- 创建 & 完善 "邻接点表" 部分 ----------------------------
    while(graph->edge_num--){           // 图有几条边, 就录入几次
        printf("Please enter the vex that connect each other by edge:\n");
        u = getchar();
        while(getchar() != '\n');
        v = getchar();
        while(getchar() != '\n');

        // 在节点表中确认输入字符的节点编号
        i = search_vex(graph, u);
        j = search_vex(graph, v); 

        if(i != -1 && j != -1){
            // 构建邻接点表
            create_adj_node_list(graph, i, j);

        }
        else{
            printf("You've enter a wrong vex, please enter again.");
            graph->edge_num++;      // 重置一下当前减掉的次数
        }
    }

    return graph;
}

int search_vex(struct ALG_Graph * graph, char ch)
{
    int i;
    for(i = 0; i < graph->vex_num; i++){
        if (ch == graph->Vex[i].node){          // 匹配节点数据
            return i;
        }
    }
    return -1;
}

void create_adj_node_list(struct ALG_Graph * graph, int i, int j)
{
    // 创建 & 初始化 新节点 (这是在图结构中, 顶点 i 指向的下一个节点)
    struct AdjNode * s = (struct AdjNode *) malloc(sizeof(struct AdjNode));
    s->index = j;                   // 注意: i 是出发点, j 是到达点
    s->next = graph->Vex[i].first;  // 初始化节点

    graph->Vex[i].first = s;        // 将i节点的 first指针 指向 编号为j 的节点

    /*
    过程解析:
        假设现在的节点是a, 与a连接的节点有 b, c, e 三个. (abcd 对应编号 01234)
            录入的顺序为: 
                a,b   (编号 0,1)
                a,c   (编号 0,2)
                a,e   (编号 0,4)
                需要特别注意: 我们在录入图信息的时候, 已经规定是"从a开始录入, 并且连接的节点按照编号从小到大"的顺序 (顺序输入)
            
        那么此时有如下过程:
            首次调用函数时, i为0, j为1; 
                创建节点s, s的index设置为1, s的next初始化为 NULL(因为此时graph->Vex[i].first为NULL)
                    然后 graph->Vex[i].first指向 节点s  (完成了 a->b 这个连接)       
                    此时邻接点表的单链表为 a->b
            
            第二次调用函数时, i为0, j为2;
                创建节点s, s的index设置为2, s的next初始化为 "编号为1的节点的地址" (指向节点b)
                    然后 graph->Vex[i].first指向 节点s (完成 a->c 这个连接)
                    此时邻接点表的单链表为 a->c->b
            
            第三次调用函数时, i为0, j为4
                创建节点s, s的index设置为1, s的next初始化为 "编号为2的节点的地址" (指向节点c)
                    然后 graph->Vex[i].first指向 节点s (完成 a->e 这个连接)
                    此时邻接点表的单链表为 a->e->c->b
            
            不难发现, 此时创建的邻接点表符合了 "按照节点编号的逆序存放" 的规则.
                即: 顺序输入, 逆序存放.
    */      
}

void Show_ALG(struct ALG_Graph *graph)
{
    int i = 0;
    struct AdjNode * temp;     // 用来遍历邻接点表(单链表节点)
    printf("Show the ALG Graph:\n");

    for(i = 0; i < graph->vex_num; i++){
        // 打印节点
        printf("%c: ", graph->Vex[i].node);

        // 打印邻接点表内的节点(遍历单链表)
        temp = graph->Vex[i].first;
        while(temp != NULL){
            printf("%d ", temp->index);
            temp = temp->next;
        }

        printf("\n");
    }

}