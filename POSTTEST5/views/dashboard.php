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
</head>
<body>
    <div class="dashboard">
        </nav>
        <main class="dash-container">
            <section class="dash-main">
                <h1>Dashboard Page</h1>
                <hr><br>
                <div class="leading-btn">
                    <a href="add.php"><button class="add-btn">Tambah</button></a>
                    <button class="history-btn" onclick="alert('TBA!')">Histori</button>
                </div><br>
                <table>
                    <thead>
                        <tr>
                            <th><h4>ID</h4></th>
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