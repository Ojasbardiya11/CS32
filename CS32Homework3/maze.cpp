//
//  main.cpp
//  Homework3part3
//
//  Created by Ojas Bardiya on 5/9/19.
//  Copyright © 2019 Ojas bardiya. All rights reserved.
//

bool pathExists(char maze[][10], int sr, int sc, int er, int ec)
{
    bool value = false;
    if (sr == er && sc == ec)
    {
        value = true;
        return (value);
    }
    maze[sr][sc] = '$';
    
    if (sr != 9 && maze[sr + 1][sc] =='.') //checks if moving south is valid
    {
        if (pathExists(maze, sr + 1, sc, er, ec))
        {
            value = true;
            return (value);
        }
    }
    if (sc != 0 && maze[sr][sc - 1] == '.') // checks if moving west is valid
    {
        if (pathExists(maze, sr, sc - 1, er, ec))
        {
            value = true;
            return (value);
        }
    }
    if (sr != 0 && maze[sr - 1][sc] == '.')
    {
        if (pathExists(maze, sr - 1, sc, er, ec)) //checks if moving north is valid
        {
            value = true;
            return (value);
        }
    }
    if (sc != 9 && maze[sr][sc + 1] == '.') //checks if moving east is valid
    {
        if (pathExists(maze, sr, sc + 1, er, ec))
        {
            value = true;
            return (value);
        }
    }
    
    return (value);
}
