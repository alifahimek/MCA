<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <table border="1">
        <?php
        $name=$_GET['name'];
        $rollno=$_GET['rollno'];
        
        $mark1=(int)($_GET['mark1']);
        $mark2=(int)($_GET['mark2']);
        $mark3=(int)($_GET['mark3']);
        
        $total=$mark1+$mark2+$mark3;

        ?>


<tr><th>name</th>
<td><?= $name ?></td>
</tr>
<tr>
    <th>rollno</th>
<td><?= $rollno ?></td>
</tr>
<tr>
    <th>mark1</th>
<td><?= $mark1 ?></td>
</tr>
<tr>
    <th>mark2</th>
<td><?= $mark2 ?></td>
</tr>
<tr>
    <th>mark3</th>
<td><?= $mark3 ?></td>
</tr>
<tr>
    <th>total mark</th>
<td><?= $total ?></td>
</tr>


    </table>
     
    
</body>
</html>