<!DOCTYPE html>
<html>

<head>
    <title>Slip 23 - File 2</title>
</head>

<body>
<form action="23_F3.php" method="post">
    Enter Product Name: 
        <input type="text" name="pname"><br><br>
    Enter Product Quantity: 
        <input type="number" name="qty"><br><br>
    Enter Product Rate: 
        <input type="number" name="rate"><br><br>
        <input type="submit" value="Submit">
</form>

<?php
// include "23_F1.php"; 
if($_SERVER["REQUEST_METHOD"]=="POST"){
    $cname=$_POST["cname"];
    $address=$_POST["address"];
    $phno=$_POST["phno"];
    $pname=$_POST["pname"];
    $qty=$_POST["qty"];
    $rate=$_POST["rate"];
}
?>


</body>

</html>