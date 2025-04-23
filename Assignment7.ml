let read_int_list n =
  let rec aux i acc =
    if i = 0 then acc
    else (
      print_string "Enter number: ";
      let x = read_int () in
      aux (i - 1) (x :: acc)
    )
  in aux n []

let mean lst =
  let sum = List.fold_left (+.) 0.0 (List.map float_of_int lst) in
  sum /. float_of_int (List.length lst)

let median lst =
  let sorted = List.sort compare lst in
  let len = List.length sorted in
  if len mod 2 = 0 then
    let a = List.nth sorted (len / 2 - 1) in
    let b = List.nth sorted (len / 2) in
    (float_of_int (a + b)) /. 2.0
  else
    float_of_int (List.nth sorted (len / 2))

let mode lst =
  let count_map = List.fold_left (fun acc x ->
    let count = try List.assoc x acc + 1 with Not_found -> 1 in
    (x, count) :: List.remove_assoc x acc
  ) [] lst in
  let max_freq = List.fold_left (fun acc (_, c) -> max acc c) 0 count_map in
  List.filter (fun (_, c) -> c = max_freq) count_map
  |> List.map fst

let () =
  print_string "Enter number of elements: ";
  let n = read_int () in
  let data = read_int_list n in
  Printf.printf "Mean: %.2f\n" (mean data);
  Printf.printf "Median: %.2f\n" (median data);
  Printf.printf "Mode: ";
  List.iter (Printf.printf "%d ") (mode data);
  print_newline ()
