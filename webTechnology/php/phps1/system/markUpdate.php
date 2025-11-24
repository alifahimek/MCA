<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
     <h3>Mark Update Form</h3>

    <form action="" method="post">

        Roll No:
        <select name="rollno">
            <option value="">Select</option>

            <?php
            $conn = mysqli_connect("localhost", "root", "", "student");

            $s_query = "SELECT roll_no FROM students";
            $res = mysqli_query($conn, $s_query);

            if(mysqli_num_rows($res) > 0) {
                while($row = mysqli_fetch_assoc($res)) {
                    echo "<option value='".$row['roll_no']."'>".$row['roll_no']."</option>";
                }
            }
            ?>
        </select>

        <input type="submit" value="search" name="search">

        <br><br>
         <?php
        if(isset($_POST['search'])) {
            $rollno = $_POST['rollno'];

            $s_query = "SELECT name FROM students WHERE roll_no='$rollno'";
            $res = mysqli_query($conn, $s_query);

            if(mysqli_num_rows($res) > 0){
                $n = mysqli_fetch_assoc($res);

                echo "Name: <input type='text' name='name' value='".$n['name']."' readonly><br><br>";
                echo "<input type='hidden' name='rollno' value='$rollno'>";
            }
        }
        ?>
         Science: <input type="text" name="science"><br><br>
        Maths: <input type="text" name="maths"><br><br>
        English: <input type="text" name="english"><br><br>

        <input type="submit" name="save" value="save">
        <input type="reset" value="reset">

        <?php
        if(isset($_POST['save'])){

            $rollno   = $_POST['rollno'];
            $science  = $_POST['science'];
            $maths    = $_POST['maths'];
            $english  = $_POST['english'];
            $total    = $science + $maths + $english;

            $UpdateQuery = "UPDATE mark SET science='$science', maths='$maths', english='$english', totalmark='$total' WHERE roll_no='$rollno'";
            mysqli_query($conn, $UpdateQuery);
        }
        ?>
    </form>
</body>
</html>