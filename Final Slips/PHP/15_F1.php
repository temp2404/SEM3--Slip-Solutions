<!DOCTYPE html>
<html>

<head>
    <title>Slip no 15</title>
</head>

<body>
<form action="15_F2.php" method="GET">
    Choose Items from the above List: 
    <ol>
        <li>Apple : Price - 45
            <input type="checkbox" name="item1" value="Apple">
        </li> 

        <li>Kiwi : Price - 85
            <input type="checkbox" name="item2" value="Kiwi">
        </li> 

        <li>Chicken : Price - 125
            <input type="checkbox" name="item3" value="Chicken">
        </li> 

        <li>Water Bottle : Price - 20
            <input type="checkbox" name="item4" value="Water Bottle">
        </li> 

        <li>Cold Drinks : Price - 60
            <input type="checkbox" name="item5" value="Cold Drinks">
        </li>
    </ol>
    <input type="reset" value="Reset">
    <input type="submit" value="Get Bill">

</form>
</body>
 
</html>