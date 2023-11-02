<?php
$item=array();
if(isset($_GET["item1"]))
    array_push($item,$_GET["item1"]);
if(isset($_GET["item2"]))
    array_push($item,$_GET["item2"]);
if(isset($_GET["item3"]))
    array_push($item,$_GET["item3"]);
if(isset($_GET["item4"]))
    array_push($item,$_GET["item4"]);
if(isset($_GET["item5"]))
    array_push($item,$_GET["item5"]);

$prices=array(45,85,125,20,60);
$total=0;
echo "<table border=1>";
echo "<tr>";
echo "<th>Name of the Product</th>";
echo "<th>Price of the Product</th>";
echo "</tr>";
for($i=0;$i<count($item);$i++){
    echo "<tr>";
    echo "<td>" . $item[$i] . "</td>";
    echo "<td>" . $prices[$i] . "</td>";
    echo "</tr>";
    $total += $prices[$i];
}
echo "<tr>";
echo "<th>Total</th>";
echo "<td>" . $total . "</td>";
echo "</tr>";
echo "</table>";
?>
