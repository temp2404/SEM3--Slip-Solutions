<!DOCTYPE html>
<html>

<head>
    <title>Slip 4</title>
</head>

<body>
<form  method="GET">
    Enter String 1: 
    <input type="text" name="str1" id="str1"><br><br>
    Enter String 2: 
    <input type="text" name="str2" id="str2"><br><br>
    Enter String to Replace: 
    <input type="text" name="str3" id="str3"><br><br>
    <input type="submit" value="Submit">
</form>

<?php
if($_SERVER["REQUEST_METHOD"]=="GET"){
    $str1=$_GET["str1"];
    $str2=$_GET["str2"];
    $str3=$_GET["str3"];
}

echo "String 1: $str1<br>";
echo "String 2: $str2<br>";

if(strpos($str1,$str2)==0){
    echo "String 2 appears at the start of string 1<br>";
}
else{
    echo "String 2 does not appear at the start of string 1<br>";
}

$newstr = str_replace($str2,$str3,$str1);
echo "String 1 after Replacing : $newstr";
?>

</body>

</html>