//
//  ProteinChain.hpp
//  Free-Coding
//
//  Created by Adam Warnick on 12/11/18.
//  Copyright © 2018 Adam Warnick. All rights reserved.
//
#pragma once
#include "BPS.h"
#include "AminoAcid.h"

class ProteinChain : public Molecule {
public:
    std::map<triplet*, AminoAcid*> initAminoAcids();
    bool AddAA(AminoAcid* n, std::map<char, char>::iterator a, std::map<char, char>::iterator b, std::map<char, char>::iterator c);
    std::map<triplet*, AminoAcid*> allAminoAcids;
    std::string toStringMap();
    std::vector<AminoAcid*> parseStrand(BPS* theChain);    
    std::string toString(std::vector<AminoAcid*> myAminoAcids);
};
