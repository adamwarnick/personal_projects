//
//  triplet.hpp
//  Free-Coding
//
//  Created by Adam Warnick on 12/12/18.
//  Copyright © 2018 Adam Warnick. All rights reserved.
//

#pragma once
#include "Molecule.h"

class triplet : public Molecule {
public:
    std::vector<char> list;
    triplet(char a, char b, char c) {
        list.push_back(a);
        list.push_back(b);
        list.push_back(c);
    }
};

/*
template<> struct std::less<triplet>
{
    bool operator() (const triplet& lhs, const triplet& rhs) const
    {
        return (lhs.list.at(0) < rhs..list.at(0));
    }
};
*/
