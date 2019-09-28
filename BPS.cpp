//
//  BPS.cpp
//  CS 235 Project-- Free Coding
//
//  Created by Adam Warnick on 12/6/18.
//  Copyright © 2018 Adam Warnick. All rights reserved.
//

#include "BPS.h"

BPS::BPS() {
    
}

BPS::BPS(std::string inP) {
    this->inSeq = inP;
}

int BPS::CreateSequence() {
    
    int l = inSeq.size() % 3;
    
    if (l != 0) {
        std::cout << std::endl << "Strand was wrong length. Cutting off ends" << std::endl << std::endl;
        inSeq = inSeq = inSeq.substr(0, inSeq.size()-l);
    }
    
    std::cout << "Raw text: " << inSeq << std::endl;
    
    std::cout << "Populating DNA object" << std::endl;
    for (int i = 0; i < inSeq.size(); ++i) {
        std::cout << ".";
        chainInput.push_back(inSeq.at(i));
    }
    
    std::istringstream ss;
    ss.str(inSeq);
    
    std::cout << std::endl << "Populating complementary DNA" << std::endl;
    for (int i = 0; i < chainInput.size(); ++i) {
        std::cout << ".";
        compDNA.push_back(pairDNA[chainInput.at(i)]);
    }
    std::cout << std::endl;
    std::cout << "Populating complementary RNA" << std::endl;
    for (int i = 0; i < chainInput.size(); ++i) {
        std::cout << ".";
        compRNA.push_back(DNAtoRNA[chainInput.at(i)]);
    }
    std::cout << "Original input:\t\tBase pair complements:\t\tmRNA complements:" << std::endl << std::endl;
    
    for (int i = 0; i < compRNA.size(); i++) {
        std::cout << chainInput.at(i) << "\t\t\t\t\t\t\t" << compDNA.at(i) << "\t\t\t\t\t\t\t" << compRNA.at(i) << std::endl;
    }
    return 0;
}

int BPS::CreateSequencefile(std::string outFile) {
        
    int l = inSeq.size() % 3;
    
    if (l != 0) {
        std::cout << std::endl << "Strand was wrong length. Cutting off ends" << std::endl << std::endl;
        inSeq = inSeq.substr(0, inSeq.size()-l);
    }
    
    std::ofstream os;
    os.open(outFile + ".txt");
 
    std::cout << "Populating DNA object" << std::endl;
    for (int i = 0; i < inSeq.size(); ++i) {
        std::cout << ".";
        chainInput.push_back(inSeq.at(i));
    }
    
    std::istringstream ss;
    ss.str(inSeq);
    
    std::cout << std::endl << "Populating complementary DNA" << std::endl;
    for (int i = 0; i < chainInput.size(); ++i) {
        std::cout << ".";
        compDNA.push_back(pairDNA[chainInput.at(i)]);
    }
    std::cout << std::endl;
    std::cout << "Populating complementary RNA" << std::endl;
    for (int i = 0; i < chainInput.size(); ++i) {
        std::cout << ".";
        compRNA.push_back(DNAtoRNA[chainInput.at(i)]);
    }
    os << "Original input:\t\tBase pair complements:\t\tmRNA complements:" << std::endl << std::endl;
    
    for (int i = 0; i < compRNA.size(); i++) {
        os << chainInput.at(i) << "\t\t\t\t" << compDNA.at(i) << "\t\t\t\t\t\t\t\t" << compRNA.at(i) << std::endl;
    }
    
    std::cout << std::endl << "Completed. See out.txt." << std::endl;
    
    return 0;

}

/*
int BPS::match(<#BPS *sym#>) {
    if (sym->num == 0) {
        return 1;
    }
    if (sym->num == 1) {
        return 0;
    }
    if (sym->num == 2) {
        return 3;
    }
    if (sym->num == 3) {
        return 2;
    }
};
*/
