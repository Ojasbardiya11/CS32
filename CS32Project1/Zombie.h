//
//  Zombies.h
//  CS32
//
//  Created by Ojas Bardiya on 4/7/19.
//  Copyright © 2019 Ojas bardiya. All rights reserved.
//

#ifndef ZOMBIES_h
#define ZOMBIES_h


class Arena;

class Zombie
{
public:
    // Constructor
    Zombie(Arena* ap, int r, int c);
    
    // Accessors
    int  row() const;
    int  col() const;
    
    // Mutators
    void move();
    bool getAttacked(int dir);
    
private:
    Arena* m_arena;
    int    m_row;
    int    m_col;
    int    m_health;
};

#endif 
