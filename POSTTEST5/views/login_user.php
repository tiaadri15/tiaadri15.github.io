<?php
    require "../include/koneksi.php";
    session_start();

    if(isset($_SESSION['username'])){
        header("Location: index.php");
        exit();
    }

    if(isset($_POST['submitLogin'])){
        $email = mysqli_real_escape_string($conn, $_POST['email']);
        $username = mysqli_real_escape_string($conn, $_POST['username']);
        $password = $_POST['password'];

        $result = mysqli_query($conn, "SELECT * FROM user WHERE email='$email' AND password='$password'");

        if($result->num_rows > 0){
            $row = mysqli_fetch_assoc($result);
            $_SESSION['username'] = $row['username'];
            if($row['username'] == "admin"){
                header("Location: dashboard.php");
            }else{
                header("Location: index.php");
            }
        }else{
            echo "<script>alert('Email atau Password Anda Salah')</script>";
        }
    }
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Login</title>
    <link rel="stylesheet" href="../styles/style.css">
    <script src="../js/javascript.js"></script>
</head>
<body>
    
    <!-- LOGIN -->
    <div class="login-container">
        <div class="box form-box">
        <header id="login">LOGIN</header>
        <form action="" method="post">
            <div class="field-input">
                <label for="username">Username</label>
                <input type="text" name="username" id="username" required>
            </div>
            <div class="field-input">
                <label for="email">Email</label>
                <input type="email" name="email" id="email" required>
            </div>
            <div class="field-input">
                <label for="password">Password</label>
                <input type="password" name="password" id="password" required>
            </div>
            <div class="field">
                <input type="submit" id="btn2" name="submitLogin" value="Login">
            </div>
            <div class="links">
                Don't Have Account? <a href="register.php"> Sign Up Now</a>
            </div>
        </form>
        </div>
    </div>
</body>
</html>
