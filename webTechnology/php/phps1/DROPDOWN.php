<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    
    <?php

     echo"<form method='post'>";
     $con=mysqli_connect('localhost','root','','student');

     $query="SELECT rollno from stud";

     $result=(mysqli_query($con,$query));

     if(mysqli_num_rows($result)>0){
        echo " roll no";
        echo "<select name='rollno>";
        while($row=mysqli_fetch_assoc($result)){
            echo "<option value='$row[rollno]'>$row[rollno]</option>";
        }
        echo"</select>";

     }
    
     
    
 
     echo" <input type='submit' name='show' value='search' >";
     echo"</form>";
      
    if (isset($_POST['show'])) {

    $roll_no = $_POST['rollno'];
    $selequery = "SELECT * FROM stud WHERE rollno='$roll_no'";
    $res = mysqli_query($con, $selequery);

    if ($res && mysqli_num_rows($res) > 0) {
        $n = mysqli_fetch_assoc($res);

        echo "<h3>Student Details</h3>";
        echo "Name: <input type='text' value='{$n['name']}' disabled><br>";
        echo "Gender: <input type='text' value='{$n['gender']}' disabled><br>";
        echo "Mark 1: <input type='text' value='{$n['mark1']}' disabled><br>";
        echo "Mark 2: <input type='text' value='{$n['mark2']}' disabled><br>";
        echo "Total: <input type='text' value='{$n['totalmark']}' disabled><br>";
    } else {
        echo "<p>No record found for roll no $roll_no</p>";
    }
}
?>




     }

     
     
     
     ?>

  
 

</body>
</html>