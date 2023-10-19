<?php
    require "../include/koneksi.php";
    $id_drama = $_GET['id_drama'];
    $result = mysqli_query($conn, "DELETE FROM drama_korea WHERE id_drama = $id_drama");
    $drama_korea = [];

    if ($result) {
        echo "
        <script>
            alert('Data berhasil dihapus!');
            document.location.href = 'dashboard.php';
        </script>";
    } else {
        echo "
        <script>
            alert('Data gagal dihapus!');
            document.location.href = 'dashboard.php';
        </script>";
    }
?>