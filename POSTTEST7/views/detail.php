<?php
require "../include/koneksi.php";

if (isset($_GET['id'])) {
    $id_drama = $_GET['id'];

    function getDetailDrama($conn, $id) {
        $query = "SELECT * FROM drama_korea WHERE id_drama = $id";
        $result = mysqli_query($conn, $query);
        return mysqli_fetch_assoc($result);
    }

    $detail_drama = getDetailDrama($conn, $id_drama);
} else {
    header('Location: index.php');
    exit();
}
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Detail Drama</title>
    <link rel="stylesheet" href="../styles/detail.css">
</head>
<body>

    <div class="container">
        <h1><?php echo $detail_drama['judul_drama']; ?></h1>
        <img src="../img/<?php echo $detail_drama['gambar']; ?>" alt="<?php echo $detail_drama['judul_drama']; ?>" width="200">
        <p>Genre: <?php echo $detail_drama['genre']; ?></p>
        <p>Tahun Rilis: <?php echo $detail_drama['tahun_rilis']; ?></p>
        <p>Jumlah Episode: <?php echo $detail_drama['jumlah_episode']; ?></p>
        <p>Sinopsis: <?php echo $detail_drama['sinopsis']; ?></p>

        <a href="drama.php">Kembali ke Daftar Drama</a>
    </div>

</body>
</html>
