<?php
    require "../include/koneksi.php";
    $id_drama = $_GET['id_drama'];
    $get = mysqli_query($conn, "SELECT * FROM drama_korea WHERE id_drama = $id_drama");
    $drama_korea = [];

    while ($row = mysqli_fetch_assoc($get)) {
        $drama_korea[] = $row;
    }
    $drama_korea = $drama_korea[0];

    if (isset($_POST['ubah'])) {
        $judul_drama = $_POST['judul_drama'];
        $genre = $_POST['genre'];
        $tahun_rilis = $_POST['tahun_rilis'];
        $jumlah_episode = $_POST['jumlah_episode'];

        $result = mysqli_query($conn, "UPDATE drama_korea SET judul_drama='$judul_drama', genre='$genre', tahun_rilis='$tahun_rilis', jumlah_episode='$jumlah_episode' WHERE id_drama = $id_drama");

        if ($result) {
            echo "
            <script>
                alert('Data berhasil diubah!');
                document.location.href = 'dashboard.php';
            </script>";
        } else {
            echo "
            <script>
                alert('Data gagal diubah!');
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
    <title>Edit Data</title>
    <link rel="stylesheet" href="../styles/crud.css">
</head>
<body>
    <section class="edit-data">
        <div class="edit-form-container">
            <h1>Edit Data</h1><hr><br>
            <form action="" method="post">
                <label for="judul_drama">Judul Drama</label>
                <input type="text" name="judul_drama" value="<?php echo $drama_korea['judul_drama'] ?>" class="textfield">
                <label for="genre">Genre</label>
                <input type="text" name="genre" value="<?php echo $drama_korea['genre'] ?>" class="textfield">
                <label for="tahun_rilis">Tahun Rilis</label>
                <input type="text" name="tahun_rilis" value="<?php echo $drama_korea['tahun_rilis'] ?>" class="textfield">
                <label for="jumlah_episode">Jumlah Episode</label>
                <input type="text" name="jumlah_episode" value="<?php echo $drama_korea['jumlah_episode'] ?>" class="textfield">
                <input type="submit" name="ubah" value="Edit Data" class="edit-btn">
            </form>
        </div>
    </section>
</body>
</html>