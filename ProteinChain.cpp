//
//  ProteinChain.cpp
//  Free-Coding
//
//  Created by Adam Warnick on 12/11/18.
//  Copyright © 2018 Adam Warnick. All rights reserved.
//

#include "ProteinChain.h"

std::vector<AminoAcid*> ProteinChain::parseStrand(BPS* theChain){
	std::cout << "Parsing input" << std::endl;
    std::vector<AminoAcid*> myAminoAcids;
    std::vector<char> currTrp;
    for (int i = 0; i < (theChain->compRNA).size(); i+=3) {
        for (int i = 0; i < 3; i++) {
	    std::cout << "Size of input chain is " << (theChain->compRNA).size() << std::endl;
            currTrp.push_back((theChain->compRNA).at(i));
        }
        triplet* t = new triplet(currTrp.at(0), currTrp.at(1), currTrp.at(2));
        AminoAcid* a;
	int match = 0;
        std::map<triplet*, AminoAcid*>::iterator mapTraverse = allAminoAcids.begin();
        for (mapTraverse = allAminoAcids.begin(); mapTraverse != allAminoAcids.end(); ++mapTraverse) {
		for (int j = 0; j < 3; ++j) {
        	            if (currTrp.at(j) == ((mapTraverse->first)->list.at(j))) {
        	                match++;
                	    }
            	}
            	if (match == 3) {
                	t = mapTraverse->first;
                	a  = allAminoAcids[t];
		}
	}        
	//AminoAcid* a = new AminoAcid((allAminoAcids.find(t)->second->name));
        myAminoAcids.push_back(a);
        currTrp.clear();
    }
    return myAminoAcids;
};

/*
bool ProteinChain::pushAA(AminoAcid* n, std::map<char, char>::iterator a, std::map<char, char>::iterator b, std::map<char, char>::iterator c){
    triplet* t = new triplet(a->first, b->first, c->first);
    std::vector<char> list1 = {a->first, b->first, c->first};
    n->encoding.push_back(list1);
    this->allAminoAcids.insert(std::pair<triplet*, AminoAcid*>(t, n));
    return true;
};
*/
 
bool ProteinChain::AddAA(AminoAcid* n, std::map<char, char>::iterator a, std::map<char, char>::iterator b, std::map<char, char>::iterator c){
    triplet* t = new triplet(a->first, b->first, c->first);
    std::vector<char> list1 = {a->first, b->first, c->first};
    n->encoding.push_back(list1);
    this->allAminoAcids.insert(std::pair<triplet*, AminoAcid*>(t, n));
    return true;
};


std::map<triplet*, AminoAcid*> ProteinChain::initAminoAcids(){
    std::map<triplet*, AminoAcid*> allAminoAcids;
    AminoAcid* phenylalinine = new AminoAcid("phe");
    AminoAcid* leucine = new AminoAcid("leu");
    AminoAcid* serine = new AminoAcid("ser");
    AminoAcid* tyrosine = new AminoAcid("tyr");
    AminoAcid* STOP = new AminoAcid("STOP");
    AminoAcid* alanine = new AminoAcid("ala");
    AminoAcid* cysteine = new AminoAcid("cys");
    AminoAcid* asparagine = new AminoAcid("asn");
    AminoAcid* aspartic_acid = new AminoAcid("asp");
    AminoAcid* lysine = new AminoAcid("lys");
    AminoAcid* methionine = new AminoAcid("met");
    AminoAcid* proline = new AminoAcid("pro");
    AminoAcid* threonine = new AminoAcid("thr");
    AminoAcid* tryptophan = new AminoAcid("trp");
    AminoAcid* glutamic_acid = new AminoAcid("glu");
    AminoAcid* valine = new AminoAcid("val");
    AminoAcid* glutamine = new AminoAcid("gln");
    AminoAcid* arginine = new AminoAcid("arg");
    AminoAcid* histidine = new AminoAcid("his");
    AminoAcid* glycine = new AminoAcid("gly");
    AminoAcid* isoleucine = new AminoAcid("ile");
    
    std::map<char, char>::iterator mapTraverse = pairRNA.begin();
    std::map<char, char>::iterator pos2 = pairRNA.begin();
    std::map<char, char>::iterator pos3 = pairRNA.begin();
    for (mapTraverse = pairRNA.begin(); mapTraverse != pairRNA.end(); ++mapTraverse) {
        for (pos2 = pairRNA.begin(); pos2 != pairRNA.end(); ++pos2) {
            for (pos3 = pairRNA.begin(); pos3 != pairRNA.end(); ++pos3) {
                if (mapTraverse->first == 'u') {
                    if (pos2->first == 'u') {
                        if (pos3->first == 'u' || pos3->first == 'c') {
                            AddAA(phenylalinine, mapTraverse, pos2, pos3);
                        }
                        if (pos3->first == 'a' || pos3->first == 'g') {
                            AddAA(leucine, mapTraverse, pos2, pos3);
                        }
                    }
                    if (pos2->first == 'c') {
                        AddAA(serine, mapTraverse, pos2, pos3);
                        
                    }
                    if (pos2->first == 'a') {
                        if (pos3->first == 'u' || pos3->first == 'c') {
                            AddAA(tyrosine, mapTraverse, pos2, pos3);
                        }
                        if (pos3->first == 'a' || pos3->first == 'g') {
                            AddAA(STOP, mapTraverse, pos2, pos3);
                        }
                    }
                    if (pos2->first == 'g') {
                        if (pos3->first == 'u' || pos3->first == 'c') {
                            AddAA(cysteine, mapTraverse, pos2, pos3);
                        }
                        if (pos3->first == 'a') {
                            AddAA(STOP, mapTraverse, pos2, pos3);
                        }
                        if (pos3->first == 'g') {
                            AddAA(tryptophan, mapTraverse, pos2, pos3);
                        }
                    }
                }
                if (mapTraverse->first == 'c') {
                    if (pos2->first == 'u') {
                        AddAA(leucine, mapTraverse, pos2, pos3);
                    }
                    if (pos2->first == 'c') {
                        AddAA(proline, mapTraverse, pos2, pos3);
                    }
                    if (pos2->first == 'a') {
                        if (pos3->first == 'u' || pos3->first == 'c') {
                            AddAA(histidine, mapTraverse, pos2, pos3);
                        }
                        if (pos3->first == 'a' || pos3->first == 'g') {
                            AddAA(glutamine, mapTraverse, pos2, pos3);
                        }
                    }
                    if (pos2->first == 'g') {
                        AddAA(arginine, mapTraverse, pos2, pos3);
                    }
                }
                if (mapTraverse->first == 'a') {
                    if (pos2->first == 'u') {
                        if (pos3->first == 'u' || pos3->first == 'c' || pos3->first == 'a') {
                            AddAA(isoleucine, mapTraverse, pos2, pos3);
                        }
                        if (pos3->first == 'g') {
                            AddAA(methionine, mapTraverse, pos2, pos3);
                        }
                    }
                    if (pos2->first == 'c') {
                        AddAA(threonine, mapTraverse, pos2, pos3);
                    }
                    if (pos2->first == 'a') {
                        if (pos3->first == 'u' || pos3->first == 'c') {
                            AddAA(asparagine, mapTraverse, pos2, pos3);
                        }
                        if (pos3->first == 'a' || pos3->first == 'g') {
                            AddAA(lysine, mapTraverse, pos2, pos3);
                        }
                    }
                    if (pos2->first == 'g') {
                        if (pos3->first == 'u' || pos3->first == 'c') {
                            AddAA(serine, mapTraverse, pos2, pos3);
                        }
                        if (pos3->first == 'a' || pos3->first == 'g') {
                            AddAA(arginine, mapTraverse, pos2, pos3);
                        }
                    }
                }
                if (mapTraverse->first == 'g') {
                    if (pos2->first == 'u') {
                        AddAA(valine, mapTraverse, pos2, pos3);
                    }
                    if (pos2->first == 'c') {
                        AddAA(alanine, mapTraverse, pos2, pos3);
                    }
                    if (pos2->first == 'a') {
                        if (pos3->first == 'u' || pos3->first == 'c') {
                            AddAA(aspartic_acid, mapTraverse, pos2, pos3);
                        }
                        if (pos3->first == 'a' || pos3->first == 'g') {
                            AddAA(glutamic_acid, mapTraverse, pos2, pos3);
                        }
                    }
                    if (pos2->first == 'g') {
                        AddAA(glycine, mapTraverse, pos2, pos3);
                    }
                }
            }
        }
    }
    
    
    return allAminoAcids;
};

std::string ProteinChain::toString(std::vector<AminoAcid*> myAminoAcids) {
    std::string n;
    std::ostringstream os;
    os << "Protein chain resulting from input DNA strand:" << std::endl;
    for (int i = 0; i < myAminoAcids.size(); ++i) {
        AminoAcid* aa = myAminoAcids.at(i);
	//std::string l = myAminoAcids.at(i)->name;
        os << ": " << aa->name << std::endl;
    }
    return os.str();
};

std::string ProteinChain::toStringMap() {
    std::string n;
    std::ostringstream os;
    for (std::map<triplet*, AminoAcid*>::iterator through = allAminoAcids.begin(); through != allAminoAcids.end(); ++through) {
        for (int i = 0; i < through->first->list.size(); ++i) {
		os << through->first->list.at(i);
        }
        os << ": " << through->second->name << std::endl;
    }
    
    
    return os.str();
};
