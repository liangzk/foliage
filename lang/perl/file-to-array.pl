#!/usr/bin/perl

use warnings;
use strict; 

my $argc = @ARGV;
if ($argc < 2) {
    printf STDERR "Usage: %s inputfile outputfile\n", $0;
    exit 1;
}

my $input=$ARGV[0];
my $output=$ARGV[1];

# read file content into an array
my $buffer = "";
open (INFILE, "<$input"); 
binmode(INFILE);
read(INFILE, $buffer, 10); 
close(INFILE);
my @inarray = unpack("C*", $buffer); 

my $i; 
for ($i=0; $i<10; $i++) {
    printf "INPUT[%d] = 0x%02X\n", $i, $inarray[$i]; 
    $inarray[$i]++; 
}

# write array into a file
open (OUTFILE, ">$output"); 
binmode(OUTFILE); 
$buffer = pack("C*", @inarray); 
syswrite(OUTFILE, $buffer); 
close(OUTFILE); 
