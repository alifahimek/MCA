 <table border="1">

 <tr>
        <th>roll no</th>
        <th>name</th>
       <th>gender</th>
       <th>mark 1</th>
       <th>mark 2</th>
       <th>total</th>
 </tr>

<?php
        $name=$_GET['name'];
        $rollno=$_GET['rollno'];
        $gender=$_GET['gender'];
        $mark1=$_GET['mark1'];
        $mark2=$_GET['mark2'];

        $totalmark=$mark1+$mark2;
        
        $con=mysqli_connect('localhost','root','','student');


        $sq="SELECT rollno FROM stud where rollno =$rollno";
        $result=mysqli_query($con,$sq);

         if (mysqli_num_rows($result)>0){

                echo "<script>alert('roll no already exist');document.location='student.php';</script>";
        }
       
       else{
        $qu="INSERT INTO  stud values($rollno,'$name','$gender','$mark1','$mark2','$totalmark')";

        if(mysqli_query($con,$qu)){
               echo "<script>alert('inserted');</script>";
       }
       }



       $qi="SELECT * FROM stud";
       $re=mysqli_query($con,$qi);

       if(mysqli_num_rows($re)>0){
              while($row = mysqli_fetch_assoc($re)){
                     echo "<tr>";
                     echo "<td>".$row['rollno']."</td>";
                     echo "<td>".$row['name']."</td>";
                     echo "<td>".$row['gender']."</td>";
                     echo "<td>".$row['mark1']."</td>";
                     echo "<td>".$row['mark2']."</td>";
                     echo "<td>".$row['totalmark']."</td>";
                     echo "</tr>";
              }
       }else{
              echo"<tr>norecords found</tr>";
       }
       ?>

       </table>