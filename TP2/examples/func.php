<?php
function csv_to_array($file){
  $res = [];
  $lines = file("csv/" . $file, FILE_IGNORE_NEW_LINES);
	foreach ($lines as $line) {
		$l = explode(';', trim($line));
    $res[] = ["c1" => ["re"=> $l[0], "im" => $l[1]],"c2" =>  ["re"=> $l[2], "im" => $l[3]],"c3" =>  ["re"=> $l[4], "im" => $l[5]]];
  }
	return $res;
}

function compile_test(){
  exec("cd .. ; ./make_src_examples.sh clean; ./make_src_examples.sh; cd examples");
}

function clean(){
  exec("cd .. ; ./make_src_examples.sh clean;");
}

function rewrite_csv($file){
  $basename = explode(".", $file)[0];
  exec("cp test_complexe_" . $basename . ".c test_complexe.c");
  compile_test();
  exec("./test_complexe > csv/" . $file);
}


function mult_complexe($c1, $c2){
  $r = $c1["re"] *  $c2["re"] - $c1["im"] *  $c2["im"];
  $i = $c1["re"] *  $c2["im"] + $c1["im"] *  $c2["re"];
  return ["re" => $r, "im" => $i];
}
