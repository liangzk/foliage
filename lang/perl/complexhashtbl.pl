#!/usr/bin/perl

use strict;
use warnings;

my %hash;

$hash{"Class 1"}{"Item F"} = 1; 
$hash{"Class 1"}{"Item A"} = 1;
$hash{"Class 1"}{"Item K"} = 1;
$hash{"Class 2"}{25} = 1; 
$hash{"Class 2"}{37} = 1; 
$hash{"Class 2"}{11} = 1;

for (keys %hash) {
    my $key1 = $_; 

    my $hashref = $hash{$key1}; 
    my @itemarray ;

    if ($key1 eq "Class 1") {
	@itemarray = sort (keys %$hashref);
    } else {
	# this is not necessary, just to demonstrate the <=> operator
	@itemarray = sort {$a <=> $b} (keys %$hashref);
    }
	
    
    print "$key1: ";
    for (@itemarray) {
	print $_, ", ";
    }

    print "\n";
}
