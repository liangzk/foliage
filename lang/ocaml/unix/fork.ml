match Unix.fork () with
    0 -> Printf.printf "I am the child %d\n" (Unix.getpid ())
  | pid -> Printf.printf "I am the father: %d of child: %d\n"
      (Unix.getpid ()) pid
