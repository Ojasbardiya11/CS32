//
//  History.cpp
//  CS32Notes
//
//  Created by Ojas Bardiya on 4/7/19.
//  Copyright © 2019 Ojas bardiya. All rights reserved.
//

#include <iostream>
#include "History.h"
#include "globals.h"

using namespace std;

History::History(int nRows, int nCols)
{
    mRows = nRows ;
    nColumns = nCols ;
    for ( int r = 0; r < mRows; r++)
    {
        for ( int c = 0; c < nColumns; c++)
        {
            mDeadZombie [r] [c] = '.';
        }
    }

}
 bool History::record(int r, int c)
{
    bool value = true;
    if (r < 1 || c < 1 || (r - 1) > mRows || (c - 1) > nColumns )
    {
        value = false;
        return (value);
    }
    if ( mDeadZombie [r - 1] [c - 1] == '.')
    {
        mDeadZombie [r - 1] [c - 1] = 'A';
    }
    else if ( mDeadZombie [r - 1] [c - 1] == 'Z')
    {
        return (value);
    }
    else
    {
        mDeadZombie [r - 1] [c - 1] = mDeadZombie [r - 1] [c - 1] + 1;
    }
    
    return (value);
}

void History::display() const
{
    clearScreen();
    for ( int r = 0; r < mRows; r++)
    {
        for ( int c = 0; c < nColumns; c++)
        {
            cout << mDeadZombie [r] [c];
        }
        cout << endl;
        
    }
    cout << endl;
}


