#include "process_data.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

int process_data(const string & line, string & newLine ) {
        newLine.clear(); 
        char inp1 = line[0];
        bool comment =0; // control variable for state initialized
        bool quote =0;  //control variable for state
        int dashExpI  =0; //control variable to check a second / appears on an i
        //int noQuot = 0; //control variable for number of quotation marks
        for (int i=1; i<=line.size(); i++) { 
                if (quote == 0) {
                        if ( inp1=='/' ){ //if came across a /
                                if (dashExpI ==i) { // if we had a / just before and had marked to check this i
                                        newLine.push_back('*');
                                        comment = 1;
                                        dashExpI  =0;
                                }       
                                else { //if we've not just had a /
                                        newLine.push_back(inp1); 
                                        dashExpI= i+1;  
                                }       
                        }       
                        else if (inp1 =='\"') { // if came across a "
                                if (comment ==0) { //if came across a " and not inside of a comment
                                        quote =1; //change of state to quote
                                        newLine.push_back(inp1);
                                }       
                                else { // if came across a " but we were already in a comment
                                        newLine.push_back(inp1); 
                                }       
                        }       
                        else    {
                                newLine.push_back(inp1);
                        }       
                        
                }
                else { //if inside a quote
                        if (inp1 == '\"'){
                                quote=0;  //change of state
                                newLine.push_back(inp1);
                        }       
                        else {
                                newLine.push_back(inp1);
                        }       
                }       
        inp1 = line[i];
        }
        if (comment ==1) {
                newLine.push_back('*');
                newLine.push_back('/');
        }       
        newLine.push_back('\n');
        return 0;
        cout << "newline in the function is: " << newLine << endl;
}       
                                                                                                                                                                               60,1          Bot
