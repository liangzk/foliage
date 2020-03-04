#!/usr/bin/perl

use warnings;
use strict; 

my %hashtbl; 

# empty an hashtable
%hashtbl = ();


$hashtbl{"Item1"} = "Data1"; 
$hashtbl{"Item2"} = "Data2"; 
$hashtbl{3} = 3; 

# get hashtable size
my $hashsize;
$hashsize = keys %hashtbl; 
print "Size of hashtable: ", $hashsize, "\n";

# delete an item
delete $hashtbl{3};

# iterate through all items
for (keys %hashtbl) {
    print $_, ":", $hashtbl{$_}, "\n";
}


