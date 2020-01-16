//
//  Player.h
//  CS32
//
//  Created by Ojas Bardiya on 4/7/19.
//  Copyright © 2019 Ojas bardiya. All rights reserved.
//

#ifndef PLAYER_h
#define PLAYER_h

class Arena;


class Player
{
public:
    // Constructor
    Player(Arena *ap, int r, int c);
    
    // Accessors
    int  row() const;
    int  col() const;
    int  age() const;
    bool isDead() const;
    
    // Mutators
    void   stand();
    void   moveOrAttack(int dir);
    void   setDead();
    
private:
    Arena* m_arena;
    int    m_row;
    int    m_col;
    int    m_age;
    bool   m_dead;
};

#endif 
