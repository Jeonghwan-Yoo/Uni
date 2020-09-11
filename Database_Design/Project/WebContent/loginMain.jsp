<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
	<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
	<title>로그인</title>
	<link rel="stylesheet" href="./make.css">
</head>
<body>

	<form action = "loginCheck.jsp" method = "post" name="loginMainform">
		아이디 : <input type="text" name="id" maxlength="15"> <br><br>
		비밀번호 : <input type="password" name="password" maxlength="15"> <br><br>
		<input type="submit" value="로그인">
		<input type="button" value="회원가입" onclick="location.href='join.jsp'"/>
	</form>

</body>
</html>