<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
    
<%@ page contentType="text/html; charset=UTF-8"%>
<%
	session.invalidate();
%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
	<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
	<link rel="stylesheet" href="./make.css">
	<title>로그아웃</title>
</head>
<body>
	로그아웃되었습니다.<br/><br/>
	<input type="button" value="HOME" onclick="location.href='loginMain.jsp'"/>
</body>
</html>