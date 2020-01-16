//
//  Header.h
//  CS32Notes
//
//  Created by Ojas Bardiya on 4/7/19.
//  Copyright © 2019 Ojas bardiya. All rights reserved.
//

#ifndef Header_h
#define Header_h
#include "globals.h"

class History
{
    public:
    History(int nRows, int nCols);
    bool record(int r, int c);
    void display() const;
    
    private:
    int mRows;
    int nColumns;
    char mDeadZombie [MAXROWS][MAXCOLS];

};

#endif 
