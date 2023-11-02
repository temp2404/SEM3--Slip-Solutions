<?php
$email="";
if($_SERVER["REQUEST_METHOD"]=="GET"){
    $email = $_GET["email"];
}
echo "Given Email: $email<br>";
$str=explode("@",$email);

// if(substr_count($email,"@")>1 || substr_count($str[0],".")>1|| (substr_count($str[1],".")<1 && substr_count($str[1],".")>2) || !preg_match('/^[a-zA-Z ]*$/',$str[0][0])){
//     echo "Invalid Email";
// }

if(substr_count($email,"@")>1)
    echo "<br>Email cannot have @ symbol more than once";
else if(substr_count($str[0],".")>1)
    echo "<br>String before @ symbol cannot have <b>'.'</b> symbol more than once";
else if((substr_count($str[1],".")<1 || substr_count($str[1],".")>2))
    echo "<br>String after @ can only have 1 <b>'.'</b> symbol or maximum 2 <b>'.'</b> symbol";
else if(!preg_match('/^[a-zA-Z ]*$/',$str[0][0]))
    echo "<br>Email must start with only alphabets";
else{
    echo "Valid Email Id";
}
?>
<body>
    <br>
    <a href="14_F1.php">Go Back</a>
</body>