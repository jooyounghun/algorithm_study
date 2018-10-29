//
//  main.cpp
//  DFS
//
//  Created by younghun joo on 2018. 10. 29..
//  Copyright © 2018년 younghun joo. All rights reserved.
//

#include <iostream>

using namespace std;

int n;
int map[30][30], visit[30];

void DFS(int v)
{
    int i;
    
    visit[v] = 1;
    for(i=1;i<=n; i++)
    {
        if(map[v][i] == 1 && !visit[i])
        {
            cout << v << "에서 " << i << "로 이동" << endl;
            DFS(i);
        }
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    int start;
    int v1, v2;
    
    cin >> n >> start;
    
    while(1)
    {
        cin >> v1 >> v2;
        if(v1 == -1 && v2 == -1)
        {
            break;
        }
        map[v1][v2] = map[v2][v1] = 1;
    }
    
    DFS(start);
    
    return 0;
}
