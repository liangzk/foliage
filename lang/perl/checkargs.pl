#!/usr/bin/perl
# Takes two arguments

use warnings;
use strict; 

my $argc = @ARGV;
if ($argc < 2) {
    printf STDERR "Usage: %s arg1 arg2\n", $0;
    exit 1;
}

print "Two command line arguments: $ARGV[0], $ARGV[1]\n";

