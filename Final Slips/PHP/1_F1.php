<!DOCTYPE html>
<html>

<head>
    <title>Slip 1</title>
</head>

<body>
<form method="post">
    Give any string:
    <input type="text" name="str" id="str">
    <br><br>
    Select Operation : 
    Vowel Count : 
    <input type="radio" name="operation" value="1">
    Check Palindrome : 
    <input type="radio" name="operation" value="2">
    <br><br>
    <input type="submit" value="Submit">
</form>


<?php
include "1_F2.php";
$string = NULL;
$option=NULL;
if($_SERVER["REQUEST_METHOD"]=="POST"){
    $string = $_POST["str"];
    $option = $_POST["operation"];
}
$n=strlen($string);

if($option==1){
    counVowel($string);
}
else{
    checkPalindrome($string);
}

?>
</body>

</html>