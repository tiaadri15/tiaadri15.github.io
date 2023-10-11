<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Data Tersimpan</title>
    <style>
        @import url('https://fonts.googleapis.com/css2?family=Poppins&display=swap');
        *{
            margin: 0;
            padding: 0;
            box-sizing: border-box;
        }
        body {
            font-family: 'Poppins', sans-serif;
            /* display: flex; */
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
            /* display: block; */
            font-weight: bold;
            margin-bottom: 5px;
        }
    </style>
</head>
<body>
    <div class="container">
        <h1>Data Tersimpan</h1>
        <p><span class="label">Email:</span> <?= $_POST['email']; ?></p>
        <p><span class="label">Username:</span> <?= $_POST['username']; ?></p>
        <p><span class="label">Password:</span> <?= $_POST['password'] ?></p>
    </div>
</body>
</html>
