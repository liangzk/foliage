#include <getopt.h>
#include <stdio.h>

int main(int argc, char**argv) 
{
	int argc1 = 1; 
	char *argv1[] = {"Driver", 0};

	getopt(argc1, argv1, ":a"); 
}
