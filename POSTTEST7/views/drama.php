<?php
require "../include/koneksi.php";

// Fungsi untuk mengambil data drama Korea dari database
function getDramaKorea($conn) {
    $result = mysqli_query($conn, "SELECT * FROM drama_korea");
    $drama_korea = [];
    while ($row = mysqli_fetch_assoc($result)) {
        $drama_korea[] = $row;
    }
    return $drama_korea;
}

// Ambil data drama Korea dari database
$drama_korea = getDramaKorea($conn);
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Drama Korea</title>
    <link rel="stylesheet" href="../styles/drama.css"> 
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">
    <script src="https://kit.fontawesome.com/2f99c0ee3f.js" crossorigin="anonymous"></script>
    <script src="https://code.jquery.com/jquery-3.6.0.min.js"></script>
    <script src="../js/drama.js"></script>
    <script src="../js/javascript.js"></script>

</head>
<body>
    <header>
        <!-- POP UP BOX -->
        <div class="alert-container" id="alertContainer">
            <div class="alert" id="alertMessage"></div>
            <button class="alert-button" id="closeAlert">OK</button>
        </div>

        <!-- POP UP BOX -->
        <div class="popup" id="customPopup">
            <div class="popup-content">
                <h2>Message</h2>
                <p id="popupMessage">Drama baru ditambahkan.</p>
                <button id="closePopup">Tutup</button>
            </div>
        </div>

        <!-- NAVBAR -->
        <nav>
            <ul>
                <li><a class="active" href="index.php"><i class="fa fa-fw fa-home"></i> Home</a></li>
                <li><a href="#" id="themeToggle"><i class="fa-solid fa-circle-half-stroke"></i> Theme</a></li>
            </ul>
        </nav>

        <!-- LOGO -->
        <div class = "logo">
            <img src="../asset/img/logo.png" alt="">
            <h3>K-Stream</h3>
        </div>
    </header>

    <main>
        <!-- Daftar Drama Korea pada Tampilan User -->
        <section class="drama-list">
            <h2>DRAMA KOREA</h2>
            <div class="drama-items">
                <?php foreach ($drama_korea as $drama) : ?>
                    <div class="drama-item">
                        <img src="../img/<?php echo $drama['gambar']; ?>" alt="<?php echo $drama['judul_drama']; ?>">
                        <h3><?php echo $drama['judul_drama']; ?></h3>
                        <p>Genre: <?php echo $drama['genre']; ?></p>
                        <p>Tahun Rilis: <?php echo $drama['tahun_rilis']; ?></p>
                        <p>Jumlah Episode: <?php echo $drama['jumlah_episode']; ?></p>
                        <a href="detail.php?id=<?php echo $drama['id_drama']; ?>" class="details-button">Lihat Detail</a>
                    </div>
                <?php endforeach; ?>
            </div>
        </section>
    </main>
</body>
</html>
