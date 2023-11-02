<?php
if($_SERVER["REQUEST_METHOD"]=="GET"){
    $name = $_GET["name"];
    $phno = $_GET["phno"];
    $units = $_GET["units"];
}


$tax1= 50 * 3.50;
$tax2= 100 * 4;
$tax3= 100 * 5.2;


if($units>=250){
    $sum = $tax1 + $tax2 + $tax3 + (($units-250)*6.5) + 150;
}
else if($units<250 && $units>=150){
    $sum = $tax1 + $tax2 + $tax3 + 150;
}
else if($units<150 && $units>=50){
    $sum = $tax1 + $tax2 + 150;
}
else{
    $sum= $tax1+150;
}
?>

<!DOCTYPE html>
<html>

<head>
    <title>Bill - Slip 16</title>
</head>

<body>
    <table border=1>
        <tr>
            <td colspan=2>Name : <?php echo $name?></td>
        </tr>
        <tr>
            <td colspan=2>Contact No : <?php echo $phno?></td>
        </tr>
        <tr>
            <th>Units Consumed</th>
            <th>Total</th>
        </tr>
        <tr>
            <td><?php echo $units?></td>
            <td><?php echo $sum?></td>
        </tr>
    </table>

</body>

</html>