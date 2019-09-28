//
//  main.cpp
//  CS 235 Project-- Free Coding
//
//  Created by Adam Warnick on 12/6/18.
//  Copyright © 2018 Adam Warnick. All rights reserved.
//

#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <istream>
#include <sstream>
#include <fstream>
#include "BPS.h"
#include "ProteinChain.h"

int main(int argc, const char * argv[]) {
    /***DOCUMENTATION:
     My project is going to be the Ultimate Nested Data Structure. Whether this is useful or not, I don't know. :)*/
    /*I'm also going to code up a hash map.*/
    /*JK!!! After some brainstorming, I have decided to do a protein synthesis thing.
     */
    
    /*
    std::map<char, char> pairDNA {{'a', 't'}, {'t', 'a'}, {'c', 'g'}, {'g', 'c'}};
    std::map<char, char> pairRNA {{'a', 'u'}, {'t', 'a'}, {'c', 'g'}, {'g', 'c'}};
    */
    
    std::cout << "***Protein synthesizer***" << std::endl << std::endl;
    
    std::cout << "Welcome to the Protein Synthesizer." << std::endl << std::endl;
    
    std::string opt = "";
    std::cout << "Would you like to read in a file or type in your own gene sequence manually? Enter 'f' for file read and 'm' for manual" << std::endl << std::endl;
    BPS* newSeq;
    while (opt != "q") {
        std::cin >> opt;
        if (opt == "f") {
            
            std::cout << "Step 1: Read in files." << std::endl << std::endl;
            
            std::stack<BPS> n;
            ///*
            //Refactoring code to read in a file
            BPS* newptr = new BPS();
            std::ifstream ins;
            std::ofstream os;
            std::string inFile;
            std::string outFile;
            std::istringstream ss;
            std::string addStr = "";
            std::string inSeq = "";
            //
            std::cout << "Name the file you would like to read in." << std::endl << std::endl;
            std::cin >> inFile;
            std::cout << "Opening " << inFile << ".txt: " << std::endl << std::endl;
            ins.open(inFile + ".txt");
            std::cout << "Name the file you would like to write to." << std::endl << std::endl;
            std::cin >> outFile;
            os.open(outFile + ".txt");
            
            while(!ins.is_open()) {
                std::cout << "Not a valid file; please re-enter file name." << std::endl;
                std::cin >> inFile;
                std::cout << "Opening " << inFile << std::endl << std::endl;
                //std::getline(std::cin, inFile);
                ins.open(inFile + ".txt");
            }
            
            ins >> addStr;
            
            while (std::getline(ins, inSeq)) {
                addStr.append(inSeq);
            }
            
            for (int i = 0; i < addStr.size(); i++) {
                if (newptr->pairDNA.find(addStr[i]) == newptr->pairDNA.end())  {
                    std::cout << "Non-base pair symbol found; deleting. Character is " << addStr.at(i) << ", full string (before deletion) is " << addStr << std::endl << std::endl;
                    if (i < addStr.size()-1) {
                        addStr.erase(i, i);
                    }
                    else {
                        addStr.erase(i);
                    }
                    std::cout << "New string is " << addStr << "." << std::endl << std::endl;
                };
            }
            
            BPS* newSeq = new BPS(addStr);
            newSeq->CreateSequencefile(outFile);
            
            
        }
            
        else if (opt == "m") {
            
            BPS* newptr = new BPS();
            
            std::cout << "Let's make this code do something." << std::endl << std::endl;
            std::cout << "Enter a string of a, t, c, or g base pairs" << std::endl << std::endl;
            std::cout << "Enter 'done' when done" << std::endl << std::endl;
            
            
            //
            //*/
            
            std::string inp = "";
            std::string inSeq;
            std::string outSeq;
            std::string addStr;
            
            while (inp != "done") {
                std::cin >> inp;
                //std::getline(std::cin, inp);
                addStr = inp;
                std::cout << "Input: " << addStr << std::endl << std::endl;
                if (inp.find("done") != std::string::npos) {
                    std::cout << "Finished chain; moving on" << std::endl << std::endl;
                    inp = "done";
                    addStr = addStr.substr(0, addStr.find("done"));
                }
                for (int i = 0; i < addStr.size(); i++) {
                    if (newptr->pairDNA.find(addStr.at(i)) == newptr->pairDNA.end())  {
                        std::cout << "Non-base pair symbol found; deleting. Character is " << addStr.at(i) << ", full string (before deletion) is " << addStr << std::endl << std::endl;
                        addStr.erase(addStr.begin() + i);
                        std::cout << "New string is " << addStr << "." << std::endl << std::endl;
                        --i;
                    };
                }
                std::cout << "Adding " << addStr << std::endl << std::endl;
                inSeq = inSeq + addStr;
                //inSeq.append(addStr);
            }
            std::cout << "Inputting " << inSeq;
            newSeq = new BPS(inSeq);
            newSeq->CreateSequence();
            
            
            
        }
        
        std::cout << "Enter 'q' to quit" << std::endl;
        std::cin >> opt;
    }
    BPS* strand;
    strand = newSeq;
    //std::cout << "Beginning initialization" << std::endl << std::endl;
    
    ProteinChain myChain;
    myChain.initAminoAcids();
    //std::cout << "Finished initialization" << std::endl << std::endl;
    //std::cout << std::endl << myChain.toStringMap();
    std::vector<AminoAcid*> protein;
    protein = myChain.parseStrand(strand);
    
    std::cout << std::endl << myChain.toString(protein);
     
    return 0;
}
