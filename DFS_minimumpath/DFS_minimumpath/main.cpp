//
//  main.cpp
//  DFS_minimumpath
//
//  Created by younghun joo on 2018. 10. 29..
//  Copyright © 2018년 younghun joo. All rights reserved.
//
#include <iostream>
#include <stack>

using namespace std;

// 노드 구조 하나 만들고,
struct Node
{
    int x;
    int y;
    int length;
};

// DFS는 스택을 사용한다.
stack<Node> S;
int n; // n*n 배열을 만들때 n
int map[10][10];
int mini;

void DFS(int x, int y, int l)
{
        // 지나간 경로 0으로 만든다.
        map[x][y] = 0;
        
        // 도착 경로에 갈 때까지 계속한다.
        if(x == n-1 && y == n-1)
        {
            if(mini > l) mini = l;
            map[x][y] = 1;
            return;
        }
        
    // 위 가능하다면/
    if((0<=x-1 && x-1<n) && map[x-1][y] != 0)
    {
        DFS(x-1,y,l+1);
    }
    // 왼 가능/
    if((0<=y-1 && y-1<n) && map[x][y-1] != 0)
    {
        DFS(x,y-1,l+1);
    }
    // 아래 가능/
    if((0<=x+1 && x+1<n) && map[x+1][y] != 0)
    {
        DFS(x+1,y,l+1);
    }
    
    // 오른 가능/
    if((0<=y+1 && y+1<n) && map[x][y+1] != 0)
    {
        DFS(x,y+1,l+1);
    }
        
        map[x][y] = 1;
    
    
}


int main()
{
    // 2차원 배열을 만든다.
    cin >> n;
    //int map[n][n]; // 요즘엔 이게 되네
    mini = n*n;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> map[i][j];
        }
    }
    
    // 시작은 0,0 에서 한다.
    DFS(0,0,1);
    
    cout << "최단 거리: " << mini << endl;
    
    return 0;
}

