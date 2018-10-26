//
//  main.cpp
//  BFS_practice
//
//  Created by younghun joo on 2018. 10. 26..
//  Copyright © 2018년 younghun joo. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;


struct Node
{
    int x;
    int y;
    int length;
};

int board[30][30];
queue<Node> Q;
vector<int> L;


void go(int x, int y)
{
    // x,y 가 첫 시작.
    
    // 마지막 도착점이 5,5이다.
    
    // 지나간 경로는 표시한다.
    board[x][y] = 0;
    
    // 처음 시작을 queue에 넣는다.
    Node tmp;
    tmp.x = x;
    tmp.y = y;
    tmp.length = 1;
    
    Q.push(tmp);
    
    int length = 1;
    
    while(!(x == 5 && y == 5) && Q.empty() != 1)
    {
        board[x][y] = 0;
        // 갈 수 있는 곳을 찾는다.
        // 위
        if(board[x-1][y] == 1 && (0<= x-1 && x-1 < 6))
        {
            tmp.x = x-1;
            tmp.y = y;
            tmp.length = length+1;
            
            Q.push(tmp);
        }
        // 아래
        if(board[x+1][y] == 1 && (0<= x+1 && x+1 < 6))
        {
            tmp.x = x+1;
            tmp.y = y;
            tmp.length = length+1;
            
            Q.push(tmp);
        }
        // 왼
        if(board[x][y-1] == 1 && (0<= y-1 && y-1 < 6))
        {
            tmp.x = x;
            tmp.y = y-1;
            tmp.length = length+1;
            
            Q.push(tmp);
        }
        // 오른
        if(board[x][y+1] == 1 && (0<= y+1 && y+1 < 6))
        {
            tmp.x = x;
            tmp.y = y+1;
            tmp.length = length+1;
            
            Q.push(tmp);
        }
        
        L.push_back(Q.front().length);
        // 쓴거는 빼고.
        Q.pop();
        
        if(Q.empty() == 1)
        {
            break;
        }
        
        // 새것을 넣는다.
        x = Q.front().x;
        y = Q.front().y;
        length = Q.front().length;
        
        
        
    }
    
    cout << "최단 길이는: " << length << endl;
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    // 자연수 입력 n*n 행렬
    int input;
    cin >> input;
    
    // 배열에 값 넣기
    for(int i=0; i<input; i++)
    {
        for(int j=0; j<input; j++)
        {
            cin >> board[i][j];
        }
    }
    
    go(0,0);
    
    
    
    
    return 0;
}
