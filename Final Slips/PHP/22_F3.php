<?php
session_start();

if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    if (isset($_POST['item4'])) {
        $_SESSION['total'] += (float)$_POST['item4'];
        $item4 = array("Asus Laptop",60000);
        array_push($_SESSION['bill_items'],$item4);
    }
    if (isset($_POST['item5'])) {
        $_SESSION['total'] += (float)$_POST['item5'];
        $item5 = array("Samsung Galaxy S9 Ultra",110000);
        array_push($_SESSION['bill_items'],$item5);
    }
}
?>

<!DOCTYPE html>
<html>
<head>
    <title>Shopping Mall</title>
</head>
<body>
<?php
print_r($_SESSION['bill_items']);
echo '<table border=1 >';
echo '<tr>';
echo '<th>Product Name</th>';
echo '<th>Product Price</th>';
echo '</tr>';
for($i=0;$i<count($_SESSION['bill_items']);$i++){
    echo '<tr>';
    echo '<td>' . $_SESSION['bill_items'][$i][0] . '</td>';
    echo '<td>' . $_SESSION['bill_items'][$i][1] . '</td>';
    echo '</tr>';
}
echo '<tr>';
echo '<th>Total</th>';
echo '<th>' . $_SESSION['total'] . '</th>';
echo '</tr>';
echo '</table>';

?>
</body>
</html>
