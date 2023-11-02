<!DOCTYPE html>
<html>

<head>
    <title>Slip 7</title>
</head>

<body>
<?php
$arr=array(1=>"Martin",2=>"Avicii",3=>"KSHMR",4=>"Skrillex",5=>"Tiesto");
echo "Original Array: ";
print_r($arr);
echo "<br><br>Size of Array: " . count($arr) . "<br>";
$deleteIndex=2;
unset($arr[$deleteIndex]);
echo "<br>Array after Deleting : ";
print_r($arr);
$arr=array_flip($arr);
echo "<br><br>Array after Fliping : ";
print_r($arr);

echo "<br><br>Traversing array in random order: ";
$keys=array_keys($arr);
shuffle($keys);
foreach($keys as $value){
    echo "$arr[$value] ";
}

?>
</body>

</html>