<!DOCTYPE html>
<html>

<head>
    <title>Slip no 2</title>
</head>

<body>
<form method="POST">
    Enter Large String: 
    <input type="text" name="str1"><br><br>
    Enter Small String: 
    <input type="text" name="str2"><br><br>
    Give string to replace in Large string: 
    <input type="text" name="replacestr"><br><br>
    <input type="submit" value="Submit">
</form>

<?php
$str1="";
$str2="";
$replaceString = "";
if($_SERVER["REQUEST_METHOD"]=="POST"){
$str1=$_POST["str1"];
$str2=$_POST["str2"];
$replaceString = $_POST["replacestr"];
}
if(strlen($str2)>strlen($str1)){
    $t=$str1;
    $str1=$str2;
    $str2=$t;
}
echo "Large String : $str1<br>";
echo "Small String : $str2<br><br>";

echo "First Occurrence of <b>'$str2'</b> in <b>'$str1'</b> : " .  strpos($str1,$str2);
echo "<br>Last Occurrence of <b>'$str2'</b> in <b>'$str1'</b> : " . strrpos($str1,$str2);  
echo "<br>Total Occurrence of <b>'$str2'</b> in <b>'$str1'</b> : " . substr_count($str1,$str2);  

$newString=str_replace($str2,$replaceString,$str1);
echo "<br>String after replace : $newString";
?> v
</body>

</html>