<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Posttest 5</title>
    <link rel="stylesheet" href="../styles/style.css">
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
            <li><div class="dropdown">
                    <button class="dropbtn"><i class="fa-solid fa-bars"></i> Menu</button>
                    <div class="dropdown-content">
                        <a href="login_user.php"> Login</a><br>
                        <a href="profil.php"> Admin Profile</a>
                    </div>
                </div>
            </li>
            <li><a class="active" href="#"><i class="fa fa-fw fa-home"></i> Home</a></li>
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

    <!-- HERO SECTION PART -->
    <section class = 'hero' >
        <div class="hero-title">
            <div class="content">
                <h1>Welcome To K-Stream</h1>
                <p>Choose the drama you want to watch </p>
            </div>
        </div>
        <div class="inside-hero">
            <div class="title">
                <span>NOW STREAMING</span>
                <div class="line1"></div>
                <h1>Descendants of The Sun</h1>
                <p>Drama, Romance, Action, Melodrama | 2016 | 16 Episodes</p>
                <div class="btn1">
                    <a href=""><i class="fas fa-play"></i>Watch Now</a>
                    <a href=""><i class="fas fa-heart"></i>Watch Later</a>
                </div>
            </div>
            <div class="poster">
                <img src="../asset/img/dots.jpg" alt="Descendants Of The Sun">
            </div>
        </div>
    </section>
    <!-- END HERO SECTION PART -->

    <!-- CONTENT WEBSITE -->
    <section class="container">
        <table width="1263px">
            <div class="tabel1">
                <tr>
                    <td>
                        <div class="cafe_minamdang">
                            <img src="../asset/img/cm.jpeg" alt="Cafe Minamdang">
                            <h3>Cafe Minamdang</h3>
                            <h6>Romance, Comedy, Mystery | 2022 | 18 Episodes</h6><br>
                        </div>
                    </td>
                    <td>
                        <div class="cloy">
                            <img src="../asset/img/CLOY.jpeg" alt="Crush Landing on You">
                            <h3>Crush Landing on You</h3>
                            <h6>Romance, Comedy, Action  | 2020 | 16 Episodes</h6><br>
                        </div>
                    </td>
                    <td>
                        <div class="dr_cha">
                            <img src="../asset/img/dr.cha.jpg" alt="dr. Cha">
                            <h3>dr. Cha</h3>
                            <h6>Family, Medical, Comedy | 2023 | 16 Episodes</h6><br>
                        </div>
                    </td>
                </tr>
            </div>
            <div class="tabel2">
                <tr>
                    <td>
                        <div class="gbm">
                            <img src="../asset/img/gbm.jpg" alt="Good Bad Mother">
                            <h3>God Bad Mother</h3>
                            <h6>Family, Comedy, Slice of Life | 2023 | 14 Episodes</h6><br>
                        </div>
                    </td>
                    <td>
                        <div class="tfto">
                            <img src="../asset/img/tfto.jpeg" alt="Twenty-Five Twenty-One">
                            <h3>Twenty-Five Twenty-One</h3>
                            <h6>Romance, Coming-of-Age | 2022 | 16 Episodes</h6><br>
                        </div>
                    </td>
                    <td>
                        <div class="hp">
                            <img src="../asset/img/hp.jpg" alt="Hospital Playlist">
                            <h3>Hospital Playlist</h3>
                            <h6>Romance, Medical, Comedy | 2022 | 2 Seasons | 24 Episodes</h6><br>
                        </div>
                    </td>
                </tr>
            </div>
            <div class="tabel3">
                <tr>
                    <td>
                        <div class="ic">
                            <img src="../asset/img/ic.jpeg" alt="Itaewon Class">
                            <h3>Itaewon Class</h3>
                            <h6>Drama, Korean Drama | 2020 | 16 Episodes</h6><br>
                        </div>
                    </td>
                    <td>
                        <div class="moving">
                            <img src="../asset/img/moving.jpeg" alt="Moving">
                            <h3>Moving</h3>
                            <h6>Sci-fi, Action, Family | 2023 | 20 Episodes</h6><br>
                        </div>
                    </td>
                    <td>
                        <div class="obm">
                            <img src="../asset/img/obm.jpg" alt="Our Beloved Summer">
                            <h3>Our Beloved Summer</h3>
                            <h6>Romance, Comedy | 2021 | 16 Episodes</h6><br>
                        </div>
                    </td>
                </tr>
            </div>
            <div class="tabel4">
                <tr>
                    <td>
                        <div class="start_up">
                            <img src="../asset/img/start up.jpeg" alt="Start Up">
                            <h3>Start Up</h3>
                            <h6>Romance, Drama | 2020 | 16 Episodes</h6><br>
                        </div>
                    </td>
                    <td>
                        <div class="tuc">
                            <img src="../asset/img/tuc.jpeg" alt="The Uncanny Counter">
                            <h3>The Uncanny Counter</h3>
                            <h6>Fantasy, Thriller, Action | 2020 | 2 Seasons | 28 Episodes</h6><br>
                        </div>
                    </td>
                    <td>
                        <div class="ttd">
                            <img src="../asset/img/ttd.jpeg" alt="Throught The Darkness">
                            <h3>Throught The Darkness</h3>
                            <h6>Crime, Thriller, Mystery | 2022 | 12 Episodes</h6><br>
                        </div>
                    </td>
                </tr>
            </div>
        </table>
    </section>

    <!-- FOOTER -->
    <div class = "footer">
        <div class="copyright">
            <p>copyright <i class="fa-regular fa-copyright"></i> 2023 by Adriati Manuk Allo</p>
        </div>
    </div>
    <!-- END FOOTER -->
</body>

</html>