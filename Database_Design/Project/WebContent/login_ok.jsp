<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>

<%@ page contentType="text/html; charset=UTF-8"%>
<% 
	String masterID = (String) session.getAttribute("MasterLoginID");
	boolean isLogin = false;
	
	if(masterID != null){
		isLogin = true;
	}
	%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
	<link rel="stylesheet" href="./make.css">
</head>
<body>
<%
	if(isLogin){
%>
"<%= masterID %>"회원님! 로그인 한 상태입니다.
<input type="button" value="로그아웃" onclick="location.href='logout.jsp'"/>
<%
	}else{
%>
로그인하지 않은 상태
<% 
	}
%>
</body>
</html>