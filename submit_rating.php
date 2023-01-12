<?php

//submit_rating.php

$connect = new PDO("mysql:host=localhost;dbname=Enter_database_name", "root", "");

if(isset($_POST["rating_data"]))
{
	$data = array(
		':user_name'		=>	$_POST["user_name"],
		// ':user_rating'		=>	$_POST["rating_data"],
		':user_review'		=>	$_POST["user_review"],
		':datetime'			=>	time()
	);

	$query = "
	INSERT INTO review_table 
	(user_name, user_review, datetime) 
	VALUES (:user_name, :user_review, :datetime)
	";

    // make query for execution
	$statement = $connect->prepare($query);

    // method execute and insert into sql table
	$statement->execute($data);

	echo "Your Review & Rating Successfully Submitted";

}

// if action variable  is set
if(isset($_POST["action"]))
{
	// $total_review = 0;
	// $total_user_rating = 0;
	$review_content = array();

	$query = "
	SELECT * FROM review_table 
	ORDER BY review_id DESC
	";

    // for execute and get query execution result
	$result = $connect->query($query, PDO::FETCH_ASSOC);

    // fetch from result
	foreach($result as $row)
	{

		$review_content[] = array(
			'user_name'		=>	$row["user_name"],
			'user_review'	=>	$row["user_review"],
			'datetime'		=>	date('l jS, F Y h:i:s A', $row["datetime"])
		);

		// $total_review++;

		// $total_user_rating = $total_user_rating + $row["user_rating"];

	}

	// $average_rating = $total_user_rating / $total_review;

	$output = array(
		// 'average_rating'	=>	number_format($average_rating, 1),
		// 'total_review'		=>	$total_review,

		'review_data'		=>	$review_content
	);

    // send data to ajax request 
	echo json_encode($output);

}

?>