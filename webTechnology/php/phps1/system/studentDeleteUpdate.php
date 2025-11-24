<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <table border="1">
        <tr>
            <th>roll no</th>
            <th>name</th>
            <th>address</th>
            <th>phone</th>
        </tr>

        <?php
        $conn = mysqli_connect("localhost", "root", "", "student");
        if (!$conn) {
            die("Connection failed: " . mysqli_connect_error());
        }
        $Query="SELECT * FROM STUDENTS";
        $res=mysqli_query($conn,$Query);

        if(mysqli_num_rows($res)>0){
         while($row = mysqli_fetch_assoc($res)){
            echo "<tr> <td> {$row['roll_no']}</td>
            <td> {$row['name']}</td>
            <td> {$row['phone_number']}</td>
            <td> {$row['address']}</td>
              <td>
                            <a href='markupdate.php?roll={$row['roll_no']}'><button>Update</button></a>
                            <a href='studentDelete.php?roll={$row['roll_no']}'><button>Delete</button></a>
                        </td>
            </tr>";
            
         }
        }
        else{
            echo"<tr><td>no student</tr></td>
            ";
        }
        ?>
        
</table>

</body>
</html>