<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
     ADMIN LOGIN PAGE

     <form action="" method = "post">
     <br>
      <br>
    username:<input type="text" id="username" name="username" default/> 
      <br><br>
      
      
      password:<input
        type="password"
        id="password"
        name="password"

        default
      />
      <br>
      <br>
       <input type="submit" name="login" value="login" />
        <input type="reset" value="reset" />
        </form>
        <?php
        $conn = mysqli_connect("localhost", "root", "", "student");
        if (!$conn) {
            die("Connection failed: " . mysqli_connect_error());
        }
        if(isset($_POST['login'])){
            $username=$_POST['username'];
            $pass=$_POST['password'];
        
        $adminQuery="SELECT * FROM `admin` where username='$username' and password='$pass'";
        $res=mysqli_query($conn,$adminQuery);

        if(mysqli_num_rows($res)>0){
            header("location:adminhome.php");
            exit();
        }
    }
?>
        
</body>
</html>