<?php
if($_SERVER["REQUEST_METHOD"]=="GET"){
    $str1=$_GET["str1"];
    $str2=$_GET["str2"];
    $method=$_GET["method"];
    $position=$_GET["position"];
}

echo "First String: <b>$str1</b><br>";
echo "Second String: <b>$str2</b><br><br>";
if($method){
    echo "Comparing String 1 and String 2 using operator: ";
    if($str1==$str2){
        echo "Both String are Same<br>";
    }
    else{
        echo "Both String are not Same<br>";
    }
}  
else{
    echo "Comparing String 1 and String 2 using operator: ";
    if(strcmp($str1,$str2)){
        echo "Both String are not same<br>";
    }
    else{
        echo "Both Strings are same<br>";
    }
}
$str1.=$str2;
echo "<br>String 2 append to String 1 : <b>$str1</b><br>";
echo "<br>Reversing String 1 after position $position: <b>" . strrev(substr($str1,$position)) ."<b>";
?>

<!DOCTYPE html>
<html>

<head>
    <title></title>
</head>

<body>
<br><br>
<a href="6_F1.php">Go back</a>
</body>

</html>