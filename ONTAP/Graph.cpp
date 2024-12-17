#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

// C?u tr�c �? th?
typedef struct Graph {
    int vertices;            // S? d?nh
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];  // Ma tr?n k?
} Graph;

// Kh?i t?o d? th?
void initGraph(Graph* g, int vertices) {
    g->vertices = vertices;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            g->adjMatrix[i][j] = 0; // Kh?i t?o ma tr?n k? v?i 0
        }
    }
}

// Th�m c?nh v�o d? th?
void addEdge(Graph* g, int src, int dest, bool isDirected) {
    g->adjMatrix[src][dest] = 1;
    if (!isDirected) {
        g->adjMatrix[dest][src] = 1; // N?u l� d? th? kh�ng hu?ng
    }
}

// Hi?n th? ma tr?n k?
void displayGraph(Graph* g) {
    printf("Ma tran ke cua do thi:\n");
    for (int i = 0; i < g->vertices; i++) {
        for (int j = 0; j < g->vertices; j++) {
            printf("%d ", g->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

// Thu?t to�n DFS - Duy?t d? th? theo chi?u s�u
void DFSUtil(Graph* g, int vertex, bool visited[]) {
    printf("%d ", vertex); // In d?nh hi?n t?i
    visited[vertex] = true; // ��nh d?u d� tham d?nh n�y

    // Duy?t t?t c? c�c d?nh k?
    for (int i = 0; i < g->vertices; i++) {
        if (g->adjMatrix[vertex][i] == 1 && !visited[i]) {
            DFSUtil(g, i, visited); // �? quy DFS
        }
    }
}

void DFS(Graph* g, int startVertex) {
    bool visited[MAX_VERTICES] = { false }; // Kh?i t?o t?t c? d?nh chua du?c tham
    printf("Duyet do thi theo chieu sau (DFS): ");
    DFSUtil(g, startVertex, visited);
    printf("\n");
}

// Thu?t to�n BFS - Duy?t d? th? theo chi?u r?ng
void BFS(Graph* g, int startVertex) {
    bool visited[MAX_VERTICES] = { false }; // Kh?i t?o t?t c? d?nh chua du?c tham
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;

    // Th�m d?nh b?t d?u v�o h�ng d?i v� d�nh d?u d� tham
    queue[rear++] = startVertex;
    visited[startVertex] = true;

    printf("Duyet do thi theo chieu rong (BFS): ");

    while (front < rear) {
        int currentVertex = queue[front++]; // L?y d?nh t? h�ng d?i
        printf("%d ", currentVertex);

        // Duy?t t?t c? c�c d?nh k?
        for (int i = 0; i < g->vertices; i++) {
            if (g->adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                queue[rear++] = i; // Th�m v�o h�ng d?i
                visited[i] = true; // ��nh d?u d� tham
            }
        }
    }
    printf("\n");
}

// H�m ch�nh d? ki?m tra c�c ch?c nang
int main() {
    Graph g;
    int vertices, edges, src, dest, startVertex;
    bool isDirected;

    printf("Nhap so dinh cua do thi: ");
    scanf("%d", &vertices);
    initGraph(&g, vertices);

    printf("Do thi co huong hay khong (1: Co huong, 0: Khong huong)? ");
    scanf("%d", &isDirected);

    printf("Nhap so canh cua do thi: ");
    scanf("%d", &edges);

    printf("Nhap cac canh theo dinh nguon va dinh dich (src dest):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &src, &dest);
        addEdge(&g, src, dest, isDirected);
    }

    displayGraph(&g);

    printf("Nhap dinh bat dau cho DFS va BFS: ");
    scanf("%d", &startVertex);

    DFS(&g, startVertex); // Duy?t d? th? theo chi?u s�u
    BFS(&g, startVertex); // Duy?t d? th? theo chi?u r?ng

    return 0;
}

