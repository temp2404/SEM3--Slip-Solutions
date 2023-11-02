<?php
$name = $_GET['name'];
$course = $_GET['course'];
$mobile = $_GET['mobile'];

if(preg_match('/^[a-zA-Z ]*$/',$name)){
    if(preg_match('/^[0-9]{10}$/',$mobile)){
        echo "<h1>Registration Successful!<br></h1> ";
        // echo "Your Registration No: " . rand(1000,9999) . "<br>";
        echo "Your Registration No: " . uniqid() . "<br>";
        echo "Name : $name<br>";
        echo "Course : $course<br>";
        echo "Mobile No : $mobile<br>";
        echo "<h3>Feedback: </h3>";
        switch($course){
            case 'BBA(CA)':
            case 'MCA':
                echo "Do Coding";
                break;
            case 'BBA':
            case 'MBA':
                echo "Do Business";
                break;
            case 'BCom':
                echo "Get a life";
                break;
            default: echo "Invalid Course";
                break;
        }
    }
    else{
        echo "Invalid Mobile No";
    }
}
else{
    echo "Name Can only contain alphabets";
}


?>