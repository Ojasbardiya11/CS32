//
//  Header.h
//  CS32Notes
//
//  Created by Ojas Bardiya on 4/7/19.
//  Copyright © 2019 Ojas bardiya. All rights reserved.
//

#ifndef Game_h
#define Game_h

class Arena;

class Game
{
public:
    // Constructor/destructor
    Game(int rows, int cols, int nZombies);
    ~Game();
    
    // Mutators
    void play();
    
    private:
    Arena* m_arena;
};

#endif 
