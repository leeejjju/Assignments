<?php
$uname = $_POST['uname'];
$uid = $_POST['uid'];
$pass = $_POST['pass'];
$email = $_POST['email'];
$domain = $_POST['domain'];
$gender = $_POST['gender'];
$birth = $_POST['birth'];
$pnum = $_POST['pnum'];
$address = $_POST['address'];
$yakOK = $_POST['yakOK'];
$infoOK = $_POST['infoOK'];



?>

<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <title>form_ok-leeejjju</title>
</head>

<body>
    <h3>입력하신 데이터는 다음과 같습니다.</h3>
    <div>이름: <?= $uname?> </div>
    <div>아이디: <?= $uid?> </div>
    <div>비밀번호: <?= $pass?> </div>
    <div>이메일: <?= $email?>@<?=$domain?> </div>
    <div>성별: <?= $gender?> </div>
    <div>생년월일: <?= $birth?> </div>
    <div>휴대전화: <?= $pnum?> </div>
    <div>주소: <?= $address?> </div>
    <div>약관동의여부: <?= $yakOK?> </div>
    <div>정보제공동의여부: <?= $infoOK?> </div>

</body>



