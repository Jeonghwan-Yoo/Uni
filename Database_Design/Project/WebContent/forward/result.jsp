<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<%@ page import="Project.haeggul" %> 
<%@ page import="org.jdom2.Document" %> 
<%@ page import="org.jdom2.*" %> 
<%@ page import="org.jdom2.input.*" %>
<%@ page import="java.util.*" %>
<%@ page import="java.sql.*"%>


<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>여행정보</title>
</head>
<%	
	haeggul jdom = new haeggul();	
	ArrayList list = new ArrayList();
	list = jdom.getAddress();
	
 	Class.forName("com.mysql.jdbc.Driver");
	Connection conn=DriverManager.getConnection("jdbc:mysql://localhost:3306/trip?verifyServerCertificate=false&useSSL=true","root","");
	PreparedStatement pstmt=conn.prepareStatement("select * from haeggul");
	ResultSet rs=pstmt.executeQuery();
	
	while(rs.next()){
		String name=rs.getString("name");
		String continent=rs.getString("continent");
		String basic=rs.getString("basic");
		String img=rs.getString("img");
		String contact=rs.getString("contact");
		String img2=rs.getString("img2");
%>
<h3>기본 정보</h3><br/>
국가이름 : <%=name %><br/>
대륙 : <%=continent %><br/><br/>
<%=basic %><br/>
<a href='<%=img %>'>국기</a><br/>
<%=contact %><br/>
<a href='<%=img2 %>'>여행경보</a><br/>
<%}
	rs.close();
	pstmt.close();
	conn.close();
%>
<body>
</body>
</html>




