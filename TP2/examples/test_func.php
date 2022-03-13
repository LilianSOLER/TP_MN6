<?php
require_once "func.php";

// $MULT_CSV = ["test_mult_float.csv", "test_mult_double.csv"];
$MULT_CSV = ["float" => "mult_float.csv", "double" => "mult_double.csv"];

function test_mult_complexe($tests){
  echo "Test mult_complexe() ...\n\n";

  
  foreach($tests as $file){
    rewrite_csv($file);
  }
  
  $arr = csv_to_array($file);

  foreach($tests as $title => $file){
    echo "Version " . $title . ":\n";
    $all_calcul_valid = true;
    $max_max_diff = 0;
    foreach($arr as $calc){
      $c3 = mult_complexe($calc["c1"], $calc["c2"]);
      $max_diff = max(abs($c3["re"] - $calc["c3"]["re"]), abs($c3["re"] - $calc["c3"]["re"]));
      if($max_max_diff < $max_diff){
        $max_max_diff = $max_diff;
      }
      if($max_diff > 0.1){
        echo "Invalid Calcul : diff " . $max_diff . "\n";
        $all_calcul_valid = false;
      }
    }
    echo "Max diff is : " . $max_max_diff . "\n";
    echo $all_calcul_valid ? "Success\n\n" : "Failure\n\n";
  }

  echo "Done.\n\n";
}


$TESTS = [
  "mult_complexe" => $MULT_CSV
];

//run tests with different functions and different tests
function TESTS($test){
  global $TESTS;
  $tests = $TESTS[$test]; //get tests array
  $function = "test_" . $test; //get function name
  $function($tests); //run function
}