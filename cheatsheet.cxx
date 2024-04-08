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

// LONG OPTS
static int f_Python;
static int f_CPlusPlus;
static int f_Bash;
static int f_GNUUtils;
static int f_Help;
static int f_Test;

int main(int argc, char* argv[]){
    
    int c;
    while (1){
        int option_index = 0;
        static struct option long_options[] = {
            {"python",       no_argument, &f_Python,       1},
            {"cpp",          no_argument, &f_CPlusPlus,    1},
            {"bash",         no_argument, &f_Bash,         1},
            {"gnu-utils",    no_argument, &f_GNUUtils,     1},
            {"help",         no_argument, &f_Help,         1},
            {"test",         no_argument, &f_Test,         1},
            {NULL,           0,           NULL,            0}
        };
        
        c = getopt_long(argc, argv, "-:", long_options, &option_index);
        if (c == -1)
            break;

        switch (c){
            case 1:
                printf("regular argument '%s'\n", optarg);
                break;
            case '?':
                // printf("Unknown option %c\n", optopt);
                printf("Unknown option %s\n", optarg);
                // print help
                break;
        }
    }

    if (f_Test == 1) {
        // print additional information
	    std::cout << std::endl;
        std::cout << "Number of arguments: " << argc << std::endl;
	    std::cout << std::endl;
        for (int i=0; i<argc; i++) {
            std::string s(argv[i]); // char array to string
            std::cout << "arg[" << i << "] = " << s << std::endl;
        }
        std::cout << std::endl;

        // print all long opt variables
        printf("\n -- LONG OPTS --\n");
        printf("     f_Python: %i\n", f_Python);
        printf("     f_CPlusPlus: %i\n", f_CPlusPlus);
        printf("     f_Bash: %i\n", f_Bash);
        printf("     f_GNUUtils: %i\n", f_GNUUtils);
        printf("     f_help: %i\n", f_Help);
    }

//    PrintAlias();
	return 0;
}

