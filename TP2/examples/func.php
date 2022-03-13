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


function mult_complexe($c1, $c2){
  $r = $c1["re"] *  $c2["re"] - $c1["im"] *  $c2["im"];
  $i = $c1["re"] *  $c2["im"] + $c1["im"] *  $c2["re"];
  return ["re" => $r, "im" => $i];
}
