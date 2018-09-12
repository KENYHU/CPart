/**
 * Created by dekai on 2018/9/12.
 *
 * 数据结构 图 - 储存方法：邻接矩阵&邻接表
 *
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAXVEX 100
#define INFINITY 65535

typedef char VertexType;
typedef int EdgeType;

typedef struct {
    VertexType vexs[MAXVEX];
    EdgeType arc[MAXVEX][MAXVEX];
    int numVertexes,numEdges;  /* 图中的顶点数和边数 */
}MGraph;

/**
 * @about 邻接矩阵初始化
 *
 * 步骤简要：
    1. 定义一个MAXVEX ，即数组的长度
    2. INFINITY 65535  ，表示无穷大，即如有两个顶点间没有连接关系，以此表示
    3. 定义一个struct中有两个数组 ，第一个数组vexs 是所有顶点的数组，第二个数组arc表示顶点与顶点对应关系的表示数组。
    4. 第一步，先将所有的顶点scanf输入到vexs中。一定要注意顺序。
    5. 初始化arc 数组，就是 将所有的内容都置为INFINITY
    6. 依次读取i行j列的值w，且注意i行j列的值和j行i列是相等的，因为无向图是矩阵对称的。
 * @param G  struct MGraph
 */
void CreateMGraph( MGraph *G ) {
    printf("输入顶点和边数：\n");

    //获取顶点数和边数
    scanf("%d %d",&G->numVertexes,&G->numEdges);
    for( int i = 0;i <G->numVertexes;i++ ) {
        scanf("%c",&G->vexs[i]);
    }

    //初始化 所有矩阵的值为最大值
    for (int j = 0; j < G->numVertexes; ++j) {
        for (int i = 0; i < G->numVertexes; ++i) {
            G->arc[i][j] = INFINITY;
        }
    }

    int vi,vj,vw;
    //读入numEdges条边 建立邻接矩阵
    for (int k = 0; k < G->numEdges; ++k) {
        printf("输入边(vi,vj)上的下标i和下标j和权值w:\n");
        scanf("%d %d %d",&vi,&vj,&vw);
        G->arc[i][j] = w;
        G->arc[j][i] = w;
    }

}

/**
 * @about   邻接表初始化
 *
 * 步骤简要：
    1. 首先数据结构的定义上，稍微的复杂了些。
        GraphAdjList-图

        （ 顶点数-numVertexes，边数-numEdges，【 下一行 】 ）
            （ 顶点域的值-data，顶点的头指针-fristedge 【 下一行 】）
                （ 链接的顶点的下标-adjvex，数值也可为权值-weight，指向的下一个顶点-EdgeNode *next )

    2. 根据输入的顶点数，将顶点数组的所有fristedge置空，进行初始化
    3. 输入两个数，即任意边（vi,vj）的两个下标，然后我们利用头插法，进行链表链接。（ 头插法，就是在链表的头部进行数据插入，此处利用头插法的好处显而易见，不需要循环next到表尾，非常好用。 ）
        且请注意，以vi为头的边表中存在vj，对于【无向图】（且仅仅对于无向图）来说，vj为头的边表中同样存在v。
 */

typedef struct EdgeNode {
    int adjvex;                 //邻接点域，储存该顶点对应的下标
    EdgeType weight;            //对于储存权值，对于非网图可以不需要
    struct EdgeNode *next;      //链域，指向下一个邻接点
}EdgeNode;

typedef struct VertexNode {
    VertexType data;            //顶点域，储存顶点信息
    EdgeNode *fristedge;        //边表头指针
}VertexNode,AdjList[MAXVEX];

typedef struct {
    AdjList adjList;
    int numVertexes;        //顶点数
    int numEdges;           //边数
}GraphAdjList;

void CreateALGraph( GraphAdjList *G ) {

    int i,j,k;

    EdgeNode *e;
    printf("输入顶点数和边数：\n");
    scanf("%d %d",&G->numVertexes,&G->numEdges); //输入顶点数和边数
    for( int i=0;i<G->numVertexes;++i ) {
        scanf(&G->adjList[i].fristedge = NULL);
    }

    for (int l = 0; l < G->numEdges; ++l) {
        printf("请输入边（vi,vj）上的顶点序号：\n");
        scanf("%d %d",&i,&j);

        e = (EdgeNode * )malloc(sizeof(EdgeNode));
        e->adjvex = j;
        e->next = G->adjList[i].fristedge;
        G->adjList[i].fristedge = e;

        e = (EdgeNode * )malloc(sizeof(EdgeNode));
        e->adjvex = i;
        e->next = G->adjList[j].fristedge;
        G->adjList[j].fristedge = e;

    }

}

