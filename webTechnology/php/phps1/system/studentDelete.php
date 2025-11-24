<?php
 $conn = mysqli_connect("localhost", "root", "", "student");
if (!isset($_GET['roll']) || empty($_GET['roll'])) {
    die("Error: Roll Number not provided.");
}
$roll = $_GET['roll'];

$query = "DELETE FROM Students WHERE roll_no = '$roll'";
$result = mysqli_query($conn, $query);

if ($result) {
    echo "<script>alert('Student deleted successfully'); window.location.href='studentDeleteUpdate.php';</script>";
} 
?>