<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
	<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
	<link rel="stylesheet" href="./make.css">
	<title>회원가입</title>
</head>
<body>
	사용할 아이디와 비밀번호를 입력해주세요.<br/><br/>
	
	<form action="joinData.jsp" method="post" name="joinform">

	아이디 : <input type="text" name="id" maxlength="15"/> <br/><br/>
	비밀번호 : <input type="password" name="password" maxlength="15"/><br/><br/>
	
	<input type="submit" value="완료"/>
	
</form>
</body>
</html>