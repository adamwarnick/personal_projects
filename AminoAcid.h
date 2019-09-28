//
//  AminoAcid.hpp
//  Free-Coding
//
//  Created by Adam Warnick on 12/11/18.
//  Copyright © 2018 Adam Warnick. All rights reserved.
//
#pragma once
#include "BPS.h"
#include "triplet.h"

class AminoAcid : public Molecule {
public:
    std::string name;
    std::vector<std::vector<char>> encoding;
    AminoAcid();
    AminoAcid(std::string name);
};
