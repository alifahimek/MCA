<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <form action="stude.php" method="get">
      name:<input type="text" id="name" name="name" /> 
      <br><br>
      
      
      rollno:<input
        type="text"
        id="rollno"
        name="rollno"
      />
      <br>
      <br>
      Gender:
      male<input type="radio" name="gender" value="male"/>
      female<input type="radio" name="gender" value="female"/>
      <br>
      <br>
      mark1:
      <input type="number" name="mark1"/><br><br>
      mark2:
      <input type="number" name="mark2"/><br><br>
       <input type="submit" value="submit" />
        <input type="submit" value="reset" />
</form>
</body>
</html>