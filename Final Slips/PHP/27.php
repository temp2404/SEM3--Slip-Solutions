<!DOCTYPE html>
<html>

<head>
    <title>Slip No 27</title>
</head>

<body>
<form method="GET">
    <input type="text" name="pname" id="pname" placeholder="Enter Project Name"><br><br>
    <input type="submit" value="Submit">
</form>

<?php
$servername = "localhost";
$username = "root";
$password = "";
$db_create = "CREATE DATABASE IF NOT EXISTS slip_27";

$conn = mysqli_connect($servername,$username,$password);
$new_db = mysqli_query($conn,$db_create);
mysqli_select_db($conn,"slip_27");

if($conn){
    echo "Connected to Database succussfully!<br>";
}
else{
    echo "Failed to connect to Database succussfully because of ". mysqli_connect_error() . "<br>";
}

$project_name = $_GET["pname"];

$query = "
SELECT ename, qualif, DOJ 
FROM employee,project,work 
WHERE employee.eno=work.eno
AND project.pno=work.pno
AND pname='$project_name';
";

$stmt = $conn->prepare($query);
if($stmt){
    $stmt->execute();
    $stmt->bind_result($ename,$qualif,$doj);

    while($stmt->fetch()){
        echo "Name : $ename<br>";
        echo "Qualification : $qualif<br>";
        echo "Date of Joining : $doj<br><br>";
    }
}
else{
    echo "Failed to get results because of " . $conn->error;
}


?>

</body>

</html>