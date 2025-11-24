<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>

    <style>
        .container{
            display: flex;
            flex-direction: row;
            height: 100vh;
            width: 100vw;
        }
        .menubar{
            width: 20%;
            border-right: 2px solid black;
        }
        .mainframe{
            width: 80%;
        }
        iframe{
            width: 100%;
            height: 100%;
        }
    </style>
</head>
<body>
    <div class="container">
        <div class="menubar">

         
    <iframe src="adminMenu.php" frameborder="0"></iframe>
        </div>
        


     <div class="mainframe">
        <iframe src="studentReg.php" name="mainframe"  frameborder="0"></iframe>
    </div>
    </div>
   

   
</body>
</html>