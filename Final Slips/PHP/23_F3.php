<!DOCTYPE html>
<html>

<head>
    <title></title>
</head>

<body>
<?php
    if($_SERVER["REQUEST_METHOD"]=="POST"){
        $pname=$_POST["pname"];
        $qty=$_POST["qty"];
        $rate=$_POST["rate"];
    }
    $cname=$_POST["cname"];
    $address=$_POST["address"];
    $phno=$_POST["phno"];

    echo $cname . "<br>";
    echo $address . "<br>";
    echo $phno . "<br>";
    echo $pname . "<br>";
    echo $qty . "<br>";
    echo $rate . "<br>";


?>
</body>

</html>