#!/usr/bin/perl

use warnings;
use strict; 

my $argc = @ARGV;
if ($argc < 1) {
    printf STDERR "Usage: %s inputfile\n", $0;
    exit 1;
}

my $input=$ARGV[0];

# read file content into an array
open (INFILE, "<$input"); 
while (<INFILE>) {
	print $_; 
}
close(INFILE);
