//
//  testSequence.cpp
//  CS32_code1
//
//  Created by Ojas Bardiya on 4/16/19.
//  Copyright © 2019 Ojas bardiya. All rights reserved.
//

#include <iostream>
#include <cassert>
#include "Sequence.h"

using namespace std;

#include "Sequence.h"
#include <iostream>
#include <cassert>
using namespace std;

void test()
{
    Sequence s;
    s.insert(0, 10);
    s.insert(0, 20);
    assert(s.size() == 2);
    ItemType x = 999;
    assert(s.get(0, x) && x == 20);
    assert(s.get(1, x) && x == 10);
}

int main()
{
    test();
}





