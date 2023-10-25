<?php
    require "../include/koneksi.php";

    $result = mysqli_query($conn, "SELECT * FROM drama_korea");
    $drama_korea = [];
    while ($row = mysqli_fetch_assoc($result)) {
        $drama_korea[] = $row;
    }
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Dashboard Page</title>
    <link rel="stylesheet" href="../styles/dashboard.css">
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">
    <script src="https://kit.fontawesome.com/2f99c0ee3f.js" crossorigin="anonymous"></script>
    <script src="../js/javascript.js"></script>
</head>
<body>
    <!-- HEADER -->
    <header id="header">
        <!-- POP UP BOX -->
        <div class="alert-container" id="alertContainer">
            <div class="alert" id="alertMessage"></div>
            <button class="alert-button" id="closeAlert">OK</button>
        </div>
        <!-- NAVBAR -->
        <ul>
            <li><a class="active" href="index.php"><i class="fa fa-fw fa-home"></i> Home</a></li>
            <li><a href="#"><i class="fa-solid fa-clapperboard"></i> Drama</a></li>
            <li id="notificationItem"><a href="#"><i class="fa-solid fa-bell"></i> Notification</a></li>
            <li><a href="#" id="themeToggle"><i class="fa-solid fa-circle-half-stroke"></i> Theme</a></li>
        </ul>

        <!-- NAVBAR -->
        <div class = "logo">
            <img src="../asset/img/logo.png" alt="">
            <h3>K-Stream</h3>
        </div>
        
        <!-- END POP UP BOX -->
    </header>
    <!-- END HEADER -->

    <!-- DASHBOARD -->
    <div class="dashboard">
        </nav>
        <main class="dash-container">
            <section class="dash-main">
                <h1>Dashboard Page</h1>
                <hr><br>
                <div class="leading-btn">
                    <p><?php echo date ('l, d F Y');?></p>
                    <p><?php date_default_timezone_set('Asia/Makassar');
                        echo date('h:i a')?></p>
                    <a href="add.php"><button class="add-btn">Tambah</button></a>
                    <button class="history-btn" onclick="alert('TBA!')">Histori</button>
                </div><br>
                <table>
                    <thead>
                        <tr>
                            <th><h4>ID</h4></th>
                            <th><h4>Gambar</h4></th>
                            <th><h4>Judul Drama</h4></th>
                            <th><h4>Genre</h4></th>
                            <th><h4>Tahun Rilis</h4></th>
                            <th><h4>Jumlah Episode</h4></th>
                            <th><h4>Aksi</h4></th>
                        </tr>
                    </thead>
                    <tbody>
                        <?php $i = 1; foreach ($drama_korea as $drama) :?>
                        <tr>
                            <td><h4><?php echo $drama['id_drama']; ?></h4></td>
                            <td><h4><img src="../img/<?php echo $drama['gambar']; ?>" alt=""></h4></td>
                            <td><h4><?php echo $drama['judul_drama']; ?></h4></td>
                            <td><h4><?php echo $drama['genre']; ?></h4></td>
                            <td><h4><?php echo $drama['tahun_rilis']; ?></h4></td>
                            <td><h4><?php echo $drama['jumlah_episode']; ?></h4></td>
                            <td class="action">
                                <a href="edit.php?id_drama=<?php echo $drama['id_drama']?>"><button class="edit-btn"><svg xmlns="http://www.w3.org/2000/svg" height="24" viewBox="0 -960 960 960" width="24" fill="white"><path d="M200-200h56l345-345-56-56-345 345v56Zm572-403L602-771l56-56q23-23 56.5-23t56.5 23l56 56q23 23 24 55.5T829-660l-57 57Zm-58 59L290-120H120v-170l424-424 170 170Zm-141-29-28-28 56 56-28-28Z"/></svg></button></a>
                                <a href="delete.php?id_drama=<?php echo $drama['id_drama']?>"><button class="delete-btn" onclick="return confirm('Yakin ingin menghapus <?php echo $drama['judul_drama']?>?')"><svg xmlns="http://www.w3.org/2000/svg" height="24" viewBox="0 -960 960 960" width="24" fill="white"><path d="M280-120q-33 0-56.5-23.5T200-200v-520h-40v-80h200v-40h240v40h200v80h-40v520q0 33-23.5 56.5T680-120H280Zm400-600H280v520h400v-520ZM360-280h80v-360h-80v360Zm160 0h80v-360h-80v360ZM280-720v520-520Z"/></svg></button></a>
                            </td>
                        </tr>
                        <?php $i++; endforeach; ?>
                    </tbody>
                </table>
            </section>
        </main>
        </nav>
        <footer class="footer">
            <a href="index.php"><button class="footer-btn">Back to Landing Page</button></a>
        </footer>
    </div>
</body>
</html>