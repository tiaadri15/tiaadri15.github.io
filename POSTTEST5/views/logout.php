<?php
    session_start();
    unset($_SESSION["id_pengguna"]);
    unset($_SESSION["username"]);
    header("Location:login_user.php");
?>