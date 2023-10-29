<?php
require "../include/koneksi.php";
if (isset($_POST['tambah'])) {
    $gambar = $_FILES['gambar']['name'];
    $judul_drama = $_POST['judul_drama'];
    $genre = $_POST['genre'];
    $tahun_rilis = $_POST['tahun_rilis'];
    $jumlah_episode = $_POST['jumlah_episode'];
    $sinopsis = $_POST['sinopsis'];
    date_default_timezone_set('Asia/Makassar');
    $tanggal = date("Y-m-d_H-i-s_");
    $x = explode('.', $gambar);
    $ekstensi = strtolower(end($x));
    $gmbr = "$tanggal$judul_drama.$ekstensi";
    $tmp = $_FILES['gambar']['tmp_name'];

    if (move_uploaded_file($tmp, "../img/".$gmbr)) {
        $result = mysqli_query($conn, "INSERT INTO drama_korea VALUES ('', '$gmbr','$judul_drama', '$genre', '$tahun_rilis', '$jumlah_episode'), '$sinopsis'");

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
    } else {
        echo "
            <script>
                alert('Failed Upload Picture!');
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
            <form action="" method="post" enctype="multipart/form-data">
                <label for="judul_drama">Judul Drama</label>
                <input type="text" name="judul_drama" class="textfield" placeholder="Masukkan judul drama">
                <label for="genre">Genre</label>
                <input type="text" name="genre" class="textfield" placeholder="Masukkan genre">
                <label for="tahun_rilis">Tahun Rilis</label>
                <input type="text" name="tahun_rilis" class="textfield" placeholder="Masukkan tahun rilis">
                <label for="jumlah_episode">Jumlah Episode</label>
                <input type="text" name="jumlah_episode" class="textfield" placeholder="Masukkan jumlah episode">
                <label for="sinopsis">Sinopsis</label>
                <input type="text" name="sinopsis" class="textfield" placeholder="Masukkan sinopsis drama">
                <label for="gambar">Gambar</label>
                <input type="file" name="gambar" readonly value="<?php echo $drama_korea['gambar'] ?>" class="textfield">
                <input type="submit" name="tambah" value="Tambah Data" class="add-btn">
            </form>
        </div>
    </section>
</body>
</html>