<?php
	$dbname = 'capstone_project';
	$servername = "localhost";
	$username = "root";
	$password = "";

	// Create connection
	$conn = @mysqli_connect($servername, $username, $password,$dbname);

	// Check connection
	if (!$conn) {
	  die("Connection failed: " . mysqli_connect_error());
	}
	echo "Connected successfully";

	$temp = $_GET["temperature"]; 
	$humi = $_GET["humidity"]; 
	$carb = $_GET["Mq_data"]; 
	$pm25 = $_GET["pm25"]; 
	$pm10 = $_GET["pm10"]; 

	$query = "INSERT INTO classroom_air_quality (Temperature, Humidity,Carbondioxide,Pm25,Pm10) VALUES ('$temp', '$humi', '$carb', '$pm25','$pm10')"; 

	$result = mysqli_query($conn,$query); 
	if($result) {
		echo "data sending succesful"; 
	} else {
		echo mysqli_error($conn);
	}
?>