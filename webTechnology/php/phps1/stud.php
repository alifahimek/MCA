
         <table border="1">
        <?php
        $name=$_GET['name'];
        $rollno=$_GET['rollno'];
        $gender=$_GET['gender'];
        $mark1=$_GET['mark1'];
        $mark2=$_GET['mark2'];

        $totalmark=$mark1+$mark2;
        

        $con=mysqli_connect('localhost','root','','student');
        if($con){
                echo "success";
        }
        else{
                echo "invalid";
        }
        
       


       $sq="SELECT * FROM stud where rollno =$rollno";

       $result=mysqli_query($con,$sq);

       if (mysqli_num_rows($result)>0){

                echo "<script>alert('roll no already exist');document.location='student.html';</script>";
        }
       
       else{
        $qu="INSERT INTO  stud values($rollno,'$name','$gender','$mark1','$mark2','$totalmark')";

        if(mysqli_query($con,$qu)){
               echo "<script>alert('inserted');document.location='student.html';</script>";
       }else{
        echo "error:".mysql_error($con);
       }
       }

       $qi="SELECT * FROM stud";
       $re=mysqli_query($con,$qi);

       if(mysqli_num_rows($re)){

        while($row=mysqli_fetch_assoc($re)){
               echo"<tr>";
        }
       }

       
        



        ?>


<!-- <tr><td>name</td>
<td><?= $name ?></td></tr>
<tr><td>rollno</td>
<td><?= $rollno ?></td></tr>
<tr><td>gender</td>
<td><?= htmlspecialchars($gender) ?></td></tr>
<tr><td>mark1</td>
<td><?= $mark1 ?></td></tr>
<tr><td>mark2</td>
<td><?= $mark2 ?></td></tr>

</table> -->
