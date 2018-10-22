//
//  main.cpp
//  bubble_game2
//
//  Created by younghun joo on 2018. 10. 18..
//  Copyright © 2018년 younghun joo. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

vector<vector<string>> make_2_arr(int n, int m);
int r_n, r_m, b_n, b_m, h_n, h_m;
vector<int> min_arr;

void go(vector<vector<string>> board, int redn, int redm, int bluen, int bluem, int holen, int holem, int min_num);
int up(vector<vector<string>> board, int redn, int redm, int bluen, int bluem, int holen, int holem, int min_num);
int down(vector<vector<string>> board, int redn, int redm, int bluen, int bluem, int holen, int holem, int min_num);
int left(vector<vector<string>> board, int redn, int redm, int bluen, int bluem, int holen, int holem, int min_num);
int right(vector<vector<string>> board, int redn, int redm, int bluen, int bluem, int holen, int holem, int min_num);


int main(int argc, const char * argv[]) {
    
    int n, m;
    cin >> n >> m;
    
    vector<vector<string>> board;
    
    board = make_2_arr(n,m);
    int min_num = 0;
    
    go(board,r_n,r_m,b_n,b_m,h_n,h_m,min_num);
    
    int tmp;
    if(min_arr.size() == 0)
    {
        cout << "-1" << endl;
        return -1;
    }
    else
    {
        tmp = min_arr[0];
        for(int i =0; i<min_arr.size()-1; i++)
        {
            if(tmp > min_arr[i+1])
            {
                tmp = min_arr[i+1];
            }
        }
    }
    cout << tmp << endl;
    return tmp;
}


vector<vector<string>> make_2_arr(int n, int m)
{
    vector<string> m_col;
    vector<vector<string>> n_col;

    for(int i=0; i<m; i++)
    {
        m_col.push_back("#");
    }
    
    for(int i=0; i<n; i++)
    {
        n_col.push_back(m_col);
    }
    
    string temp;
    
    for(int i=0; i<n; i++)
    {
        string tmp;
        cin >> tmp;
        
        for(int j=0; j<m; j++)
        {
            temp = tmp.substr(j,1);
            n_col[i][j] = temp;
            
            if(temp == "R")
            {
                r_n = i;
                r_m = j;
            }
            else if(temp == "B")
            {
                b_n = i;
                b_m = j;
            }
            else if(temp == "O")
            {
                h_n = i;
                h_m = j;
            }
        }
    }
    
    return n_col;
}


void go(vector<vector<string>> board, int redn, int redm, int bluen, int bluem, int holen, int holem, int min_num)
{
    
    // 위
    if(board[redn-1][redm] != "#" || board[bluen-1][bluem] != "#")
    {
        up(board,redn,redm,bluen,bluem,holen,holem,min_num);
    }
    // 아래
    if(board[redn+1][redm] != "#" || board[bluen+1][bluem] != "#")
    {
        down(board,redn,redm,bluen,bluem,holen,holem,min_num);
    }
    // 왼
    if(board[redn][redm-1] != "#" || board[bluen][bluem-1] != "#")
    {
        left(board,redn,redm,bluen,bluem,holen,holem,min_num);
    }
    // 오른
    if(board[redn][redm+1] != "#" || board[bluen][bluem+1] != "#")
    {
        right(board,redn,redm,bluen,bluem,holen,holem,min_num);
    }
}

int up(vector<vector<string>> board, int redn, int redm, int bluen, int bluem, int holen, int holem, int min_num)
{
    if(min_num > 10)
    {
        return  -1;
    }
    min_num++;
    bool red = true;
    bool blue = true;
    int temp;
    bool success = false;
    bool fail = false;
    
    int tt = 0;
    int hh = 0;
    
    while(red)
    {
        tt++;
        // 빨강색 구멍 만남
        if(((redn-tt) == holen && redm == holem))
        {
            red = false;
            temp = 1;
            success = true;
        }
        
        // 빨강색 벽 만남
        if(board[redn-tt][redm] == "#")
        {
            red = false;
        }
        
    }
    
    while(blue)
    {
        hh++;
        
        // 파랑색 구멍 만남
        if(((bluen-hh) == holen && bluem == holem))
        {
            blue = false;
            temp = 0;
            fail = true;
        }
        
        // 파랑색 벽 만남
        if(board[bluen-hh][bluem] == "#")
        {
            blue = false;
        }
    }
    
    // 같은 열일때
    if(redm == bluem)
    {
        // 빨강이 더 위
        if(redn > bluen)
        {
            redn -= (tt-1);
            bluen = (redn+1);
        }
        // 파랑이 더 위
        else
        {
            bluen -= (hh-1);
            redn = (bluen+1);
        }
    }
    // 다른 열
    else
    {
        redn -= (tt-1);
        bluen -= (hh-1);
    }
    
    
    // 성공
    if(success && !fail)
    {
        min_arr.push_back(min_num);
        return min_num;
    }
    // 실패
    else if(fail)
    {
        return -1;
    }
    // 중간
    else
    {
        go(board,redn,redm,bluen,bluem,holen,holem,min_num);
    }
    
    
    return 2;
}

int down(vector<vector<string>> board, int redn, int redm, int bluen, int bluem, int holen, int holem,int min_num)
{
    if(min_num > 10)
    {
        return  -1;
    }
    min_num++;
    bool red = true;
    bool blue = true;
    int temp;
    bool success = false;
    bool fail = false;
    
    int tt = 0;
    int hh = 0;
    
    while(red)
    {
        tt++;
        // 빨강색 구멍 만남
        if(((redn+tt) == holen) && (redm == holem))
        {
            red = false;
            temp = 1;
            success = true;
        }
        
        // 빨강색 벽 만남
        if(board[redn+tt][redm] == "#")
        {
            red = false;
        }
        
    }
    
    while(blue)
    {
        hh++;
        
        // 파랑색 구멍 만남
        if(((bluen+hh) == holen && bluem == holem))
        {
            blue = false;
            temp = 0;
            fail = true;
        }
        
        // 파랑색 벽 만남
        if(board[bluen+hh][bluem] == "#")
        {
            blue = false;
        }
    }
    
    // 같은 열일때
    if(redm == bluem)
    {
        // 빨강이 더 아래
        if(redn > bluen)
        {
            redn += (tt-1);
            bluen = (redn-1);
        }
        // 파랑이 더 아래
        else
        {
            bluen += (hh-1);
            redn = (bluen-1);
        }
    }
    // 다른 열
    else
    {
        redn += (tt-1);
        bluen += (hh-1);
    }
    
    
    // 성공
    if(success && !fail)
    {
        min_arr.push_back(min_num);
        return min_num;
    }
    // 실패
    else if(fail)
    {
        return -1;
    }
    // 중간
    else
    {
        go(board,redn,redm,bluen,bluem,holen,holem,min_num);
    }
    
    
    return 2;
}

int left(vector<vector<string>> board, int redn, int redm, int bluen, int bluem, int holen, int holem, int min_num)
{
    if(min_num > 10)
    {
        return  -1;
    }
    min_num++;
    bool red = true;
    bool blue = true;
    int temp;
    bool success = false;
    bool fail = false;
    
    int tt = 0;
    int hh = 0;
    
    while(red)
    {
        tt++;
        // 빨강색 구멍 만남
        if(((redm-tt) == holem) && (redn == holen))
        {
            red = false;
            temp = 1;
            success = true;
        }
        
        // 빨강색 벽 만남
        if(board[redn][redm-tt] == "#")
        {
            red = false;
        }
        
    }
    
    while(blue)
    {
        hh++;
        
        // 파랑색 구멍 만남
        if(((bluem-hh) == holem) && (bluen == holen))
        {
            blue = false;
            temp = 0;
            fail = true;
        }
        
        // 파랑색 벽 만남
        if(board[bluen][bluem-hh] == "#")
        {
            blue = false;
        }
    }
    
    // 같은 행일때
    if(redn == bluen)
    {
        // 빨강이 더 왼
        if(redm < bluem)
        {
            redm -= (tt-1);
            bluem = (redm+1);
        }
        // 파랑이 더 왼
        else
        {
            bluem -= (hh-1);
            redm = (bluem+1);
        }
    }
    // 다른 행
    else
    {
        redm -= (tt-1);
        bluem -= (hh-1);
    }
    
    
    // 성공
    if(success && !fail)
    {
        min_arr.push_back(min_num);
        return min_num;
    }
    // 실패
    else if(fail)
    {
        return -1;
    }
    // 중간
    else
    {
        go(board,redn,redm,bluen,bluem,holen,holem,min_num);
    }
    
    
    return 2;
}

int right(vector<vector<string>> board, int redn, int redm, int bluen, int bluem, int holen, int holem, int min_num)
{
    if(min_num > 10)
    {
        return  -1;
    }
    min_num++;
    bool red = true;
    bool blue = true;
    int temp;
    bool success = false;
    bool fail = false;
    
    int tt = 0;
    int hh = 0;
    
    while(red)
    {
        tt++;
        // 빨강색 구멍 만남
        if(((redm+tt) == holem) && (redn == holen))
        {
            red = false;
            temp = 1;
            success = true;
        }
        
        // 빨강색 벽 만남
        if(board[redn][redm+tt] == "#")
        {
            red = false;
        }
        
    }
    
    while(blue)
    {
        hh++;
        
        // 파랑색 구멍 만남
        if(((bluem+hh) == holem) && (bluen == holen))
        {
            blue = false;
            temp = 0;
            fail = true;
        }
        
        // 파랑색 벽 만남
        if(board[bluen][bluem+hh] == "#")
        {
            blue = false;
        }
    }
    
    // 같은 행일때
    if(redn == bluen)
    {
        // 빨강이 더 오른
        if(redm < bluem)
        {
            redm += (tt-1);
            bluem = (redm-1);
        }
        // 파랑이 더 오른
        else
        {
            bluem += (hh-1);
            redm = (bluem-1);
        }
    }
    // 다른 행
    else
    {
        redm += (tt-1);
        bluem += (hh-1);
    }
    
    
    // 성공
    if(success && !fail)
    {
        min_arr.push_back(min_num);
        return min_num;
    }
    // 실패
    else if(fail)
    {
        return -1;
    }
    // 중간
    else
    {
        go(board,redn,redm,bluen,bluem,holen,holem,min_num);
    }
    
    
    return 2;
}
