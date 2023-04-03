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
-- 테이블 구조 `orders`
--

CREATE TABLE `orders` (
  `OrderID` int(6) NOT NULL,
  `CustomerID` int(2) NOT NULL,
  `EmployeeID` int(2) NOT NULL,
  `OrderDate` varchar(15) NOT NULL,
  `ShipperID` int(2) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- 테이블의 덤프 데이터 `orders`
--

INSERT INTO `orders` (`OrderID`, `CustomerID`, `EmployeeID`, `OrderDate`, `ShipperID`) VALUES
(10278, 5, 8, '1996-08-12', 2),
(10280, 5, 2, '1996-08-14	', 1),
(10308, 2, 7, '1996-09-18	', 3),
(10355, 4, 6, '1996-11-15	', 1),
(10365, 3, 3, '1996-11-27	', 2),
(10383, 4, 8, '1996-12-16	', 3),
(10384, 5, 3, '1996-12-16	', 3);

--
-- 덤프된 테이블의 인덱스
--

--
-- 테이블의 인덱스 `orders`
--
ALTER TABLE `orders`
  ADD PRIMARY KEY (`OrderID`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
