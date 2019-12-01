#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char const **argv)
{
    ifstream f_txt(argv[1], ios::in);
    ofstream f_bin(argv[2], ios::binary | ios::out | ios::trunc);

    string tline;
    stringstream tmp;
    unsigned int a;

    while (getline(f_txt, tline))
    {
        tmp.clear();
        tmp << tline;
        
        while (tmp >> a)
            f_bin.write(reinterpret_cast<char*>(&a), sizeof(unsigned int));
        
    }
    
    f_txt.close();
    f_bin.close();

    return 0;
}