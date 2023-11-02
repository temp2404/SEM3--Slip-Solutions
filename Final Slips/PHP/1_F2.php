<?php

function counVowel($string){
    echo "Original String $string<br>";
    $string=strtolower($string);
    echo "Count of A: " . substr_count($string,"a") . "<br>";
    echo "Count of E: " . substr_count($string,"e") . "<br>";
    echo "Count of I: " . substr_count($string,"i") . "<br>";
    echo "Count of O: " . substr_count($string,"o") . "<br>";
    echo "Count of U: " . substr_count($string,"u") . "<br>";
}

function checkPalindrome($string){
    $rev="";
    for($i=strlen($string)-1;$i>=0;$i--){
        $rev .= $string[$i];
    }
    echo "Original String : $string<br>";
    echo "Reverse of given string : " . $rev . "<br>";
    if(strcmp($string,$rev)==0){
        echo "Given String is a Palindrome";
    }
    else{
        echo "Given String is not a Palindrome";
    }
}

?>