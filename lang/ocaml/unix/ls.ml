open Unix;;

let dhandle = opendir "." in
let rec display dhandle= 
  try 
    let dentry = readdir dhandle in 
    let () = Printf.printf "%s\n" dentry in
      display dhandle
  with
      End_of_file -> closedir dhandle
in
  display dhandle
