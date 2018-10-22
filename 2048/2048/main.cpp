//
//  main.cpp
//  2048
//
//  Created by younghun joo on 2018. 10. 19..
//  Copyright © 2018년 younghun joo. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> make_board(int n);
void go(vector<vector<int>> board, int num);
void up(vector<vector<int>> board, int num);
void down(vector<vector<int>> board, int num);
void left(vector<vector<int>> board, int num);
void right(vector<vector<int>> board, int num);

vector<int> max_collect;

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    int input;
    cin >> input;
    vector<vector<int>> board;
    
    board = make_board(input);
    
    int start_num = 0;
    
    go(board,start_num);
    
    int max_num = max_collect[0];
    
    for(int i=0; i<max_collect.size(); i++)
    {
        if(max_collect[i] >= max_num)
        {
            max_num = max_collect[i];
        }
    }
    
    cout << max_num << endl;
    
    
    return 0;
}



vector<vector<int>> make_board(int n)
{
    vector<int> tmp;
    vector<vector<int>> tmp1;
    int *input = new int[n];
    
    for(int i=0; i<n; i++)
    {
        tmp.push_back(0);
    }
    
    for(int i=0; i<n; i++)
    {
        tmp1.push_back(tmp);
    }
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> input[j];
            tmp1[i][j] = input[j];
        }
    }
    
    return tmp1;
}

void go(vector<vector<int>> board, int num)
{
    up(board,num);
    
    down(board,num);
    
    left(board,num);
    
    right(board,num);
    
}


void up(vector<vector<int>> board, int num)
{
    if(num++ != 5)
    {
    
    int *bin = new int[board.size()];
        for(int i=0; i<board.size(); i++)
        {
            bin[i] = 0;
        }
    
    // 1행 과 2행 비교
    for(int i=0; i<board.size()-1; i++)
    {
        for(int j=0; j<board.size(); j++)
        {
            // 빈칸(0)이 어디까지인지
            
            // 빈칸이라면
            if(board[i][j] == 0)
            {
                bin[j] = i+1;
                continue;
            }
            // 빈칸이 아니라면
            else
            {
                // 같으면
                if(board[i][j] == board[i+1][j])
                {
                    board[i][j] = board[i][j]*2;
                    for(int k=i+1; k<board.size()-1; k++)
                    {
                        board[k][j] = board[k+1][j];
                    }
                    board[board.size()-1][j] = 0;
                }
                // 다르면
                else
                {
                    continue;
                }
            }
            
        }
    }
    
    for(int i=0; i<board.size(); i++)
    {
        for(int j=0; j<board.size(); j++)
        {
            if(i>=bin[j])
            {
                continue;
            }
            
            board[i][j] = board[bin[j]][j];
            board[bin[j]][j] = 0;
        }
    }
        
        
        go(board,num);
        
    }
    // 5번재 일때.
    else
    {
        // 처음부터 시작.
        int max = board[0][0];
        
        
        for(int i=0; i<board.size(); i++)
        {
            for(int j=0; j<board.size(); j++)
            {
                if(board[i][j] >= max)
                {
                    max = board[i][j];
                }
            }
        }
        max_collect.push_back(max);
        return;
    }
    
}

void down(vector<vector<int>> board, int num)
{
    if(num++ != 5)
    {
        
        int *bin = new int[board.size()];
        for(int i=0; i<board.size(); i++)
        {
            bin[i] = 0;
        }
        
        // 1행 과 2행 비교
        for(int i=board.size()-1; i>0; i--)
        {
            for(int j=0; j<board.size(); j++)
            {
                // 빈칸(0)이 어디까지인지
                
                // 빈칸이라면
                if(board[i][j] == 0)
                {
                    bin[j] = i+1;
                    continue;
                }
                // 빈칸이 아니라면
                else
                {
                    // 같으면
                    if(board[i][j] == board[i-1][j])
                    {
                        board[i][j] = board[i][j]*2;
                        for(int k=i-1; k>0; k--)
                        {
                            board[k][j] = board[k-1][j];
                        }
                        board[0][j] = 0;
                    }
                    // 다르면
                    else
                    {
                        continue;
                    }
                }
                
            }
        }
        
        for(int i=0; i<board.size(); i++)
        {
            for(int j=0; j<bin[i]-1; j++)
            {
                
                board[j][i] = 0;
            }
        }
        
        
        go(board,num);
        
    }
    // 5번재 일때.
    else
    {
        // 처음부터 시작.
        int max = board[0][0];
        
        
        for(int i=0; i<board.size(); i++)
        {
            for(int j=0; j<board.size(); j++)
            {
                if(board[i][j] >= max)
                {
                    max = board[i][j];
                }
            }
        }
        max_collect.push_back(max);
        return;
    }
}

void left(vector<vector<int>> board, int num)
{
    if(num++ != 5)
    {
        
        int *bin = new int[board.size()];
        for(int i=0; i<board.size(); i++)
        {
            bin[i] = 0;
        }
        
        // 1열 과 2열 비교
        for(int i=0; i<board.size(); i++)
        {
            for(int j=0; j<board.size()-1; j++)
            {
                // 빈칸(0)이 어디까지인지
                
                // 빈칸이라면
                if(board[i][j] == 0)
                {
                    bin[j] = j+1;
                    continue;
                }
                // 빈칸이 아니라면
                else
                {
                    // 같으면
                    if(board[i][j] == board[i][j+1])
                    {
                        board[i][j] = board[i][j]*2;
                        for(int k=j+1; k<board.size()-1; k++)
                        {
                            board[i][k] = board[i][k+1];
                        }
                        board[i][board.size()-1] = 0;
                    }
                    // 다르면
                    else
                    {
                        continue;
                    }
                }
                
            }
        }
        
        for(int i=0; i<board.size(); i++)
        {
            for(int j=bin[i]-1; j<board.size(); j++)
            {
                board[i][j] = 0;
            }
        }
        
        
        go(board,num);
        
    }
    // 5번재 일때.
    else
    {
        // 처음부터 시작.
        int max = board[0][0];
        
        
        for(int i=0; i<board.size(); i++)
        {
            for(int j=0; j<board.size(); j++)
            {
                if(board[i][j] >= max)
                {
                    max = board[i][j];
                }
            }
        }
        max_collect.push_back(max);
        return;
    }
    
}

void right(vector<vector<int>> board, int num)
{
    if(num++ != 5)
    {
        
        int *bin = new int[board.size()];
        for(int i=0; i<board.size(); i++)
        {
            bin[i] = 0;
        }
        
        // 1열 과 2열 비교
        for(int i=0; i<board.size(); i++)
        {
            for(int j=board.size()-1; j>0; j--)
            {
                // 빈칸(0)이 어디까지인지
                
                // 빈칸이라면
                if(board[i][j] == 0)
                {
                    bin[j] = j+1;
                    continue;
                }
                // 빈칸이 아니라면
                else
                {
                    // 같으면
                    if(board[i][j] == board[i][j-1])
                    {
                        board[i][j] = board[i][j]*2;
                        for(int k=j-1; k>0; k--)
                        {
                            board[i][k] = board[i][k-1];
                        }
                        board[i][0] = 0;
                    }
                    // 다르면
                    else
                    {
                        continue;
                    }
                }
                
            }
        }
        
        for(int i=0; i<board.size(); i++)
        {
            for(int j=0; j<bin[i]; j++)
            {
                board[i][j] = 0;
            }
        }
        
    
        
        go(board,num);
        
    }
    // 5번재 일때.
    else
    {
        // 처음부터 시작.
        int max = board[0][0];
        
        
        for(int i=0; i<board.size(); i++)
        {
            for(int j=0; j<board.size(); j++)
            {
                if(board[i][j] >= max)
                {
                    max = board[i][j];
                }
            }
        }
        max_collect.push_back(max);
        return;
    }
    
}

