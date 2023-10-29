<?php
    require '../include/koneksi.php';
     
    if (isset($_POST['submitregis'])) {
        $username = $_POST['username'];
        $email = $_POST['email'];
        $password = $_POST['password'];
     
        $result = mysqli_query($conn, "SELECT * FROM user WHERE email='$email'");
            if (!$result->num_rows > 0) {
                $sql = "INSERT INTO user VALUES ('', '$username', '$email', '$password')";
                $result = mysqli_query($conn, $sql);
                if ($result) {
                    echo "<script>alert('Selamat, registrasi berhasil!')</script>";
                    header("Location: login_user.php");
                    $username = "";
                    $email = "";
                    $_POST['password'] = "";
                } else {
                    echo "<script>alert('Woops! Terjadi kesalahan.')</script>";
                }
            } else {
                echo "<script>alert('Woops! Email Sudah Terdaftar.')</script>";
            }
        }
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Register</title>
    <link rel="stylesheet" href="../styles/login-regis.css">
    
    <script src="../js/javascript.js"></script>
</head>
<body>
    
    <!-- REGISTER -->
    <div class="signup-container">
        <div class="box form-box">
        <header id="sign-up">Sign Up</header>
        <form method="post" action="">
            <div class="field-input">
                <label for="username">Username</label>
                <input type="text" name="username" id="username" required>
            </div>
            <div class="field-iput">
                <label for="email">Email</label>
                <input type="email" name="email" id="email" required>
            </div>
            <div class="field-input">
                <label for="password">Password</label>
                <input type="password" name="password" id="password" required>
            </div>
            <div class="field">
                <input type="submit" id="btn2" name="submitregis" value="Sign Up">
            </div>
            <div class="links">
                <a href="login_user.php"> Back to Login </a>
            </div>
            
        </form>
        </div>
    </div>
</body>
</html>
