<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Mark Entry</title>
</head>
<body>
    <h3>Mark Entry Form</h3>

    <form action="" method="post">

        Roll No:
        <select name="rollno" required>
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

        Science: <input type="number" name="science" required><br><br>
        Maths: <input type="number" name="maths" required><br><br>
        English: <input type="number" name="english" required><br><br>

        <input type="submit" name="save" value="save">
        <input type="reset" value="reset">

        <?php
        if(isset($_POST['save'])){

            $rollno   = $_POST['rollno'];
            $science  = $_POST['science'];
            $maths    = $_POST['maths'];
            $english  = $_POST['english'];

            $total    = $science + $maths + $english;

            $query = "INSERT INTO mark (roll_no, science, maths, english, totalmark) 
                      VALUES ('$rollno', '$science', '$maths', '$english', '$total')";

            $inserted = mysqli_query($conn, $query);

            if($inserted){
                echo "<script>alert('Inserted successfully');</script>";
            } else {
                echo "<script>alert('Error inserting data');</script>";
            }
        }
        ?>

    </form>
</body>
</html>
