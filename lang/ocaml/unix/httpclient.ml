open Unix

let request = "GET /index.html\n\n"
;; 

let hostent = gethostbyname "google.com" in
let addr = hostent.h_addr_list.(0) in
let server = ADDR_INET (addr, 80) in
let ic, oc = open_connection server in
let _ = output_string oc request in	
let _ = flush oc in
let response = input_line ic in
    print_endline response
