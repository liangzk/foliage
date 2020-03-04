let group_match regex str size =
  let r = Str.regexp regex in
  let result = Str.string_match r str 0 in
    if result 
    then
      let rec group_to_list n =
	let matched = 
	  try 
	    Some(Str.matched_group n str)
	  with
	      Not_found -> None
	in
	  if n = size 
	  then [matched]
	  else matched :: group_to_list (n+1)
	    
      in
	group_to_list 1
    else
      []

;;

let regex = "\\([0-9]+\\) : \\(.*\\)" in
let tomatch = "123 : Test\n" in
  group_match regex tomatch 2
	
