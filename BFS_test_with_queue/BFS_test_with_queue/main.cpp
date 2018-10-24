//
//  main.cpp
//  BFS_test_with_queue
//
//  Created by younghun joo on 2018. 10. 24..
//  Copyright © 2018년 younghun joo. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std;

int n;
int visit[30];
int map[30][30];
queue<int> Q;

void BFS(int v)
{
    int i;
    visit[v] = 1;
    
    printf("%d에서 시작\n",v);
    
    Q.push(v);
    while(!Q.empty()) // 비어있을 때까지 루프 실행
    {
        v = Q.front();
        Q.pop();
        for(int i=1; i<=n; i++)
        {
            if(map[v][i] == 1 && !visit[i])
            {
                visit[i] = 1;
                printf("%d에서 %d로 이동\n",v,i);
                Q.push(i);
            }
        }
    }
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    int start;
    int v1,v2;
    
    cin >> n >> start;
    
    while(1)
    {
        scanf("%d%d", &v1, &v2);
        if(v1 == -1 && v2 == -1) break;
        map[v1][v2] = map[v2][v1] = 1;
    }
    BFS(start);

    
    return 0;
}
