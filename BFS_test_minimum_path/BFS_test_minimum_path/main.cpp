//
//  main.cpp
//  BFS_test_minimum_path
//
//  Created by younghun joo on 2018. 10. 24..
//  Copyright © 2018년 younghun joo. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std;


struct Node
{
    int x;
    int y;
    int length;
};

int map[6][6];
queue<Node> Q;
vector<int> min_num;
int cnt;

void BFS(int x, int y)
{
    
    
    
    // 시작 지점은 지나간 경로 표시한다.
    map[x][y] = 0;
    Node start;
    start.x = x;
    start.y = y;
    start.length = 1;
    int length = 1;
    Q.push(start);
    
    while(Q.size() != 0 && (x != 5 || y != 5))
    {
        map[x][y] = 0;
        // 위로 갈 수 있는 경우
        if(map[x-1][y] == 1 && ((0<=x-1 && x-1 < 6) && (0<=y && y < 6)))
        {
            Node up;
            up.x = x-1;
            up.y = y;
            up.length = length+1;
            Q.push(up);
            min_num.push_back(length+1);
            
        }
        // 아래
        if(map[x+1][y] == 1 && ((0<=x+1 && x+1 < 6) && (0<=y && y < 6)))
        {
            Node down;
            down.x = x+1;
            down.y = y;
            down.length = length+1;
            Q.push(down);
            min_num.push_back(length+1);
        }
        // 왼
        if(map[x][y-1] == 1 && ((0<=x && x < 6) && (0<=y-1 && y-1 < 6)))
        {
            Node left;
            left.x = x;
            left.y = y-1;
            left.length = length+1;
            Q.push(left);
            min_num.push_back(length+1);
        }
        // 오른
        if(map[x][y+1] == 1 && ((0<=x && x < 6) && (0<=y+1 && y+1 < 6)))
        {
            Node right;
            right.x = x;
            right.y = y+1;
            right.length = length+1;
            Q.push(right);
            min_num.push_back(length+1);
        }
        
        Q.pop();
        x = Q.front().x;
        y = Q.front().y;
        length = Q.front().length;
        cnt++;
    }
    
    cout << min_num.back() << endl;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    for(int i=0; i<6; i++)
    {
        for(int j=0; j<6; j++)
        {
            cin >> map[i][j];
        }
    }
    
    // Start Point (x,y)
    
    int x, y;
    
    
    
    BFS(x,y);
    
    
    return 0;
}
