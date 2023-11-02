<?php
session_start();
$_SESSION['total'] = 0;
$_SESSION['bill_items']=array();
if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    if (isset($_POST['item1'])) {
        $_SESSION['total'] += (float)$_POST['item1'];
        $item1 = array("Samsung M34",20000);
        array_push($_SESSION['bill_items'],$item1);
    }
    if (isset($_POST['item2'])) {
        $_SESSION['total'] += (float)$_POST['item2'];
        $item2 = array("Redmi K50i",23000);
        array_push($_SESSION['bill_items'],$item2);
    }
    if (isset($_POST['item3'])) {
        $_SESSION['total'] += (float)$_POST['item3'];
        $item3 = array("Iphone 15 Pro Max",169000);
        array_push($_SESSION['bill_items'],$item3);
    }
}
?>

<!DOCTYPE html>
<html>
<head>
    <title>S22 File 2</title>
</head>
<body>
    <h2>Select Product to Purchase</h2>
    <form action="22_F3.php" method="POST">
        <?php echo "Page Total: ₹" . $_SESSION['total']; ?>
        <br>
        Asus Laptop : Price ₹60,000
            <input type="checkbox" name="item4" value="60000">
        <br>
        Samsung Galaxy S9 Ultra: Price ₹1,10,000
            <input type="checkbox" name="item5" value="110000">
        <br>
        <input type="submit" value="Next">
    </form>
</body>
</html>
