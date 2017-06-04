//
//
//  Assignment4
//
//
//  Seyed Mohamad Hosseinioun
//  CSCI 689/0001
//  Assignment 4
//  Due on 02.27.2017

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "process_data.h"
using namespace std;

int main(int argc, const char * argv[]) {
        if (argc != 3) { 
                cerr << "usage: " << argv[0] << " String String" << endl;
                return -1;
        }       
        
        string inpFile = argv[1];
        string outFile = argv[2];
        
        //Initiating the input stream
        ifstream inStream;
        inStream.open(inpFile.c_str());
        
        //Testing the input file status
        if (! inStream.is_open()) {
                cerr << "the "<< inpFile << " did not open properly!"<< endl;
                return -1;
        }       
        
        //Initiating the output stream
        ofstream outStream;
        outStream.open(outFile.c_str());
        
        //Testing the input file status
        if (! outStream.is_open()) {
                cerr << "the "<< outFile << " did not open properly!"<< endl;
                return -1;
        }       
        
        //initiating the input from the file
        string line,newLine;
        getline(inStream, line);
        

        //loop for checking boundary of file
        while(! inStream.eof()) {
                //processes the line
                process_data(line,  newLine);
                
                //output the new line
                outStream << newLine << endl;
                
                //take in the next line
                getline(inStream, line);
        }       
        
        inStream.close();
        outStream.close();
        
    return 0;
    

}
                                                                                                                                                                               70,1          Bot
