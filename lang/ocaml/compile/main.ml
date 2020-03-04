let x = ref 4;;
let go() =
  x := -1; 
  Fact.fact !x;;
go();;
