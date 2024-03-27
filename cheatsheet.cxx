#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
#include <getopt.h>
#include "aliases.h"

int getopt(int argc, char * const argv[],
       const char *optstring);

extern char *optarg;
extern int optind, opterr, optopt;

int getopt_long(int argc, char * const argv[],
                const char *optstring,
                const struct option *longopts, int *longindex);

int getopt_long_only(int argc, char * const argv[],
                     const char *optstring,
                     const struct option *longopts, int *longindex);

void PrintHelp()
{
    std::cout <<
        "--users:             Show help related to users.\n";
        "--help:              Show help\n";
    exit(1);
}

int main(int argc, char* argv[]){
//	std::cout << "\nTest run!\n\n";
    
	std::cout << std::endl;
    std::cout << "Number of arguments: " << argc << std::endl;
	std::cout << std::endl;

    for (int i=0; i<argc; i++) {
//	    std::cout << "\n" << input_var <<"\n\n";
        std::string s(argv[i]); // char array to string
        std::cout << "arg[" << i << "] = " << s << std::endl;
    }

    PrintAlias();
	return 0;
}

