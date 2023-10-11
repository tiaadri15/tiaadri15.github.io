<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Data Tersimpan</title>
    <style>
        body {
            background-image: linear-gradient(rgba(228, 184, 184, 0.9), rgba(228, 184, 184, 0.9)), url(asset/dots.jpg);
            background-color: rgba(206, 159, 159, 0.9);
            background-size: cover;
            background-repeat: no-repeat;
            font-family: Arial, sans-serif;
            background-color: #f2f2f2;
            margin: 0;
            padding: 0;
            display: flex;
            justify-content: center;
            align-items: center;
            height: 100vh;
        }

        .container {
            background: #fff;
            box-shadow: 0px 0px 10px rgba(0, 0, 0, 0.1);
            padding: 20px;
            border-radius: 5px;
            width: 300px;
            text-align: center;
        }

        h1 {
            font-size: 24px;
            margin-bottom: 20px;
        }

        p {
            text-align: left;
            margin: 10px 0;
        }

        .label {
            display: block;
            font-weight: bold;
            margin-bottom: 5px;
        }
    </style>
</head>
<body>
    <div class="container">
        <h1>Data Tersimpan</h1>
        <p><span class="label">Username:</span> <?= $_POST['username']; ?></p>
        <p><span class="label">Email:</span> <?= $_POST['email']; ?></p>
        <p><span class="label">Age:</span> <?= $_POST['number'] ?></p>
        <p><span class="label">Password:</span> <?= $_POST['password'] ?></p>
    </div>
</body>
</html>
