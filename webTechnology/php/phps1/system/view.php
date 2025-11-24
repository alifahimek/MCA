 <!DOCTYPE html>
 <html lang="en">
 <head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
 </head>
 <body>
    <form action="" method="post">
          Roll Number : <select name="roll_no">
              <option value="" disabled selected>Select Roll Number</option>
              <?php
    $con=mysqli_connect("localhost", "root", "", "student");
    $s_query = "SELECT roll_no from Students";
    $result = mysqli_query($con,$s_query);
    if(mysqli_num_rows($result)> 0)
        {   
            while($row = mysqli_fetch_assoc($result))
                {
                    echo "<option value='$row[roll_no]'>$row[roll_no]</option>";
                    
                }
            }
            
            
            ?>
         </select>
         <input type='submit' value='SEARCH' name="search"><br>
         <?php
        if(isset($_POST['search']))
            {
                $rollno = $_POST['roll_no'];
                $n_query = "SELECT students.roll_no, students.name, mark.science, mark.maths, mark.english, mark.totalmark
                       FROM students
                       JOIN mark ON students.roll_no = mark.roll_no
                       WHERE students.roll_no = '$rollno'";
            $res = mysqli_query($con,$n_query);
            
            if(mysqli_num_rows($res)>0)
                {
                    $n = mysqli_fetch_assoc($res);
                    echo "<a href='view_top_student.php'>View Top Student</a>";
                    echo "<table border='1'>";
                    echo "<tr><th>Roll Number</th><td>{$n['roll_no']}</td></tr>";
                    echo "<tr><th>Name</th><td>{$n['name']}</td></tr>";
                    echo "<tr><th>Science</th><td>{$n['science']}</td></tr>";
                    echo "<tr><th>Maths</th><td>{$n['maths']}</td></tr>";
                    echo "<tr><th>English</th><td>{$n['english']}</td></tr>";
                    echo "<tr><th>Total</th><td>{$n['totalmark']}</td></tr>";
                    
                    echo "</table>";
                    
                }
            }
            
            ?>
</form>
 </body>
 </html><body>
    
      