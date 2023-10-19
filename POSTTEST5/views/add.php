<?php
    require "../include/koneksi.php";
    if (isset($_POST['tambah'])) {
        $judul_drama = $_POST['judul_drama'];
        $genre = $_POST['genre'];
        $tahun_rilis = $_POST['tahun_rilis'];
        $jumlah_episode = $_POST['jumlah_episode'];

        $result = mysqli_query($conn, "INSERT INTO drama_korea VALUES ('','$judul_drama', '$genre', '$tahun_rilis', '$jumlah_episode')");

        if ($result) {
            echo "
            <script>
                alert('Data berhasil ditambahkan!');
                document.location.href = 'dashboard.php';
            </script>";
        } else {
            echo "
            <script>
                alert('Data gagal ditambahkan!');
                document.location.href = 'dashboard.php';
            </script>";
        }
    }
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Tambah Data</title>
    <link rel="stylesheet" href="../styles/crud.css">
</head>
<body>
    <section class="add-data">
        <div class="add-form-container">
            <h1>Tambah Data</h1><hr><br>
            <form action="" method="post">
                <label for="judul_drama">Judul Drama</label>
                <input type="text" name="judul_drama" class="textfield">
                <label for="genre">genre</label>
                <input type="text" name="genre" class="textfield">
                <label for="tahun_rilis">Tahun Rilis</label>
                <input type="text" name="tahun_rilis" class="textfield">
                <label for="jumlah_episode">Jumlah Episode</label>
                <input type="text" name="jumlah_episode" class="textfield">
                <input type="submit" name="tambah" value="Tambah Data" class="add-btn">
            </form>
        </div>
    </section>
</body>
</html>