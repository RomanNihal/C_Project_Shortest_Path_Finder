#include <stdio.h>
#include <time.h>
#include <limits.h>
#define V 8
int minDistance(int dist[], int sptSet[]){
    int min = INT_MAX, min_index;
    for (int i = 0; i < V; i++)
        if (sptSet[i] == 0 && dist[i] <= min)
            min = dist[i], min_index = i;
    return min_index;
}
void printPath(int parent[], int i, char c[8][10]){
    if (parent[i]==-1)
        return;
    printPath(parent, parent[i], c);
    printf("-> %s", c[i]);
}
int printSolution(int dist[], int n, int parent[], char c[8][10], int dest){
    loading(2);
    int src = 0;
    printf("\n\tFrom    --    To\t\tDistance\t\tPath\n");
    for (int i = 1; i < V; i++){
        if(i==dest-1){
            printf("\n\t%s -> %s \t\t %d\t\t%s ", c[src], c[i], dist[i], c[src]);
            printPath(parent, i, c);
        }
    }
}
void dijkstra(int graph[V][V], int src, char c[8][10], int dest){
    int dist[V];
    int sptSet[V];
    int parent[V];
    for (int i=0; i<V; i++){
        parent[0] = -1;
        dist[i] = INT_MAX;
        sptSet[i] = 0;
    }
    dist[src] = 0;
    for (int i=0; i<V-1; i++){
        int u = minDistance(dist, sptSet);
        sptSet[u] = 1;
        for (int v = 0; v < V; v++)
            if (sptSet[v]==0 && graph[u][v] && dist[u] + graph[u][v] < dist[v]){
                parent[v]  = u;
                dist[v] = dist[u] + graph[u][v];
            }
    }
    printSolution(dist, V, parent, c, dest);
}
int Dhanmondi(){
    system("cls");
    loading(2);
    int choice, dest;
    system("COLOR 09");
    animation("\n\tEnter Your Destination Area:\n");
    printf("\n\t1. Farmgate\t");
    printf("2. Shahbag\t");
    printf("3. Pilkhana\t");
    printf("4. Mogbazar\n\t");
    printf("5. Gulistan\t");
    printf("6. Motijheel\t");
    printf("7. Sayedabad\n");
    printf("\n\tEnter Your Choice: ");
    choice = getche();
    switch(choice){
        case '1': dest = 2;
        break;
        case '2': dest = 3;
        break;
        case '3': dest = 6;
        break;
        case '4': dest = 4;
        break;
        case '5': dest = 5;
        break;
        case '6': dest = 8;
        break;
        case '7': dest = 7;
        break;
        default: {
            animation("\n\n\t###### WRONG INPUT ######\n");
            main();
        };
	}
	system("cls");
	char c[8][10] = {"Dhanmondi", "Farmgate", "Shahabagh", "Mogbazar", "Gulistan", "Pilkhana", "Sayedabad", "Motijheel"};
	int graph[V][V] = {
        { 0, 8, 5, 0, 0, 4, 0, 0 },
        { 8, 0, 4, 3, 0, 0, 0, 0 },
        { 5, 4, 0, 2, 3, 5, 0, 0 },
        { 0, 3, 2, 0, 2, 0, 0, 6 },
        { 0, 0, 3, 2, 0, 6, 3, 0 },
        { 4, 0, 5, 0, 6, 0, 5, 0 },
        { 0, 0, 0, 0, 3, 5, 0, 3 },
        { 0, 0, 0, 6, 0, 0, 3, 0 }
        };
    dijkstra(graph, 0, c, dest);
    printf("\n\n\n\n\n");
}
int Farmgate(){
    system("cls");
    loading(2);
    int choice, dest;
    system("COLOR 09");
    animation("\n\tEnter Your Destination Area:\n");
    printf("\n\t1. Dhanmondi\t");
    printf("2. Shahbag\t");
    printf("3. Pilkhana\t");
    printf("4. Mogbazar\n\t");
    printf("5. Gulistan\t");
    printf("6. Motijheel\t");
    printf("7. Sayedabad\n");
    printf("\n\tEnter Your Choice: ");
    choice = getche();
    switch(choice){
        case '1': dest = 8;
        break;
        case '2': dest = 2;
        break;
        case '3': dest = 5;
        break;
        case '4': dest = 3;
        break;
        case '5': dest = 4;
        break;
        case '6': dest = 7;
        break;
        case '7': dest = 6;
        break;
        default: {
            animation("\n\n\t###### WRONG INPUT ######\n");
            main();
        };
	}
	system("cls");
	char c[8][10] = {"Farmgate", "Shahabagh", "Mogbazar", "Gulistan", "Pilkhana", "Sayedabad", "Motijheel", "Dhanmondi"};
	int graph[V][V] = {
        { 0, 4, 3, 0, 0, 0, 0, 8 },
        { 4, 0, 2, 3, 5, 0, 0, 5 },
        { 3, 2, 0, 2, 0, 0, 6, 0 },
        { 0, 3, 2, 0, 6, 3, 0, 0 },
        { 0, 5, 0, 6, 0, 5, 0, 4 },
        { 0, 0, 0, 3, 5, 0, 3, 0 },
        { 0, 0, 6, 0, 0, 3, 0, 0 },
        { 8, 5, 0, 0, 4, 0, 0, 0 }
        };
    dijkstra(graph, 0, c, dest);
    printf("\n\n\n\n\n");
}
int Shahbag(){
    system("cls");
    loading(2);
    int choice, dest;
    system("COLOR 09");
    animation("\n\tEnter Your Destination Area:\n");
    printf("\n\t1. Dhanmondi\t");
    printf("2. Farmgate\t");
    printf("3. Pilkhana\t");
    printf("4. Mogbazar\n\t");
    printf("5. Gulistan\t");
    printf("6. Motijheel\t");
    printf("7. Sayedabad\n");
    printf("\n\tEnter Your Choice: ");
    choice = getche();
    switch(choice){
        case '1': dest = 7;
        break;
        case '2': dest = 8;
        break;
        case '3': dest = 4;
        break;
        case '4': dest = 2;
        break;
        case '5': dest = 3;
        break;
        case '6': dest = 6;
        break;
        case '7': dest = 5;
        break;
        default: {
            animation("\n\n\t###### WRONG INPUT ######\n");
            main();
        };
	}
	system("cls");
	char c[8][10] = {"Shahabagh", "Mogbazar", "Gulistan", "Pilkhana", "Sayedabad", "Motijheel", "Dhanmondi", "Farmgate"};
	int graph[V][V] = {
        { 0, 2, 3, 5, 0, 0, 5, 4 },
        { 2, 0, 2, 0, 0, 6, 0, 3 },
        { 3, 2, 0, 6, 3, 0, 0, 0 },
        { 5, 0, 6, 0, 5, 0, 4, 0 },
        { 0, 0, 3, 5, 0, 3, 0, 0 },
        { 0, 6, 0, 0, 3, 0, 0, 0 },
        { 5, 0, 0, 4, 0, 0, 0, 8 },
        { 4, 3, 0, 0, 0, 0, 8, 0 }
        };
    dijkstra(graph, 0, c, dest);
    printf("\n\n\n\n\n");
}
int Pilkhana(){
    system("cls");
    loading(2);
    int choice, dest;
    system("COLOR 09");
    animation("\n\tEnter Your Destination Area:\n");
    printf("\n\t1. Dhanmondi\t");
    printf("2. Farmgate\t");
    printf("3. Shahbag\t");
    printf("4. Mogbazar\n\t");
    printf("5. Gulistan\t");
    printf("6. Motijheel\t");
    printf("7. Sayedabad\n");
    printf("\n\tEnter Your Choice: ");
    choice = getche();
    switch(choice){
        case '1': dest = 4;
        break;
        case '2': dest = 5;
        break;
        case '3': dest = 6;
        break;
        case '4': dest = 7;
        break;
        case '5': dest = 8;
        break;
        case '6': dest = 3;
        break;
        case '7': dest = 2;
        break;
        default: {
            animation("\n\n\t###### WRONG INPUT ######\n");
            main();
        };
	}
	system("cls");
	char c[8][10] = {"Pilkhana", "Sayedabad", "Motijheel", "Dhanmondi", "Farmgate", "Shahabagh", "Mogbazar", "Gulistan"};
	int graph[V][V] = {
        { 0, 5, 0, 4, 0, 5, 0, 6 },
        { 5, 0, 3, 0, 0, 0, 0, 3 },
        { 0, 3, 0, 0, 0, 0, 6, 0 },
        { 4, 0, 0, 0, 8, 5, 0, 0 },
        { 0, 0, 0, 8, 0, 4, 3, 0 },
        { 5, 0, 0, 5, 4, 0, 2, 3 },
        { 0, 0, 6, 0, 3, 2, 0, 2 },
        { 6, 3, 0, 0, 0, 3, 2, 0 }
        };
    dijkstra(graph, 0, c, dest);
    printf("\n\n\n\n\n");
}
int Mogbazar(){
    system("cls");
    loading(2);
    int choice, dest;
    system("COLOR 09");
    animation("\n\tEnter Your Destination Area:\n");
    printf("\n\t1. Dhanmondi\t");
    printf("2. Farmgate\t");
    printf("3. Shahbag\t");
    printf("4. Pilkhana\n\t");
    printf("5. Gulistan\t");
    printf("6. Motijheel\t");
    printf("7. Sayedabad\n");
    printf("\n\tEnter Your Choice: ");
    choice = getche();
    switch(choice){
        case '1': dest = 6;
        break;
        case '2': dest = 7;
        break;
        case '3': dest = 8;
        break;
        case '4': dest = 1;
        break;
        case '5': dest = 2;
        break;
        case '6': dest = 5;
        break;
        case '7': dest = 4;
        break;
        default: {
            animation("\n\n\t###### WRONG INPUT ######\n");
            main();
        };
	}
	system("cls");
	char c[8][10] = {"Mogbazar", "Gulistan", "Pilkhana", "Sayedabad", "Motijheel", "Dhanmondi", "Farmgate", "Shahabagh"};
	int graph[V][V] = {
        { 0, 2, 0, 0, 6, 0, 3, 2 },
        { 2, 0, 6, 3, 0, 0, 0, 3 },
        { 0, 6, 0, 5, 0, 4, 0, 5 },
        { 0, 3, 5, 0, 3, 0, 0, 0 },
        { 6, 0, 0, 3, 0, 0, 0, 0 },
        { 0, 0, 4, 0, 0, 0, 8, 5 },
        { 3, 0, 0, 0, 0, 8, 0, 4 },
        { 2, 3, 5, 0, 0, 5, 4, 0 }
        };
    dijkstra(graph, 0, c, dest);
    printf("\n\n\n\n\n");
}
int Gulistan(){
    system("cls");
    loading(2);
    int choice, dest;
    system("COLOR 09");
    animation("\n\tEnter Your Destination Area:\n");
    printf("\n\t1. Dhanmondi\t");
    printf("2. Farmgate\t");
    printf("3. Shahbag\t");
    printf("4. Pilkhana\n\t");
    printf("5. Mogbazar\t");
    printf("6. Motijheel\t");
    printf("7. Sayedabad\n");
    printf("\n\tEnter Your Choice: ");
    choice = getche();
    switch(choice){
        case '1': dest = 5;
        break;
        case '2': dest = 6;
        break;
        case '3': dest = 7;
        break;
        case '4': dest = 2;
        break;
        case '5': dest = 8;
        break;
        case '6': dest = 4;
        break;
        case '7': dest = 3;
        break;
        default: {
            animation("\n\n\t###### WRONG INPUT ######\n");
            main();
        };
	}
	system("cls");
	char c[8][10] = {"Gulistan", "Pilkhana", "Sayedabad", "Motijheel", "Dhanmondi", "Farmgate", "Shahabagh", "Mogbazar"};
	int graph[V][V] = {
        { 0, 6, 3, 0, 0, 0, 3, 2 },
        { 6, 0, 5, 0, 4, 0, 5, 0 },
        { 3, 5, 0, 3, 0, 0, 0, 0 },
        { 0, 0, 3, 0, 0, 0, 0, 6 },
        { 0, 4, 0, 0, 0, 8, 5, 0 },
        { 0, 0, 0, 0, 8, 0, 4, 3 },
        { 3, 5, 0, 0, 5, 4, 0, 2 },
        { 2, 0, 0, 6, 0, 3, 2, 0 },
        };
    dijkstra(graph, 0, c, dest);
    printf("\n\n\n\n\n");
}
int Motijheel(){
    system("cls");
    loading(2);
    int choice, dest;
    system("COLOR 09");
    animation("\n\tEnter Your Destination Area:\n");
    printf("\n\t1. Dhanmondi\t");
    printf("2. Farmgate\t");
    printf("3. Shahbag\t");
    printf("4. Pilkhana\n\t");
    printf("5. Mogbazar\t");
    printf("6. Gulistan\t");
    printf("7. Sayedabad\n");
    printf("\n\tEnter Your Choice: ");
    choice = getche();
    switch(choice){
        case '1': dest = 3;
        break;
        case '2': dest = 4;
        break;
        case '3': dest = 5;
        break;
        case '4': dest = 8;
        break;
        case '5': dest = 6;
        break;
        case '6': dest = 7;
        break;
        case '7': dest = 1;
        break;
        default: {
            animation("\n\n\t###### WRONG INPUT ######\n");
            main();
        };
	}
	system("cls");
	char c[8][10] = {"Sayedabad", "Motijheel", "Dhanmondi", "Farmgate", "Shahabagh", "Mogbazar", "Gulistan", "Pilkhana"};
	int graph[V][V] = {
        { 0, 0, 0, 0, 6, 0, 0, 3 },
        { 0, 0, 8, 5, 0, 0, 4, 0 },
        { 0, 8, 0, 4, 3, 0, 0, 0 },
        { 0, 5, 4, 0, 2, 3, 5, 0 },
        { 6, 0, 3, 2, 0, 2, 0, 0 },
        { 0, 0, 0, 3, 2, 0, 6, 3 },
        { 0, 4, 0, 5, 0, 6, 0, 5 },
        { 3, 0, 0, 0, 0, 3, 5, 0 }
        };
    dijkstra(graph, 0, c, dest);
    printf("\n\n\n\n\n");
}
int Sayedabad(){
    system("cls");
    loading(2);
    int choice, dest;
    system("COLOR 09");
    animation("\n\tEnter Your Destination Area:\n");
    printf("\n\t1. Dhanmondi\t");
    printf("2. Farmgate\t");
    printf("3. Shahbag\t");
    printf("4. Pilkhana\n\t");
    printf("5. Mogbazar\t");
    printf("6. Gulistan\t");
    printf("7. Motijheel\n");
    printf("\n\tEnter Your Choice: ");
    choice = getche();
    switch(choice){
        case '1': dest = 3;
        break;
        case '2': dest = 4;
        break;
        case '3': dest = 5;
        break;
        case '4': dest = 8;
        break;
        case '5': dest = 6;
        break;
        case '6': dest = 7;
        break;
        case '7': dest = 2;
        break;
        default: {
            animation("\n\n\t###### WRONG INPUT ######\n");
            main();
        };
	}
	system("cls");
	char c[8][10] = {"Sayedabad", "Motijheel", "Dhanmondi", "Farmgate", "Shahabagh", "Mogbazar", "Gulistan", "Pilkhana"};
	int graph[V][V] = {
        { 0, 3, 0, 0, 0, 0, 3, 5 },
        { 3, 0, 0, 0, 0, 6, 0, 0 },
        { 0, 0, 0, 8, 5, 0, 0, 4 },
        { 0, 0, 8, 0, 4, 3, 0, 0 },
        { 0, 0, 5, 4, 0, 2, 3, 5 },
        { 0, 6, 0, 3, 2, 0, 2, 0 },
        { 3, 0, 0, 0, 3, 2, 0, 6 },
        { 5, 0, 4, 0, 5, 0, 6, 0 }
        };
    dijkstra(graph, 0, c, dest);
    printf("\n\n\n\n\n");
}

void animation(char arr[]){
    int i=0;
    while(arr[i]!='\0'){
        delay(1);
		printf("%c ",arr[i++]);
	}
}
void delay(int time){
    int milli_seconds = 50 * time;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds);
}
void loading(int n){
    for(int i = 0; i<n; i++){
        printf("\n\tLOADING ");
        animation("....");
        system("cls");
    }
}
int main(){
    system("cls");
    int choice;
    system("COLOR 09");
    animation("\n\t\t\t###### WELCOME ######\n\n");
    animation("\n\tEnter Your Current Area:\n");
    printf("\n\t1. Dhanmondi\t");
    printf("2. Farmgate\t");
    printf("3. Shahbag\t");
    printf("4. Pilkhana\n\t");
    printf("5. Mogbazar\t");
    printf("6. Gulistan\t");
    printf("7. Motijheel\t");
    printf("8. Sayedabad\n");
    printf("\n\tEnter Your Choice: ");
    choice = getche();
    switch(choice){
        case '1': Dhanmondi();
        break;
        case '2': Farmgate();
        break;
        case '3': Shahbag();
        break;
        case '4': Pilkhana();
        break;
        case '5': Mogbazar();
        break;
        case '6': Gulistan();
        break;
        case '7': Motijheel();
        break;
        case '8': Sayedabad();
        break;
        default: {
            animation("\n\n\t###### WRONG INPUT ######\n");
            main();
        };
	}
}
