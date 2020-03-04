type 'a bin_tree =
      Empty
    | Node of 'a bin_tree * 'a * 'a bin_tree

let rec list_of_tree = function
      Empty -> []
    | Node (lb, r, rb) -> (list_of_tree lb) @ (r :: (list_of_tree rb))

let rec insert x = function
      Empty -> Node(Empty, x, Empty)
    | Node(lb, r, rb) -> 
        if x<r then Node(insert x lb, r, rb)
        else Node(lb, r, insert x rb)

let rec tree_of_list = function
      [] -> Empty
    | h::t -> insert h (tree_of_list t)

let sort x = list_of_tree (tree_of_list x)

                 
