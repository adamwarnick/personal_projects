//
//  BPS.h
//  CS 235 Project-- Free Coding
//
//  Created by Adam Warnick on 12/6/18.
//  Copyright © 2018 Adam Warnick. All rights reserved.
//

#pragma once

#include <iostream>
#include <map>
#include <string>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <istream>
#include <sstream>
#include <fstream>
#include "Molecule.h"

class BPS : public Molecule {
    public:
    
    BPS();
    BPS(std::string inP);
    int CreateSequence();
    int CreateSequencefile(std::string outFile);
    //std::map<char, char> pairDNA {{'a', 't'}, {'t', 'a'}, {'c', 'g'}, {'g', 'c'}};
    //std::map<char, char> pairRNA {{'a', 'u'}, {'t', 'a'}, {'c', 'g'}, {'g', 'c'}};
    std::string inSeq;
    std::vector<char> compDNA;
    std::vector<char> compRNA;
    std::vector<char> chainInput;
};

/*
class BPS {
    public:
    //Key: {a = 0, t = 2, c = 3, g = 4}
        int key[4] = {0, 1, 2, 3};
        const std::map<int, char> basePairings = {{0, 'a'}, {1, 't'}, {2, 'c'}, {3, 'g'}};
        int num;
        int match(BPS* sym);
};
*/
