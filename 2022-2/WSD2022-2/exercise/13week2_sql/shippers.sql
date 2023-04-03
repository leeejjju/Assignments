-- phpMyAdmin SQL Dump
-- version 5.1.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- 생성 시간: 21-11-15 01:57
-- 서버 버전: 10.4.20-MariaDB
-- PHP 버전: 8.0.8

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- 데이터베이스: `testrdb`
--

-- --------------------------------------------------------

--
-- 테이블 구조 `shippers`
--

CREATE TABLE `shippers` (
  `ShipperID` int(2) NOT NULL,
  `ShipperName` varchar(20) NOT NULL,
  `Phone` varchar(20) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- 테이블의 덤프 데이터 `shippers`
--

INSERT INTO `shippers` (`ShipperID`, `ShipperName`, `Phone`) VALUES
(1, 'Speedy Express	', '(503) 555-9831'),
(2, 'United Package	', '(503) 555-3199'),
(3, 'Federal Shipping	', '(503) 555-9931');

--
-- 덤프된 테이블의 인덱스
--

--
-- 테이블의 인덱스 `shippers`
--
ALTER TABLE `shippers`
  ADD PRIMARY KEY (`ShipperID`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
