//
//  testScoreList.cpp
//  CS32_code1
//
//  Created by Ojas Bardiya on 4/16/19.
//  Copyright © 2019 Ojas bardiya. All rights reserved.
//

#include "Sequence.h"
#include "Scorelist.h"
#include <cassert>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    ScoreList mathgrades;
    assert(mathgrades.add(36));
    assert(mathgrades.add(88));
    assert(mathgrades.add(76));
    assert(mathgrades.add(94));
    assert(mathgrades.add(56));
    assert(mathgrades.add(66));
    assert(!mathgrades.remove(33));
    assert(mathgrades.size() == 6);
    assert(mathgrades.maximum() == 94);
    assert(mathgrades.minimum() == 36);
}
