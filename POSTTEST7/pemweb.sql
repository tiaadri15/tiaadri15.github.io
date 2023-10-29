-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Oct 29, 2023 at 09:35 AM
-- Server version: 10.4.28-MariaDB
-- PHP Version: 8.2.4

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `pemweb`
--

-- --------------------------------------------------------

--
-- Table structure for table `drama_korea`
--

CREATE TABLE `drama_korea` (
  `id_drama` int(10) NOT NULL,
  `gambar` varchar(255) NOT NULL,
  `judul_drama` varchar(100) NOT NULL,
  `genre` varchar(100) NOT NULL,
  `tahun_rilis` int(4) NOT NULL,
  `jumlah_episode` varchar(255) NOT NULL,
  `sinopsis` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `drama_korea`
--

INSERT INTO `drama_korea` (`id_drama`, `gambar`, `judul_drama`, `genre`, `tahun_rilis`, `jumlah_episode`, `sinopsis`) VALUES
(1, '2023-10-29_15-16-47_Move to Heaven.jpg', 'Move to Heaven', 'Drama', 2021, '10 episode', 'Move to Heaven bercerita tentang kisah kehidupan seorang remaja, Geu-ru (Tang Joon Sang) yang menggeluti profesi unik dan cenderung langka. Geu Ru (Tang Joon Sang) merupakan putra dari pemilik jasa trauma cleaner bernama Move to Heaven. Ditinggal sendiria'),
(2, '2023-10-29_15-19-22_Taxi Driver Season 1.jpg', 'Taxi Driver Season 1', 'Drama, Crime, Mystery', 2021, '16 episode', 'Menceritakan tentang Kim Do Gi (Lee Ji Hoon), seorang lulusan akademi Angkatan Laut Korea Selatan. Hidupnya berubah drastis setelah ibunya meninggal secara tragis dibunuh oleh pembunuh berantai. Kim Do Gi kemudian menjadi seorang sopir taksi mewah di peru'),
(3, '2023-10-25_09-06-59_Police University.jpg', 'Police University', 'Romance, Youth, Drama', 2021, '16 episode', ''),
(4, '2023-10-25_09-07-10_King The Land.jpg', 'King The Land', 'Romantic, Comedy', 2023, '16 episode', '');

-- --------------------------------------------------------

--
-- Table structure for table `user`
--

CREATE TABLE `user` (
  `id_pengguna` int(11) NOT NULL,
  `username` varchar(50) NOT NULL,
  `email` varchar(50) NOT NULL,
  `password` varchar(8) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `user`
--

INSERT INTO `user` (`id_pengguna`, `username`, `email`, `password`) VALUES
(1, 'admin', 'admin@gmail.com', 'admin123'),
(2, 'aaa', 'adri@gmail.com', 'aaaa'),
(3, 'adri', 'adriatimank75@gmail.com', 'adri123'),
(4, 'nia', 'nia@gmail.com', 'nia123');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `drama_korea`
--
ALTER TABLE `drama_korea`
  ADD PRIMARY KEY (`id_drama`);

--
-- Indexes for table `user`
--
ALTER TABLE `user`
  ADD PRIMARY KEY (`id_pengguna`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `drama_korea`
--
ALTER TABLE `drama_korea`
  MODIFY `id_drama` int(10) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=5;

--
-- AUTO_INCREMENT for table `user`
--
ALTER TABLE `user`
  MODIFY `id_pengguna` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=5;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
