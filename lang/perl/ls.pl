#!/usr/bin/perl

use warnings;
use strict;

my $dir; 

if ($ARGV[0]) {
    $dir = $ARGV[0]; 
} else {
    $dir = ".";
}

my @files = <$dir/*>;

my $file; 

foreach $file (@files) {
    print $file, "\n";
}
