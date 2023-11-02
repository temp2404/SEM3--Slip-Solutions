<?php
session_start();

if (!isset($_SESSION['details']['marks'])) {
    $_SESSION['details']['marks'] = array();
}

if (isset($_POST['physics'])) {
    $_SESSION['details']['marks']['Physics'] = $_POST['physics'];
}
if (isset($_POST['biology'])) {
    $_SESSION['details']['marks']['Biology'] = $_POST['biology'];
}
if (isset($_POST['chemistry'])) {
    $_SESSION['details']['marks']['Chemistry'] = $_POST['chemistry'];
}
if (isset($_POST['maths'])) {
    $_SESSION['details']['marks']['Maths'] = $_POST['maths'];
}
if (isset($_POST['marathi'])) {
    $_SESSION['details']['marks']['Marathi'] = $_POST['marathi'];
}
if (isset($_POST['english'])) {
    $_SESSION['details']['marks']['English'] = $_POST['english'];
}

$marks = $_SESSION['details']['marks'];
$subjects = array_keys($marks);

?>

<!DOCTYPE html>
<html>
<head>
    <title>Marksheet</title>
</head>
<body>
    <h2>Mark Sheet</h2>
    <table border="1">
        <tr>
            <th colspan=2>Name of the Student: <?php echo $_SESSION['details']['sname'];?></th>
        </tr>
        <tr>
            <th>Class: <?php echo $_SESSION['details']['class'];?></th>
            <th>Address: <?php echo $_SESSION['details']['address'];?></th>
        </tr>
        <tr>
            <th>Subject</th>
            <th>Marks</th>
        </tr>
        <?php
        $total=0;
        foreach($subjects as $sub){
            echo "<tr>";
            echo "<td>$sub</td>";
            echo "<td>$marks[$sub]</td>";
            echo "</tr>";
            $total += $marks[$sub];
        }
        ?>
        <tr>
            <th>Total Marks</th>
            <th><?php echo $total;?></th>
        </tr>
        <tr>
            <th>Percentage</th>
            <th><?php echo number_format($total/6,2)."%";?></th>
        </tr>

    </table>
</body>
</html>
