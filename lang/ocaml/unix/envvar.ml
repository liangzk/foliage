let envarray = Unix.environment () in
let envlist = Array.to_list envarray in
let () = List.iter (fun s -> Printf.printf "%s\n" s) envlist in
let path = 
  try
    Unix.getenv "TEST" 
  with
      Not_found -> 
	Printf.printf "Adding TEST\n";
	Unix.putenv "TEST" "mytest"; 
	Unix.getenv "TEST" 
in
  Printf.printf "TEST: %s\n" path
    
