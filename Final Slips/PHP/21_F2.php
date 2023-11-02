<?php
session_start();

if (!isset($_SESSION['details'])) {
    $_SESSION['details'] = array();
}

if (isset($_POST['sname'])) {
    $_SESSION['details']['sname'] = $_POST['sname'];
}
if (isset($_POST['class'])) {
    $_SESSION['details']['class'] = $_POST['class'];
}
if (isset($_POST['address'])) {
    $_SESSION['details']['address'] = $_POST['address'];
}

print_r($_SESSION['details']);
?>

<!DOCTYPE html>
<html>

<head>
    <title>Slip no 21 File 2</title>
</head>

<body>
<form action="21_F3.php" method="POST">
<input type="number" name="physics" placeholder="Enter Physics Marks" required><br>
<input type="number" name="biology" placeholder="Enter Biology Marks" required><br>
<input type="number" name="Chemistry " placeholder="Enter Chesmistry Marks" required><br>
<input type="number" name="maths" placeholder="Enter Maths Marks" required><br>
<input type="number" name="marathi" placeholder="Enter Marathi Marks" required><br>
<input type="number" name="english" placeholder="Enter English Marks" required><br>
<input type="submit" value="Get Result">
</form>
</body>

</html>