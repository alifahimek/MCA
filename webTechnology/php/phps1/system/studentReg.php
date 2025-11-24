<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    student Registration form
    <br><br>
    <form  method="post">
    rollno:<input type="text" id="rollno" name="rollno" /> 
      <br><br>
      
      
      name:<input
        type="text"
        id="name"
        name="name"
      />
      <br>
      <br>
      address<input type="text" id="address" name="address"/>
        <br><br>
        phoneno:<input type="text" id="phone" name="phone"/>
        <br><br>
        username:<input type="text" id="username" name="username"/>
        <br><br>
        password:<input type="password" id="password" name="password"/>
        <br><br>
        retype password:<input type="password" id="repassword" name="repassword"/>
        <br><br>
       <input type="submit" value="Register" name="Register" onclick="return validatePassword()"/>
       <p id="pass_valid" style="color:red; display:none;"></p>
       <p id="re-pass_valid" style="color:red; display:none;"></p>
       </form>
       <script>
         function validatePassword(){
            var pass=document.getElementById("password").value;
            var rePass=document.getElementById("repassword").value;
            var pass_p=document.getElementById("pass_valid");
            var rePass_p=document.getElementById("re-pass_valid");
            if(pass.length<8){
                pass_p.style.display="block";
                pass_p.innerText="Password must be at least 8 characters long.";
                return false;
            }
            if(pass!==rePass){
                rePass_p.style.display="block";
                rePass_p.innerText="Passwords do not match.";
                return false;
            }

            return true;
        }
        </script>
       <?php
        if (isset($_POST['Register'])){
          $rollno = $_POST['rollno'];
            $name = $_POST['name'];
            $address = $_POST['address'];
            $phone = $_POST['phone'];
            $username = $_POST['username'];
            $pass = $_POST['password'];
            
            $con = mysqli_connect("localhost","root","","student");

            $checkRoll="SELECT roll_no from students where roll_no ='$rollno'";

            $check=mysqli_query($con,$checkRoll);

            if(mysqli_num_rows($check)>0){
                echo "<script>alert('Roll no already exists');</script>";

            }
            else
            {
               $insertReg="INSERT INTO students (roll_no,name,address,phone_number,username,password)values('$rollno','$name','$address','$phone','$username','$pass')";

                $inserted=mysqli_query($con,$insertReg);
                if($inserted){
                    echo "<script>alert('registered successfully');</script>";
                }
            
        }}
        ?>
       
</body>
</html>