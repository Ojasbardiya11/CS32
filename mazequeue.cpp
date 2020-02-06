//
//  main.cpp
//  CS32W_mazequeue
//
//  Created by Ojas Bardiya on 2/2/20.
//  Copyright © 2020 Ojas bardiya. All rights reserved.
//

#include <iostream>
#include <queue>
#include <string>
using namespace std;

class Coord
{
public:
    Coord(int rr, int cc) : m_r(rr), m_c(cc) {}
    int r() const { return m_r; }
    int c() const { return m_c; }
private:
    int m_r;
    int m_c;
};

// Return true if there is a path from (sr,sc) to (er,ec)
// through the maze; return false otherwise
bool pathExists(string maze[], int nRows, int nCols, int sr, int sc, int er, int ec)
{
    queue <Coord> coordQueue;
    coordQueue.push(Coord(sr, sc));
    maze[sr][sc] = '$';
    
    while (coordQueue.empty() == false)
    {
        Coord temp_coord = coordQueue.front();
        coordQueue.pop();
        if (temp_coord.r() == er && temp_coord.c() == ec)
        {
            return true;
        }
        if (temp_coord.c() < nCols - 1) //checking east
        {
            if (maze[temp_coord.r()][temp_coord.c() + 1] == '.')
            {
                coordQueue.push(Coord(temp_coord.r(), temp_coord.c() + 1));
                maze[temp_coord.r()][temp_coord.c() + 1] = '$';
            }
        }
        if (temp_coord.r() < nRows - 1) //checking south
        {
            if (maze[temp_coord.r() + 1][temp_coord.c()] == '.')
            {
                coordQueue.push(Coord(temp_coord.r() + 1, temp_coord.c()));
                maze[temp_coord.r() + 1][temp_coord.c()] = '$';
            }
        }
        if (temp_coord.c() > 0) //checking west
        {
            if (maze[temp_coord.r()][temp_coord.c() - 1] == '.')
            {
                coordQueue.push(Coord(temp_coord.r(), temp_coord.c() - 1));
                maze[temp_coord.r()][temp_coord.c() - 1] = '$';
            }
        }
        if (temp_coord.r() > 0) //checking north
        {
            if (maze[temp_coord.r() - 1][temp_coord.c()] == '.')
            {
                coordQueue.push(Coord(temp_coord.r() - 1, temp_coord.c()));
                maze[temp_coord.r() - 1][temp_coord.c()] = '$';
            }
        }
    }
    return false;
    
}

