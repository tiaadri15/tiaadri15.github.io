<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Register</title>
    <link rel="stylesheet" href="style.css">
</head>
<body>
    
    <!-- LOGIN -->
    <div class="login-container">
        <div class="box form-box">
        <header id="sign-up">Sign Up</header>
        <form method="post" action="process_reg.php">
            <div class="field-input">
                <label for="username">Username</label>
                <input type="text" name="username" id="username" required>
            </div>
            <div class="field-iput">
                <label for="email">Email</label>
                <input type="email" name="email" id="email" required>
            </div>
            <div class="field-iput">
                <label for="age">Age</label>
                <input type="number" name="number" id="number" required>
            </div>
            <div class="field-input">
                <label for="password">Password</label>
                <input type="password" name="password" id="password" required>
            </div>
            <div class="field">
                <input type="submit" id="btn2" name="submit" value="Login">
            </div>
            <div class="links">
                Don't Have Account? <a href="register.php"> Sign Up Now</a>
            </div>
        </form>
        </div>
    </div>

    <script src="script.js"></script>
</body>
</html>
