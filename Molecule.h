//
//  Molecule.hpp
//  Free-Coding
//
//  Created by Adam Warnick on 12/11/18.
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

class Molecule {
public:
    std::map<char, char> pairDNA {{'a', 't'}, {'t', 'a'}, {'c', 'g'}, {'g', 'c'}};
    std::map<char, char> DNAtoRNA {{'a', 'u'}, {'t', 'a'}, {'c', 'g'}, {'g', 'c'}};
    std::map<char, char> pairRNA {{'a', 'u'}, {'u', 'a'}, {'c', 'g'}, {'g', 'c'}};
    
};
