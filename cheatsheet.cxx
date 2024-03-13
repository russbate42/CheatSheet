#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
#include <getopt.h>

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

int main(int argc, char* argv[]){
	std::cout << "\nTest run!\n\n";
	return 0;
}

