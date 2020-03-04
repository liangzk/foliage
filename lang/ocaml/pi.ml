(* this code is from codecodex.com *)

let scale = 10000 and n = 2800
let a = Array.make (n+1) 2000

let rec g j sum =
  if j < 1 then sum else
    let sum = sum * j + scale * a.(j) in
    a.(j) <- sum mod (j * 2 - 1);
    g (j - 1) (sum / (j * 2 - 1))

let rec f i carry =
  if i = 0 then () else
    let sum = g i 0 in
    Printf.printf "%04d" (carry + sum / scale);
    f (i - 14) (sum mod scale)

let () =
  f n 0;
  print_newline()
